#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int max_reservation = 100;
char nom[100][50];
char prenom[100][50];
char telephone[100][25];
int age[100];
char statut[100][10];
char reference[100][10];
char date[100][25];
int Nombre_reservation = 0;
char reservetemp;
char res[];
int temp;

void ajouter_reservation() {
    if (Nombre_reservation < max_reservation) {
    printf("Ajouter une reservation:\n");
    printf("donner le nom de patient : ");
    scanf("%s", nom[Nombre_reservation]);
    printf(" donner le Prenom du client : ");
    scanf("%s", prenom[Nombre_reservation]);
    printf(" donner le Telephone du client : ");
    scanf("%s", telephone[Nombre_reservation]);
     printf(" donner l age du client : ");
     scanf("%d", &age[Nombre_reservation]);
    printf("Statut (valide, reporte, annule, traite) : ");
    scanf("%s", statut[Nombre_reservation]);
 printf(" saisie la Date de reservation  : ");
 scanf("%s", date[Nombre_reservation]);
 printf("donner la reference de la reservation : ");
scanf("%s", reference[Nombre_reservation]);
 printf("Client ete ajoute  : %s\n", reference[Nombre_reservation]);
        Nombre_reservation++;
    } else {
        printf("Le nombre maximum de reservatoin:\n");
    }
}

void modifier_reservation() {
    char ref[10];
    printf("donner  la reference de client : ");
    scanf("%s", ref);
    for (int i = 0; i < Nombre_reservation; i++) {
    if (strcmp(reference[i], ref) == 0) {
        printf("modifier la reservation %s :\n", ref);
        printf("nom  : %s. nouveau nom : ", nom[i]);
        scanf("%s", nom[i]);
        printf("Prenom  : %s. Nouveau prenom : ", prenom[i]);
        scanf("%s", prenom[i]);
        printf("Telephone  : %s. Nouveau telephone : ", telephone[i]);
        scanf("%s", telephone[i]);
        printf("Age  : %d. Nouvel age : ", age[i]);
        scanf("%d", &age[i]);
        printf("Statut  : %s. Nouveau statut : ", statut[i]);
        scanf("%s", statut[i]);
        printf("Date  : %s. Nouvelle date : ", date[i]);
        scanf("%s", date[i]);
        printf(" mise a jour  de reservation: \n");
            return;
        }
    }
    printf("reservation n est pas trouve.\n");
}

void supprimer_reservation() {
    char ref[10];
    printf(" reference il est supprimer : ");
    scanf("%s", ref);

    for (int i = 0; i < Nombre_reservation; i++) {
        if (strcmp(reference[i], ref) == 0) {
  for (int j = i; j < Nombre_reservation - 1; j++) {
    strcpy(nom[j], nom[j + 1]);
    strcpy(prenom[j], prenom[j + 1]);
    strcpy(telephone[j], telephone[j + 1]);
        age[j] = age[j + 1];
    strcpy(statut[j], statut[j + 1]);
     strcpy(reference[j], reference[j + 1]);
     strcpy(date[j], date[j + 1]);
            }
    Nombre_reservation--;
printf("reservation supprime :\n");
            return;
        }
    }
    printf("reservation non trouve:\n");
}
void afficher_details_reservation() {
    char ref[10];
    printf("entrez la reference de la reservation : ");
    scanf("%s", ref);
    for (int i = 0; i < Nombre_reservation; i++) {
        if (strcmp(reference[i], ref) == 0) {
            printf("details de la reservation %s :\n", ref);
            printf("Nom : %s\n", nom[i]);
            printf("Prenom : %s\n", prenom[i]);
            printf("Telephone : %s\n", telephone[i]);
            printf("age : %d\n", age[i]);
            printf("Statut : %s\n", statut[i]);
            printf("date de reservation : %s\n", date[i]);
            return;
        }
    }
    printf("reservation non trouve.\n");
}
void trier_reservations_par_nom() {
    for (int i = 0; i < Nombre_reservation ; i++) {
        for (int j = 0; j < Nombre_reservation - 1; j++) {
            if (strcmp(nom[j], nom[j + 1]) > 0) {
  reservetemp = res[j];
        res[j] = res[j+1];
        res[j+1] =temp;
            }
        }
    }
}
  void trier_reservations_par_date() {
    for (int i = 0; i < Nombre_reservation ; i++) {
        for (int j = 0; j < Nombre_reservation - 1; j++) {
            if (strcmp(date[j], date[j + 1]) > 0) {
        reservetemp =res[j];
        res[j] = res[j+1];
        res[j+1] =temp;
            }
        }
    }
}

void trier_reservations_par_statut() {
    for (int i = 0; i < Nombre_reservation ; i++) {
        for (int j = 0; j < Nombre_reservation - 1; j++) {
            if (strcmp(statut[j], date[j + 1]) > 0) {
        reservetemp =res[j];
        res[j] = res[j+1];
        res[j+1] =temp;
            }
        }
    }
}

