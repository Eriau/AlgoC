typedef struct RGB{ // Struct pour chaque couleur
    unsigned char Red, Green, Blue, Alpha;
}RGB_t;


typedef struct Couleur Couleur;
struct Couleur{ // Struct pour un élement
	RGB_t rgb;
    Couleur *suivant;
};

typedef struct ListCouleurs ListCouleurs; // Struct pour une liste de couleurs
struct ListCouleurs{
    Couleur *premier;
};

ListCouleurs *init();
void insertion (RGB_t *newCouleur, ListCouleurs *liste);
void parcours (ListCouleurs *liste);

