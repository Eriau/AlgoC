#include <stdio.h>
#include <string.h>

typedef struct Etudiant{
	char *nom, *prenom, *adresse, *notesC, *notesSysExp;
    char *tabEtu[5];
}Etudiant_t;

void etudiant(char *tabEtu[], Etudiant_t etu);

int main (int argc, char* argv[]){

    Etudiant_t etuUn = {"Jean /", "Dupont /", "Sault /", "[10, 12, 14] /", "[12, 15, 0]"};
    Etudiant_t etuDeux = {"Phillipe /", "Pain /", "Villeurbanne /", "[10, 0, 0] /", "[12, 20, 20]"};
    Etudiant_t etuTrois = {"Denis /", "Faim /", "Montbrun les bains /", "[10, 0, 20] /", "[12, 1, 2]"};
    Etudiant_t etuQuatre = {"Herve /", "Plate /", "Lyon /", "[10, 2, 4] /", "[12, 4, 8]"};
    Etudiant_t etuCinq = {"Henri /", "Longe /", "Paris /", "[10, 9, 9] /", "[12, 9, 9]"};

    etudiant(etuUn.tabEtu, etuUn);
    etudiant(etuDeux.tabEtu, etuDeux);
    etudiant(etuTrois.tabEtu, etuTrois);
    etudiant(etuQuatre.tabEtu, etuQuatre);
    etudiant(etuCinq.tabEtu, etuCinq);

    return 0;
}

void etudiant(char *tabEtu[], Etudiant_t etu){
    tabEtu[0] = etu.nom;
    tabEtu[1] = etu.prenom;
    tabEtu[2] = etu.adresse;
    tabEtu[3] = etu.notesC;
    tabEtu[4] = etu.notesSysExp;
    for(int i = 0; i<5;i++){
        printf("%s ", tabEtu[i]);
    }
    printf("\n");
    return;
}
