#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition des statuts des tâches
enum statut {
    a_realiser,            // 0
    en_cours_realisation, // 1
    finalisee             // 2
};


// Structure pour les dates
typedef struct {
    int heure;
    int jour;
    int mois;
    int annee;
} dates;

// Structure pour les données des tâches
typedef struct {
    int identifiant;
    char titre[50];
    char description[100];
    dates deadline;
    enum statut st;
} donnee;

int compt = 0;  // Nombre actuel de tâches
donnee tache[300];  // Tableau pour stocker les tâches
// Prototypes de fonctions
void menu();
void ajouter_une_tache();
void ajouter_plus_taches();
void affichage();
void modification();
void supprimer();
void recherche();
void statistique();
void tri_alpha();
void tri_deadline();
void tache_info();
void exit_program(int error);
void recherche_titre();
void recherche_Id();
void modifier_deadline();
void modifier_description();
void modifier_statut();
void nb_taches_statut();
void retn();

// Fonction principale
int main() {
    menu();
    return 0;
}

// Fonction pour afficher le menu principal
void menu() {
    int choix;
    printf("________________________________________________TO DO LIST______________________________________________________\n\n");
    printf("1 - Ajouter une nouvelle tâche.\n");
    printf("2 - Ajouter plusieurs nouvelles tâches.\n");
    printf("3 - Afficher la liste de toutes les tâches.\n");
    printf("4 - Modifier une tâche.\n");
    printf("5 - Supprimer une tâche.\n");
    printf("6 - Rechercher une tâche.\n");
    printf("7 - Statistiques.\n");
    printf("8 - Quitter.\n\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: ajouter_une_tache(); break;
        case 2: ajouter_plus_taches(); break;
        case 3: affichage(); break;
        case 4: modification(); break;
        case 5: supprimer(); break;
        case 6: recherche(); break;
        case 7: statistique(); break;
        case 8: exit_program(0); break;
        default: printf("Choix invalide.\n"); retn();
    }
}
// Fonction pour saisir les informations d'une tâche
void tache_info() {
    printf("Entrez l'identifiant: ");
    scanf("%d", &tache[compt].identifiant);
    printf("Entrez le titre de la tâche: ");
    scanf(" %[^\n]", tache[compt].titre);
    printf("Entrez la description: ");
    scanf(" %[^\n]", tache[compt].description);
    printf("Statut de la tâche (1 - à réaliser, 2 - en cours de réalisation, 3 - finalisée): ");
      int n;
    scanf("%d", &n);
    tache[compt].st = n - 1;
    printf("Entrez la date de la deadline (jour/mois/année): ");
    scanf("%d/%d/%d", &tache[compt].deadline.jour, &tache[compt].deadline.mois, &tache[compt].deadline.annee);
    printf("Entrez l'heure de la deadline: ");
    scanf("%d", &tache[compt].deadline.heure);
    ++compt;
}
}
// Fonction pour ajouter une nouvelle tâche
void ajouter_une_tache() {
    printf("\nAjouter une nouvelle tâche\n");
    tache_info();
    printf("\nVotre tâche a été ajoutée avec succès.\n");
    retn();
}
// Fonction pour ajouter plusieurs nouvelles tâches
void ajouter_plus_taches() {
    int num_taches;
    printf("\nAjouter plusieurs nouvelles tâches\n");
    printf("Entrez le nombre de tâches que vous souhaitez ajouter: ");
    scanf("%d", &num_taches);

    for (int i = 0; i < num_taches; i++) {
        if (compt >= 300) {
            printf("Nombre maximal de tâches atteint.\n");
            exit_program(1);
        }
        printf("\nEntrez les informations de la tâche %d:\n", i + 1);
        tache_info();
    }

    printf("\nToutes les tâches ont été ajoutées avec succès.\n");
    retn();
}
// Fonction pour afficher les tâches
void affichage() {
    int tri_choix;
    printf("\nAfficher les tâches\n");
    printf("1 - Trier par ordre alphabétique du titre.\n");
    printf("2 - Trier par ordre de deadline.\n");
    printf("3 - Revenir au menu.\n");
    printf("4 - Quitter.\n");
    printf("Entrez votre choix: ");
    scanf("%d", &tri_choix);

    switch (tri_choix) {
        case 1: tri_alpha(); break;
        case 2: tri_deadline(); break;
        case 3: menu(); break;
        case 4: exit_program(0); break;
        default: printf("Choix invalide.\n"); retn();
    }
}

// Fonction pour supprimer une tâche
void supprimer() {
    int id;
    printf("Entrez l'identifiant de la tâche à supprimer: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < compt; i++) {
        if (tache[i].identifiant == id) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < compt - 1; i++) {
            tache[i] = tache[i + 1];
        }
        --compt;
        printf("Tâche supprimée avec succès.\n");
    } else {
        printf("Tâche non trouvée.\n");
    }
    retn();
}

























// Fonction pour retourner au menu ou quitter le programme
void retn() {
    int choix;
    printf("\n1 - Revenir au menu.\n");
    printf("2 - Quitter.\n");
    printf("Entrez votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: menu(); break;
        case 2: exit_program(0); break;
        default: printf("Choix invalide.\n"); retn();
    }
}
