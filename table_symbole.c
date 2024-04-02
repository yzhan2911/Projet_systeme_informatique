
#include "table_symbole.h"

static Symbole* symboleT;

static int Index=0;
static const int IndexMax=TABLE_SIZE;
static int depthCurrent=0;
static int IndexTemporaire=0;
void augmenDepth(){
    depthCurrent++;
}
void diminuDepth(){
    depthCurrent--;
}
void handleError(const char *message) {
    fprintf(stderr, "Erreur : %s\n", message);
}
void ini_table(){
    symboleT=malloc(sizeof(Symbole)*TABLE_SIZE);
}
Symbole creerSymbole(char* name, numberType type){
    Symbole s;
    strcpy(s.name,name);
    s.ini = false;
    s.number = type;
    s.depth = depthCurrent;
    return s;
}
void ajoutTable(char *name,numberType type){
    Symbole element=creerSymbole(name,type);

    if (Index<IndexMax){
         symboleT[Index]=element;
        Index ++;
    }
    else{
        handleError("erreur:symbole full");
    }

}
numberType findtype(char *name){
    numberType ty;
    ty=symboleT[getIndex(name)-1].number;
    return ty;
}
int getIndex(char* name){
    for(int i=0;i<Index;i++){
        if(strcmp(symboleT[i].name,name)==0){
            return i;
        }
    }
    handleError("pas trouver element ");
    printf("%s \n",name);
    return(0);
}

void supprimElement(char* name){
    for(int i=getIndex(name);i<(Index-1);i++){
        symboleT[i]=symboleT[i+1];
    }
    Index--;
}
int creation_valeur_temporaire(){
    IndexTemporaire++;
    return IndexTemporaire;
}
int reset_index_temporaire(){
    IndexTemporaire==Index;
    return IndexTemporaire;
}
void suprime_valeur_temporaire(){
    IndexTemporaire--;
    
}
void set_ini(char* name){
    symboleT[getIndex(name)].ini=true;
}
int get_last_index(){
    return Index;
}
