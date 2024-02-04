#include "../lib/tp_note_2023.h"   

Liste liste_nouv(){  
    return NULL;
}

// pré: le bloc l de parametre est déjà plein
void split_block(Liste l){ 
    int k = l->taille / 2;
    Liste new = MALLOC(strListe);
    new->taille = k;
    new->s = l->s;
    new->p = l;
    l->s->p = new;
    l->s = new;
    new->max = l->max;
    new->min = l->tab[k+1];
    l->max = l->tab[k];
    int j = 0;
    for (int i = k+1; i < l->taille; i++) {
        new->tab[j] = l->tab[i];
        j++;
    }
    l->taille -= k;
}

// pré : l->taille < TAILLE && x > l->p->max && x < l->s->min
void insert_in_block(Liste l, int x){ 
    if (x >= l->max) {
        l->tab[l->taille] = x;
        l->taille++;
        l->max = x;
    } else {
        int i;
        for (i = 0; i < l->taille-1; i++) {
            if (x < l->tab[i] || (x >= l->tab[i] && x < l->tab[i+1])) {
                break;
            }
        }
        if (i == 0) l->min = x;
        for(int j = l->taille; j > i; j--) {
            l->tab[j] = l->tab[j-1];
        }
        l->tab[i] = x;
        l->taille++;
    }
}

Liste ajout_element(Liste l, int x){
    // cas 1: liste est vide
    if (l == NULL) {
        Liste new = MALLOC(strListe);
        new->tab[0] = x;
        new->taille = 1;
        new->min = x;
        new->max = x;
        new->s = new;
        new->p = new;
        return new;
    }

    // cas 2: si x <= l->max 
    if (x <= l->max) {
        if (l->taille == TAILLE) {
            split_block(l);
            if (x <= l->max) {
                insert_in_block(l, x);
            } else {
                insert_in_block(l->s, x);
            }
        } else {
            insert_in_block(l, x);
        }
        return l;
    }

    // cas 3: cas trivial
    Liste curser = l->s;
    while(curser != l) {
        if (x <= curser->max) {
            if (curser->taille == TAILLE) {
                split_block(curser);
                if (x <= curser->max) {
                    insert_in_block(curser, x);
                } else {
                    insert_in_block(curser->s, x);
                }
            } else {
                insert_in_block(curser, x);
            }
            break;
        }
        curser = curser->s;
    }
    return l;
}

int min_liste (Liste l){ 
    if (l != NULL)
        return l->min;
    return -1;
}

int max_liste(Liste l){ 
    if (l!= NULL) 
        return l->p->max;
    return -1;
}

Nat longueur(Liste l){ 
    if (l == NULL) return 0;
    Liste tete = l->s;
    Nat longueur = 1;
    while (tete != l) {
        longueur++;
        tete = tete->s;
    }
    return longueur;
}

int indice_in_tab(Liste l, int n){
    if (l->min == n) return 0;
    else if (l->max == n) return l->taille-1;
    int i = 1, j = l->taille-1, m;
    while(i < j) {
        m = (i + j) / 2;
        if (l->tab[m] == n) return m;
        else if (l->tab[m] > n) j = m-1;
        else if (l->tab[m] < n) i = m+1;
    }
    return -1;
}

bool recherche(Liste l, int n){ 
    if (l == NULL) return false;
    Liste curser = l->s;
    while(curser != l) {
        if (indice_in_tab(curser, n) != -1) return true;
        curser = curser->s;
    }
    if (indice_in_tab(curser, n) != -1) return true;
    return false;
}

Liste free_block(Liste l){
    Liste dummy = l;
    l = l->s;
    if (l == dummy) l = NULL;
    free(dummy);
    return l;
}

void free_liste(Liste l){
   while (l != NULL) {
    l = free_block(l);
   }
}


// ----------------------------- Fonctions csv et affichage : Déja fait ----------------------------------------


void print_liste(Liste l){
    int n=0;
    Liste curser = l->s;
    while (curser != l){

        printf("Boite n°%d, min:%d, max:%d, taille:%d\n",n, curser->min, curser->max,curser->taille);
        for(int i = 0; i<curser->taille;i++){
            printf("%d ",curser->tab[i]);
        }
        printf("\n \n");
        curser = curser->s;
        n++;
    }
    printf("Boite n°%d, min:%d, max:%d, taille:%d\n",n, curser->min, curser->max,curser->taille);
    for(int i = 0; i<curser->taille;i++){
        printf("%d ",curser->tab[i]);
    }
    printf("\n \n");
}

Liste readCSVToListe(const char *filename) {
    Liste l = liste_nouv();
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int v;
    while (fscanf(file, "%d,", &v) == 1){
        l = ajout_element(l,v);
    }

    fclose(file);

    return l;
}
