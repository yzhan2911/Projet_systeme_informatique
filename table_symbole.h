#ifndef TABLE_SYMBOLE_H
#define TABLE_SYMBOLE_H


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define TABLE_SIZE 128  // correspond à Taille de notre carte FPGA
#define NAME_MAX_LENGTH 20 

typedef enum numberType {INT,FLOAT,CHAR} numberType;

typedef struct{
char name[NAME_MAX_LENGTH];
numberType number;
bool ini;
int depth;
} Symbole;
void augmenDepth();
void diminuDepth();

/*initialiser le table de symbole*/
void ini_table();

/*ajouter un element dans le tableau*/
void ajoutTable(char *name,numberType type);

/*supprimer un element*/
void supprimElement(char* name);

/*retourner index d'un element*/
int getIndex(char* name);
int popValTemp();
int pushValTemp();
void handleError(const char *message);
int get_last_index();
int creation_valeur_temporaire();
int reset_index_temporaire();
void suprime_valeur_temporaire();
void set_ini(char* name);
/*numberType findtype(char *name);*/
#endif