
#include "table_symbole.h"

static Symbole* symboleT;

static int Index=0;
static const int IndexMax=TABLE_SIZE;
static int depthCurrent=0;
static int IndexTemporaire=0;
void handleError(const char *message) {
    fprintf(stderr, "Erreur : %s\n", message);
}
void ini_table(){
    symboleT=malloc(sizeof(Symbole)*TABLE_SIZE);
}
Symbole creerSymbole(char* name, numberType type,int valeur){
    Symbole s;
    strcpy(s.name,name);
    s.ini = false;
    s.number = type;
    s.valeur= valeur;
    return s;
}
void ajoutTable(char *name,numberType type,int valeur){
    printf("%s , index: %d , valeur:%d \n",name,Index,valeur);
    Symbole element=creerSymbole(name,type,valeur);
    if (Index<IndexMax){
         symboleT[Index]=element;
        Index ++;
    }
    else{
        handleError("erreur:symbole full");
    }

}
/*numberType findtype(char *name){
    numberType ty;
    ty=symboleT[getIndex(name)-1].number;
    return ty;
}*/
int getIndex(char* name){
    for(int i=0;i<=Index;i++){
        if(strcmp(symboleT[i].name,name)==0){
            return i;
        }
    }
    handleError("pas trouver element ");
    printf("%s \n",name);
    return(0);
}


int creation_valeur_temporaire(int valeur){
    char nomtempo[50] ="valeurTempo ";
    ajoutTable(nomtempo,0,valeur);
    IndexTemporaire++;
    return Index-1;
}

void suprime_valeur_temporaire(){
    Index--;
    IndexTemporaire--;
    
}
void set_ini(char* name){
    symboleT[getIndex(name)].ini=true;
}
int get_last_index(){
    return Index;
}
void exportTableSymbole(){
    FILE* fp;
    fp = fopen("symbole", "a");
    for (int i = 0; i < Index; ++i) {
        fprintf(fp,"index: %d   sympole: %s  valeur: %d\n",i, symboleT[i].name, symboleT[i].valeur);
    }
    fprintf(fp,"Indexest %d",Index);
    fclose(fp);
}

int get_valeur(int index){
    //printf("la valeur de index %d est %d \n",index, symboleT[index].valeur);
    return symboleT[index].valeur;
}

void set_valeur(int index,int val){
    symboleT[index].valeur=val;
      printf("maj la valeur %d dans index %d\n",val,index);
}