void rechercher_reservation_par_reference() {
    char ref_recherche[10];
    printf("entrez la reference a rechercher : ");
    scanf("%s", ref_recherche);
for (int i = 0; i < Nombre_reservation; i++) {
  if (strcmp(reference[i], ref_recherche) == 0) {
    printf("reservation trouve pour la reference %s :\n", reference[i]);
    printf("nom : %s\n", nom[i]);
    printf("Prenom : %s\n", prenom[i]);
    printf("telephone : %s\n", telephone[i]);
    printf("age : %d\n", age[i]);
    printf("Statut : %s\n", statut[i]);
    printf("Date de reservation : %s\n", date[i]);
            return;
        }
    }
    printf("Aucune reservation trouve avec cette reference.\n");
}
void rechercher_reservation_par_nom() {
    char nom_recherche[50];
    printf("entrez le nom a rechercher : ");
    scanf("%s", nom_recherche);
    int trouve = 0;
    for (int i = 0; i < Nombre_reservation; i++) {
        if (strcmp(nom[i], nom_recherche) == 0) {
            printf("reservation trouve pour %s :\n", nom[i]);
            printf("Prenom : %s\n", prenom[i]);
            printf("Telephone : %s\n", telephone[i]);
            printf("Age : %d\n", age[i]);
            printf("Statut : %s\n", statut[i]);
            printf("reference : %s\n", reference[i]);
            printf("date de reservation : %s\n", date[i]);
            trouve = 1;
        }
    }

    if (trouve!=0) {
        printf("Aucune reservation trouve pour ce nom.\n");
    }
}
void rechercher_reservation_par_date() {
    char date_recherche[25];
    printf("entrez la date a rechercher : ");
    scanf("%s", date_recherche);
       int trouve = 0;
for (int i = 0; i < Nombre_reservation; i++) {
  if (strcmp(date[i], date_recherche) == 0) {
  printf("Reservation trouve pour la date %s :\n", date_recherche);
  printf("nom : %s\n", nom[i]);
  printf("Prenom : %s\n", prenom[i]);
  printf("telephone : %s\n", telephone[i]);
  printf("age : %d\n", age[i]);
  printf("Statut : %s\n", statut[i]);
  printf("reference : %s\n", reference[i]);
            trouve = 1;
        }
    }

    if (trouve!=0) {
        printf("Aucune reservation trouve pour cette date.\n");
    }
}
    void calculer_moyenne_age() {
    if (Nombre_reservation == 0) {
        printf(" reservation n est pas effectu:\n");
        return;
    }
     float moyenne_age;
    float somme_age = 0;
    for (int i = 0; i < Nombre_reservation; i++) {
        somme_age =  somme_age + age[i];
    }

     moyenne_age = somme_age / Nombre_reservation;
    printf("La moyenne d'age des patients ayant reserve est : %.2f ans\n", moyenne_age);
}
void afficher_nombre_patients_par_tranche_age() {
    int compte_0_18 = 0;
    int compte_19_35 = 0;
    int compte_36_plus = 0;

    for (int i = 0; i < Nombre_reservation; i++) {
        if (age[i] >= 0 && age[i] <= 18) {
            compte_0_18++;
        } else if (age[i] >= 19 && age[i] <= 35) {
            compte_19_35++;
        } else if (age[i] >= 36) {
            compte_36_plus++;
        }
    }

    printf("nombre de patients par tranche d'age :\n");
    printf("0-18 ans : %d\n", compte_0_18);
    printf("19-35 ans : %d\n", compte_19_35);
    printf("36 ans et plus : %d\n", compte_36_plus);
}
void afficher_statistiques_par_statut() {
    int compte_valide = 0;
    int compte_annule = 0;
    int compte_reporte = 0;
    int compte_traite = 0;

    for (int i = 0; i < Nombre_reservation; i++) {
        if (strcmp(statut[i], "valide") == 0) {
            compte_valide++;
        } else if (strcmp(statut[i], "annule") == 0) {
            compte_annule++;
        } else if (strcmp(statut[i], "reporte") == 0) {
            compte_reporte++;
        } else if (strcmp(statut[i], "traite") == 0) {
            compte_traite++;
        }
    }

    printf("Statistiques des reservations par statut :\n");
    printf("Valide : %d\n", compte_valide);
    printf("Annule : %d\n", compte_annule);
    printf("Reporte : %d\n", compte_reporte);
    printf("Traite : %d\n", compte_traite);
}



int main() {
    int choix;

    do {
        printf("Gestion des reservations de rendez-vous dentaires\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("4. Afficher les details d'une reservation\n");
        printf("5. Rechercher une reservation par reference\n");
printf("6. Rechercher une reservation par nom\n");
printf("7. Trier les reservations par nom\n");
printf("8. Trier les reservations par date\n");
printf("9. Trier les reservations par statut (valide, reporte, annule, traite)\n");
printf("10. Rechercher une reservation par date\n");
printf("11. Calculer la moyenne d'age des patients ayant reserve\n");
printf("12. Afficher le nombre de patients par tranche d'age (0-18, 19-35, 36+)\n");
 printf("13. Afficher le nombre total de reservations par statut (valide, annule, reporte, traite)\n");
        printf(" donner Votre choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter_reservation();
                break;
            case 2:
                modifier_reservation();
                break;
            case 3:
                supprimer_reservation();
                break;
            case 4:
                afficher_details_reservation();
                break;
                case 5:
        rechercher_reservation_par_reference();
                break;
                case 6:
             rechercher_reservation_par_nom();
             break;
             case 7:
    trier_reservations_par_nom();
               break;
             case 8:
    trier_reservations_par_date();
    break;
    case 9:
    trier_reservations_par_statut();
    break;
     case 10:
    rechercher_reservation_par_date();
             break;
             case 11:
    calculer_moyenne_age();
    break;
    case 12:
    afficher_nombre_patients_par_tranche_age();
    break;
    case 13:
    afficher_statistiques_par_statut();
    break;
            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
