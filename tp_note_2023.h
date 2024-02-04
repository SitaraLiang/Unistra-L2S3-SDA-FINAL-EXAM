#include "base.h"   
#include <time.h>

/*Mise en place :

Une archive est disponible sur moodle avec l’architecture du code (.h .c et makefile), 
les fonctions devront être écrite dans le fichier Liste.c et testées dans le fichier main.c.
La fonction main contient initialement un appel à une fonction initialisant une liste de test à partir du fichier values.csv, 
cette fonction est utilisable à partir du moment ou la fonction ajout_element est implanté.

Rendu :

Sur moodle vous rendrez une archive contenant l’ensemble des fichiers nécessaire pour la compilation, 
la commande make doit permettre de compiler un exécutable. 
Votre projet doit impérativement COMPILER, vous pouvez commenter l’ensemble des fonctions problématiques pour la compilation.
La pertinence de vos jeux de test sera également pris en compte pour la notation.
*/

#define TAILLE 50

typedef struct strliste{ // liste doublement chaînée circulaire
    int tab[TAILLE];
    int min;
    int max;
    Nat taille;
    struct strliste *s;
    struct strliste *p;
} strListe, *Liste;

// ----------------------- Fonctions Liste à faire ----------------------- //

/**
 * @brief Générateur : Crée une nouvelle Liste vide.
 *
 * @return Liste vide
 */
Liste liste_nouv();

/**
 * @brief Split un block de la liste en deux blocks chainés
 *
 * @param l Bloc de la Liste que l'on veut split en deux
 * @return Pas de return mais modifie la liste globale
 */
void split_block(Liste l);

/**
 * @brief Insert l'élémént x dans le block de la liste ciblé
 *
 * @param l Block de la liste que l'on veut cibler
 * @param x Valeur à ajouter
 * @return Pas de return mais modifie la liste globale
 */
void insert_in_block(Liste l, int x);

/**
 * @brief Générateur : Ajoute un élément au bon endroit dans la Liste globale.
 *
 * @param l Liste globale
 * @param x Valeur à ajouter
 * @return Liste résultante après ajout
 */
Liste ajout_element(Liste l, int x);

/**
 * @brief Renvoie la valeur minimum de la liste
 *
 * @param l Liste dont on veut savoir le minimum
 * @return Element minimum
 */
int min_liste (Liste l);

/**
 * @brief Renvoie la valeur maximum de la liste
 *
 * @param l Liste dont on veut savoir le maximum
 * @return Element maximum
 */
int max_liste(Liste l);

/**
 * @brief Récupère la longueur de la Liste, c'est-à-dire le nombre d'éléments (de valeurs) qu'elle contient.
 *
 * @param l Liste
 * @return Longueur de la Liste
 */
Nat longueur(Liste l);

/**
 * @brief Fonction de recherche qui renvoie l'indice de l'élémént dans un block
 *
 * @param l Liste
 * @param n Valeur à chercher
 * @return Int indice de l'élément -1 sinon
 */
int indice_in_tab(Liste l, int n);

/**
 * @brief Fonction de recherche pour savoir si n appartient à la liste l.
 *
 * @param l Liste
 * @param n Valeur à chercher
 * @return Bool true si n est dans la liste l Sinon false
 */
bool recherche(Liste l, int n);

/**
 * @brief Fonction qui free le block en tete de liste 
 *
 * @param l Liste
 * 
 * @return la nouvelle tete de liste
 */
Liste free_block(Liste l);


/**
 * @brief Fonction qui free completement la liste l
 *
 * @param l Liste
 */
void free_liste(Liste l);


// ----------------------- Fonctions CSV et affichage, DEJA FAIT ----------------------- //

/**
 * @brief Affiche les éléménts de la liste
 *
 * @param l La liste à afficher
 */
void print_liste(Liste l);

Liste readCSVToListe(const char *filename);