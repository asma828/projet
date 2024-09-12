#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Projet Fin SAS: Gestion des étudiants dans une université
#define MAX_DEPARTEMENTS 3
const char* departements[] = {
    "Science Biologique",
    "Science de la Vie et de la Terre",
    "Économie"
};
typedef struct {
    int numero;
    char nom[50];
    char prenom[50];
    char date_naissance[11]; // Format: DD/MM/YYYY
    char departement[40];
    float note_generale;
} Etudiant;
  Etudiant etudiants[1000]; // Tableau pour stocker les étudiants
    int count = 0; // Compteur d'etudiants
//Fonction pour ajouter les departement
void afficher_departements() {
    printf("Liste des départements disponibles :\n");
    for (int i = 0; i <MAX_DEPARTEMENTS ; i++) {
        printf("%d. %s\n", i + 1, departements[i]);
    }
}
//Fonction pour choisir un departement
int choisir_departement() {
    int choix;
    afficher_departements();
    printf("Choisissez un département (1-%d) : ", MAX_DEPARTEMENTS);
    scanf("%d", &choix);

    if (choix < 1 || choix > 3) {
        printf("Choix invalide. Veuillez réessayer.\n");
        return choisir_departement(); // Recurssion en cas d'erreur
    }

    return choix - 1; // Retourne l'index correspondant au choix de l'utilisateur
}
//Fonction pour ajouter un etudiant
void ajouter_etudiant() {
    if (count >= 1000) {
        printf("Nombre maximal d'étudiants atteint.\n");
        return;
    }

    Etudiant nouveau;
    nouveau.numero=count + 1;
    printf("Nom : ");
    scanf("%s", nouveau.nom);
    printf("Prénom : ");
    scanf("%s", nouveau.prenom);
    printf("Date de naissance (jj/mm/aaaa) : ");
    scanf("%s", nouveau.date_naissance);

    int choix_dept = choisir_departement();
    strcpy(nouveau.departement, departements[choix_dept]); // Utilise le département sélectionné

    printf("Note générale : ");
    scanf("%f", &nouveau.note_generale);

    etudiants[count] = nouveau; // Affecte le nouvel étudiant à la position actuelle
    count++; // Incrémente le compteur d'étudiants

    printf("Étudiant ajouté avec succès !\n");
}
//Fonction pour modifier les informations des etudiants
void modifier_etudiant(int numero) {

    printf("Entrez le numreo d\'etudiant à modifier: ");
    scanf("%d", &numero);
    for (int i = 0; i < count; i++) {
        if (etudiants[i].numero ==numero ) {
            printf("Modifier les informations de l'étudiant %d\n", numero);
            printf("Nom (%s) : ", etudiants[i].nom);
            scanf("%s", etudiants[i].nom);
            printf("Prénom (%s) : ", etudiants[i].prenom);
            scanf("%s", etudiants[i].prenom);
            printf("Date de naissance (%s) : ", etudiants[i].date_naissance);
            scanf("%s", etudiants[i].date_naissance);
            printf("Département (%s) : ", etudiants[i].departement);
            scanf("%s", etudiants[i].departement);
            printf("Note générale (%.2f) : ", etudiants[i].note_generale);
            scanf("%f", &etudiants[i].note_generale);
            printf("Étudiant modifié avec succès.\n");
            return;
        }
    }
    printf("Étudiant non trouvé.\n");
}
//Fonction pour supprimer un etudiant
void supprimer_etudiant(int numero) {
    printf("Entrez le numero de l\'etudiant à supprimer: ");
    scanf("%d", &numero);
    int index = -1;
     // Recherche de l'étudiant dans le tableau
    for (int i = 0; i < count; i++) {
        if (etudiants[i].numero ==numero) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        char confirmation;
        printf("Vous êtes sur le point de supprimer l'étudiant suivant :\n");
        printf("Nom : %s, Prénom : %s, Département : %s\n", etudiants[index].nom, etudiants[index].prenom, etudiants[index].departement);
        printf("Êtes-vous sûr de vouloir continuer ? (O/N) : ");
        scanf(" %c", &confirmation);

        if (confirmation == 'O' || confirmation == 'o') {
            // Suppression de l'étudiant
        for (int i = index; i < count - 1; i++) {
            etudiants[i] = etudiants[i + 1];
        }
            count--;
            printf("Étudiant supprimé avec succès.\n");
        } else {
            printf("Suppression annulée.\n");
        }
    } else {
        // Si l'étudiant n'est pas trouvé
        printf("Étudiant non trouvé.\n");
    }
}
//Fonction pour afficher les d'etails d'un etudiant
void afficher_details_etudiants(int numero) {
    int num;
    printf("Numéro de l'étudiant à afficher: ");
    scanf("%d", &num);
    for (int i = 0; i < count; i++) {
        if (etudiants[i].numero == num) {
            printf("\nDétails de l'étudiant %d :\n", num);
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prénom : %s\n", etudiants[i].prenom);
            printf("Date de naissance : %s\n", etudiants[i].date_naissance);
            printf("Département : %s\n", etudiants[i].departement);
            printf("Note générale : %.2f\n", etudiants[i].note_generale);
            return;
        }
    }
    printf("Étudiant avec numéro %d introuvable.\n", num);

}
//aficher des ligne
void afficher_ligne_separation() {
    printf("----------------------------------------------------\n");
}
//affiche cadre
void afficher_cadre_titre(const char* titre) {
    printf("\n******************\n");
    printf("* %s *\n", titre);
    printf("******************\n");
}
// Fonction pour afficher le menu principal
void afficher_menu() {
  afficher_cadre_titre("       Menu Principal   ");
    printf("1. Ajouter un étudiant\n");
    printf("2. Modifier un étudiant\n");
    printf("3. Supprimer un étudiant\n");
    printf("4. Afficher les détails d'un étudiant\n");
    printf("5. afficher moyenne d\'universite\n");
    printf("6. Statistiques\n");
    printf("7. Rechercher un étudiant\n");
    printf("8. Trier les étudiants\n");
    printf("9. Quitter\n");
    afficher_ligne_separation(); // Ajout d'une ligne de séparation
}
// Fonction pour calculer la moyenne de chaque département
void calculer_moyenne_par_departement() {
    int somme[MAX_DEPARTEMENTS] = {0};  // Tableaux pour stocker la somme des notes par département
    int count_dept[MAX_DEPARTEMENTS] = {0};  // Tableaux pour stocker le nombre d'étudiants par département
    const char* departements[] = {"Science Biologique", "Science de la Vie et de la Terre", "Économie"};

    // Parcourir la liste des étudiants et calculer les sommes et les comptes par département
    for (int i = 0; i < count; i++) {
        if (strcmp(etudiants[i].departement, "Science Biologique") == 0) {
            somme[0] += etudiants[i].note_generale;
            count_dept[0]++;
        } else if (strcmp(etudiants[i].departement, "Science de la Vie et de la Terre") == 0) {
            somme[1] += etudiants[i].note_generale;
            count_dept[1]++;
        } else if (strcmp(etudiants[i].departement, "Économie") == 0) {
            somme[2] += etudiants[i].note_generale;
            count_dept[2]++;
        }
    }

    // Afficher les moyennes par département
    for (int j = 0; j < 3; j++) {
        if (count_dept[j] > 0) {
            printf("Département: %s, Moyenne: %.2f\n", departements[j], (float)somme[j] / count_dept[j]);
        } else {
            printf("Département: %s, Aucun étudiant\n", departements[j]);
        }
    }
}
// Fonction pour calculer la moyenne générale de l'université
float calculer_moyenne_generale() {
    float somme = 0;
    for (int i = 0; i < count; i++) {
        somme += etudiants[i].note_generale;
    }
    return (count > 0) ? (somme /count) : 0;
}
// Fonction principale pour afficher les moyennes
void afficher_moyennes() {
    calculer_moyenne_par_departement();
    
    float moyenne_universite = calculer_moyenne_generale();
    printf("Moyenne générale de l'université: %.2f\n", moyenne_universite);
}
//Fonction pour afficher total d'etudiants
void afficher_nombre_total_etudiants() {
    printf("Nombre total d'étudiants: %d\n",count);
}
//Fonction pour afficher nomber d'etudiant par departement
void afficher_nombre_etudiants_par_departement(const char* departement) {
    int n_count = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(etudiants[i].departement, departement) == 0) {
            n_count++;
        }
    }
    printf("Nombre d'étudiants dans le département %s: %d\n", departement, n_count);
}
//Fonction pour afficher etudiants superieur a un seuil
void afficher_etudiants_superieur_seuil(float seuil) {
    printf("Étudiants ayant une moyenne supérieure à %.2f:\n", seuil);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (etudiants[i].note_generale > seuil) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Note générale: %.2f\n",
                   etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun étudiant n'a une moyenne supérieure à %.2f.\n", seuil);
    }
}
//Fonction pour afficher les 3 meilleurs
void afficher_trois_meilleurs_etudiants() {
    if (count < 3) {
        printf("Il n'y a pas assez d'étudiants pour afficher les 3 meilleurs.\n");
        return;
    }

    // Créer un tableau temporaire pour stocker les étudiants
    Etudiant temp[count];
    for (int i = 0; i < count; i++) {
        temp[i] = etudiants[i];
    }

    // Trier les étudiants par note générale décroissante
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j].note_generale < temp[j + 1].note_generale) {
                Etudiant t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // Afficher les 3 meilleurs étudiants
    printf("Les 3 meilleurs étudiants:\n");
    for (int i = 0; i < 3; i++) {
        printf("Numéro: %d, Nom: %s, Prénom: %s, Note générale: %.2f\n",
               temp[i].numero, temp[i].nom, temp[i].prenom, temp[i].note_generale);
    }
}
//Fonction pour afficher le
void afficher_nombre_etudiants_reussis_par_departement() {
    int reussis[MAX_DEPARTEMENTS] = {0}; // Tableau pour stocker le nombre d'étudiants ayant réussi par département

    // Parcourir la liste des étudiants et compter ceux qui ont réussi dans chaque département
    for (int i = 0; i < count; i++) {
        if (etudiants[i].note_generale >= 10) {
            if (strcmp(etudiants[i].departement, "Science Biologique") == 0) {
                reussis[0]++;
            } else if (strcmp(etudiants[i].departement, "Science de la Vie et de la Terre") == 0) {
                reussis[1]++;
            } else if (strcmp(etudiants[i].departement, "Économie") == 0) {
                reussis[2]++;
            }
        }
    }

    // Afficher le nombre d'étudiants ayant réussi par département
    printf("Nombre d'étudiants ayant réussi dans chaque département:\n");
    printf("Science Biologique: %d étudiants\n", reussis[0]);
    printf("Science de la Vie et de la Terre: %d étudiants\n", reussis[1]);
    printf("Économie: %d étudiants\n", reussis[2]);
}
//Fonction pour recherche etudiant par son nom
void rechercher_etudiant_par_nom(char nom[50]) {
    int found = 0; 
    for (int i = 0; i < count; i++) {
        if (strcmp(etudiants[i].nom, nom) == 0) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Note générale: %.2f\n",
                   etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun étudiant trouvé avec le nom %s.\n", nom);
    }
}
// Fonction pour afficher la liste des étudiants dans un département spécifique
void afficher_etudiants_dans_departement(const char* departement) {
    int found = 0;  // Indicateur pour vérifier si des étudiants sont trouvés
    printf("Liste des étudiants dans le département %s:\n", departement);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(etudiants[i].departement, departement) == 0) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Note générale: %.2f\n",
                   etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun étudiant trouvé dans le département %s.\n", departement);
    }
}
//Afficher les etudiant
void afficher_tous_les_etudiants() {
    if (count == 0) {
        printf("Aucun étudiant n'est enregistré.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Numéro: %d, Nom: %s, Prénom: %s, Département: %s, Note générale: %.2f\n",
               etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].departement, etudiants[i].note_generale);
    }
}
// tri alphanitique
void trier_etudiants_par_nom(int ordre) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int comparison = strcmp(etudiants[i].nom, etudiants[j].nom);
            if ((ordre == 1 && comparison > 0) || (ordre == 2 && comparison < 0)) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}
