#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct etudiant{
    int id;
     char name[30];
      char prenom[30];
       float moyenne;
            char groupe[10];
};
//-----------------------------------------------------------------------
void cree_fichier(){
    FILE *F = fopen("etudiant.txt","w");

    if(F == NULL){
        printf("erreur d'ouverture du fichier\n");
        return;
    }
    fclose(F);
    }
 //-----------------------------------------------------------------------
    void Serche_moy(){

    FILE *F = fopen("etudiant.txt","r");
    if(F==NULL){
        return;
    }
    struct etudiant e;
    float moy_donne;
    int trouve=0;
    printf("entre la moyenne a rechercher:");
    scanf("%f",&moy_donne);
    while (fscanf(F,"%d %s %s %f %s",&e.id,e.name,e.prenom,&e.moyenne,e.groupe)!=EOF){
          if(e.moyenne >= moy_donne){
                printf("ID:%d \n NOM:%s \n PRENOM:%s \n MOY:%f \n GROUPE:%s \n",e.id,e.name,e.prenom,e.moyenne,e.groupe);
                 trouve=1;
          }

    }
    if(trouve==0){
        printf("ucunne etudiant trouve");
    }
   fclose(F);
}
//----------------------------------------------------------------------------------------------------
void rechercher_groupe(){
    FILE *F = fopen("etudiant.txt","r");
    if(F==NULL){
        return;
    }
  struct etudiant e;
    char groupe_rech[10];
    int trouve=0;
    printf("entre le groupe rechercher:");
    scanf("%s",groupe_rech);
    while (fscanf(F,"%d %s %s %f %s",&e.id,e.name,e.prenom,&e.moyenne,e.groupe)!=EOF){
          if(strcmp(e.groupe,groupe_rech)==0){
                printf("ID:%d \n NOM:%s \n PRENOM:%s \n MOY:%f \n GROUPE:%s \n",e.id,e.name,e.prenom,e.moyenne,e.groupe);
                 trouve=1;
          }
}
if(trouve==0){
        printf("ucunne groupe avec se nome \n");
    }
   fclose(F);

}
//--------------------------------------------------------------------------------------------------------
void ajouter(){
FILE *F = fopen("etudiant.txt","a");

    if(F == NULL){
        printf("erreur d'ouverture du fichier\n");
        return;
    }
   struct etudiant e;
   printf("entre the firste name of etudiant :");
   scanf("%s",e.name);
   printf("entre the laste name of etudiant :");
   scanf("%s",e.prenom);
   printf("entre  the id of etudiant :");
   scanf("%d",&e.id);
   printf("entre la moyenne de etudiant: ");
   scanf("%f",&e.moyenne);
   printf("entre the goupe of etudiant :");
   scanf("%s",e.groupe);


    fprintf(F,"%d %s %s %f %s \n",e.id,e.name,e.prenom,e.moyenne,e.groupe);
    fclose(F);



}
//---------------------------------------------------------------------------------------------------------------
int main() {

    int choix;

    do {
        printf("1. cree le fichier etudiant\n");
        printf("2. rechercher par moyenne.\n");
        printf("3. rechercher par goupe\n");
        printf("4. ajouter un etudiant \n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d",&choix);

        switch(choix){

            case 1:
                cree_fichier();
                break;


            case 2:
                Serche_moy();
                break;
            case 3:
                rechercher_groupe();
                break;
            case 4:
                ajouter();
                break;

            case 0:
                printf("Au revoir...\n");
                break;

            default:
                printf("Choix invalide\n");
        }

    } while(choix != 0);

    return 0;
}
