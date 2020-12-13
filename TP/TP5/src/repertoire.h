#ifndef ALGO_CPE_REPERTOIRE_H
#define ALGO_CPE_REPERTOIRE_H

typedef struct listRepertoire{
    struct listRepertoire* next;
    struct listRepertoire* last;
    char* name;
}listRepertoire_t;

void lire_dossier(char *);

void lire_dossier_recursif(char *);


#endif //ALGO_CPE_REPERTOIRE_H