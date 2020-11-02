#include <stdio.h>
#include <string.h>

typedef struct Etudiant{
	char nom[20], prenom[20], adresse[20], notesC[20], notesSysExp[20];
}Etudiant_t;

void etudiant(Etudiant_t etu);

int main (int argc, char* argv[]){

    Etudiant_t etuUn = {"Jean /", "Dupont /", "Sault /", "[10, 12, 14] /", "[12, 15, 0]"};
    Etudiant_t etuDeux = {"Phillipe /", "Pain /", "Villeurbanne /", "[10, 0, 0] /", "[12, 20, 20]"};
    Etudiant_t etuTrois = {"Denis /", "Faim /", "Montbrun les bains /", "[10, 0, 20] /", "[12, 1, 2]"};
    Etudiant_t etuQuatre = {"Herve /", "Plate /", "Lyon /", "[10, 2, 4] /", "[12, 4, 8]"};
    Etudiant_t etuCinq = {"Henri /", "Longe /", "Paris /", "[10, 9, 9] /", "[12, 9, 9]"};

    etudiant(etuUn);
    etudiant(etuDeux);
    etudiant(etuTrois);
    etudiant(etuQuatre);
    etudiant(etuCinq);

    return 0;
}

void etudiant(Etudiant_t etu){
    printf("%s %s %s %s %s", etu.nom, etu.prenom, etu.adresse, etu.notesC, etu.notesSysExp);
    printf("\n");
    return;
}
