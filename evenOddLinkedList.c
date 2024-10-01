#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int value;
    node* next;
};

typedef struct Liste Liste;
struct Liste {
    node* first;
};

Liste* initialisation() {
    Liste* liste_chainee = malloc(sizeof(liste_chainee));
    if(liste_chainee == NULL) {
        exit(EXIT_FAILURE);
    }
    liste_chainee->first = NULL;
    return liste_chainee;
}

void insertValue(Liste* liste,const int val) {
    node* noeud = (node*)malloc(sizeof(node));
    if(liste == NULL || noeud == NULL) {
        exit(EXIT_FAILURE);
    }
    noeud->value = val;

    if(liste->first == NULL) {
        noeud->next = liste->first;
        liste->first = noeud;
        return;
    }

    node* current = liste->first;
    while(current->next != NULL) {
        current = current->next;
    }
    noeud->next = NULL;
    current->next = noeud;
}

void printList(const Liste* liste) {
    node* current = liste->first;
    while(current != NULL) {
        printf("%d->",current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void oddEvenNode(const Liste *liste,Liste* odd,Liste* even) {
    node* current = liste->first;

    while(current->next != NULL) {
        if((current->value)%2 == 0) {
            insertValue(even,current->value);
        }
        else {
            insertValue(odd,current->value);
        }
        current = current->next;
    }
}

void deleteList(Liste* liste) {
    node* current = liste->first;
    node* suiv = NULL;

    while(current->next != NULL) {
        suiv = current->next;
        free(current);
        current = suiv;
    }
    free(liste);
    free(current);
    free(suiv);
}

int main(void) {
    printf("Creer une liste chainee de base!\n");
    Liste* chaine_base = initialisation();
    int nbre = 0;
    printf("entrez le nombre d'element de la liste :    ");
    scanf("%d",&nbre);

    for(int i = 1;i<nbre;i++) {
        //int value = 0;
        printf("entrez la valeur du noeud %d   :  ",i+1);
        //scanf("%d",&value);
        insertValue(chaine_base,i);
    }
    printf("affichage de la liste de base\n");
    printList(chaine_base);

    printf("processus de creation et d'initialisation des listes odd et even\n");
    Liste *odd = initialisation();
    Liste *even = initialisation();

    oddEvenNode(chaine_base,odd,even);
    printf("affichage de la liste even\n");
    printList(even);
    printf("affichage de la liste odd\n");
    printList(odd);

    printf("suppression de l'espace utilise\n");
    free(chaine_base);
    return 0;
}
