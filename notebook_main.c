#include <stdio.h>
#include <string.h>

char beleska[128];
int broj;
char linija[128];

void dodajBelesku();
void prikaziBelesku();
void obrisiBelesku();
void pretraziBelesku();

int main() {
    char cmd[16];

    while(1) {
        printf("dodaj/prikazi/obrisi/pretraga/izadji\n");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "dodaj") == 0) {
            dodajBelesku();
        } else if (strcmp(cmd, "prikazi") == 0) {
            prikaziBelesku();
        } else if (strcmp(cmd, "obrisi") == 0) {
            obrisiBelesku();
        } else if (strcmp(cmd, "pretraga") == 0) {
            pretraziBelesku();
        } else if (strcmp(cmd, "izadji") == 0) {
            break;
        } else {
            printf("Nepoznata komanda!\n");
        }
    }
    return 0;
}

void dodajBelesku() {
    FILE *f = fopen("notes.txt", "a");
    if (f == NULL) return;

    printf("Unesi novu belesku: ");
    fgets(beleska, sizeof(beleska), stdin);
    beleska[strcspn(beleska, "\n")] = 0;

    fprintf(f, "%s\n", beleska);
    fclose(f);
}

void prikaziBelesku() {
    FILE *f = fopen("notes.txt", "r");
    if (f == NULL) {
        printf("Greska pri otvaranju fajla!\n");
        return;
    }

    printf("Koju belesku trazis: ");
    scanf("%d", &broj);
    getchar();

    for (int i = 0; i < broj; i++) {
        if (fgets(beleska, sizeof(beleska), f) == NULL) {
            printf("Ne postoji toliko beleski u fajlu!\n");
            fclose(f);
            return;
        }
    }

    beleska[strcspn(beleska, "\n")] = 0;
    printf("%s\n", beleska);
    fclose(f);
}

void obrisiBelesku() {
    FILE *f = fopen("notes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Koju belesku zelis da obrises: ");
    scanf("%d", &broj);
    getchar();

    int cur = 1;
    while (fgets(linija, sizeof(linija), f) != NULL) {
        if (cur != broj) fputs(linija, temp);
        cur++;
    }

    fclose(f);
    fclose(temp);

    remove("notes.txt");
    rename("temp.txt", "notes.txt");
}

void pretraziBelesku() {
    FILE *f = fopen("notes.txt", "r");
    if (f == NULL) {
        printf("Greska pri otvaranju fajla!\n");
        return;
    }

    char trazeno[128];
    int nadjeno = 0;
    int broj = 1;

    printf("Pretrazi belesku: ");
    fgets(trazeno, sizeof(trazeno), stdin);
    trazeno[strcspn(trazeno, "\n")] = 0;

    while (fgets(linija, sizeof(linija), f) != NULL) {
        if (strstr(linija, trazeno) != NULL) {
            printf("Pronadjeno u belesci broj %d: %s", broj, linija);
            nadjeno = 1;
        }
        broj++;
    }

    if (!nadjeno) printf("Nema belesaka koje sadrze: %s\n", trazeno);
    fclose(f);
}