// Fonction pour trier les étudiants par note générale
void trier_etudiants_par_note(int ordre) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((ordre == 1 && etudiants[i].note_generale < etudiants[j].note_generale) || 
                (ordre == 2 && etudiants[i].note_generale > etudiants[j].note_generale)) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
}
// Fonction pour trier les étudiants par statut de réussite
void trier_etudiants_par_statut_reussite() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (etudiants[i].note_generale < 10 && etudiants[j].note_generale >= 10) {
                Etudiant temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
      // Affichage des étudiants ayant une note supérieure ou égale à 10
    printf("Liste des étudiants ayant une moyenne supérieure ou égale à 10:\n");
    int found = 0; // Indicateur pour vérifier si des étudiants sont trouvés
    for (int i = 0; i < count; i++) {
        if (etudiants[i].note_generale >= 10) {
            printf("Numéro: %d, Nom: %s, Prénom: %s, Note générale: %.2f\n",
                   etudiants[i].numero, etudiants[i].nom, etudiants[i].prenom, etudiants[i].note_generale);
            found = 1; // Indiquer qu'on a trouvé au moins un étudiant
        }
    }

    if (!found) {
        printf("Aucun étudiant trouvé avec une note supérieure ou égale à 10.\n");
    }
}
 // Fonction principale
int main() {
 int choix, numero;
    char nom[50], departement[40];
    float seuil;


    while (1) {
        afficher_menu();
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:ajouter_etudiant();
                break;
            case 2: modifier_etudiant(numero);
                break;
            case 3:supprimer_etudiant(numero);
                break;
            case 4:afficher_details_etudiants(numero);
                break;
            case 5: afficher_moyennes();
                break;
            case 6:
                printf("1. Afficher nombre total d'étudiants\n");
                printf("2. Afficher nombre d'étudiants par département\n");
                printf("3. Afficher étudiants ayant une moyenne supérieure à un seuil\n");
                printf("4. Afficher les 3 meilleurs étudiants\n");
                printf("5.Afficher le nombre d'étudiants ayant réussi dans chaque département\n");
                int sous_choix;
                scanf("%d", &sous_choix);
                switch (sous_choix) {
                    case 1:
                        afficher_nombre_total_etudiants();
                        break;
                   case 2:
         printf("Sélectionnez un département :\n");
          afficher_departements();
          int dept_index;
          printf("Choisissez un département (1-%d) : ", 3);
             scanf("%d", &dept_index);
    
          afficher_nombre_etudiants_par_departement(departements[dept_index - 1]);
    break;
                    case 3:
                        printf("Seuil de moyenne: ");
                        scanf("%f", &seuil);
                        afficher_etudiants_superieur_seuil(seuil);
                        break;
                    case 4:
                        afficher_trois_meilleurs_etudiants();
                        break;
                    case 5:
                afficher_nombre_etudiants_reussis_par_departement();
                        break;
                        default:
                         printf("Sous-choix invalide.\n");
                        break;
                }
                break;
case 7:
    printf("1. Rechercher un étudiant par nom\n");
    printf("2. Afficher les étudiants dans un département spécifique\n");
    int recherche_choix;
    scanf("%d", &recherche_choix);

    switch (recherche_choix) {
        case 1:
            printf("Nom de l'étudiant à rechercher: ");
            scanf("%s", nom);
            rechercher_etudiant_par_nom(nom);
            break;
        case 2:
        printf("Liste des départements disponibles :\n");
            for (int i = 0; i < 3; i++) {
                printf("%d. %s\n", i + 1, departements[i]);
            }
            
            int choix_dept;
            printf("Choisissez un département (1-3) : ");
            scanf("%d", &choix_dept);
                   if (choix_dept >= 1 && choix_dept <= 3) {
                afficher_etudiants_dans_departement(departements[choix_dept - 1]);
            } else {
                printf("Choix de département invalide.\n");
            }
            break;
            printf("Nom du département: ");
            scanf("%s", departement);
            afficher_etudiants_dans_departement(departement);
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
    break;

case 8:
    printf("1. Trier par nom (A-Z)\n");
    printf("2. Trier par nom (Z-A)\n");
    printf("3. Trier par note (du plus élevé au plus faible)\n");
    printf("4. Trier par note (du plus faible au plus élevé)\n");
    printf("5. Trier par statut de réussite\n");
    int tri_choix;
    scanf("%d", &tri_choix);

    switch (tri_choix) {
        case 1:
            trier_etudiants_par_nom(1); // A-Z
            printf("Étudiants triés par nom (A-Z).\n");
            afficher_tous_les_etudiants();
            break;
        case 2:
            trier_etudiants_par_nom(2); // Z-A
            printf("Étudiants triés par nom (Z-A).\n");
            afficher_tous_les_etudiants();
            break;
        case 3:
            trier_etudiants_par_note(1); // Du plus élevé au plus faible
            printf("Étudiants triés par note (du plus élevé au plus faible).\n");
            afficher_tous_les_etudiants();
            break;
        case 4:
            trier_etudiants_par_note(2); // Du plus faible au plus élevé
            printf("Étudiants triés par note (du plus faible au plus élevé).\n");
            afficher_tous_les_etudiants();
            break;
        case 5:
            trier_etudiants_par_statut_reussite(); // Tri par statut de réussite
            printf("Étudiants triés par statut de réussite.\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
    break;

case 9:
                printf("Au revoir.\n");
                return 0;
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
        
}
    return 0;
}