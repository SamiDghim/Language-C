#include <stdio.h>
#include <stdlib.h>
#include "graphiqu_enis.h"
#include <string.h>
#include <ctype.h>
//---------------------------------controle de saisie:
int controle(char NUMBER[])
{
    int i=0;
    while(i<strlen(NUMBER))
    {
        if(!isdigit(NUMBER[i])) return 0;
        else    i++;
    }
return 1;
}
//--------------------------------fonction de saisie:
void saisie(char NUMBER[])
{
do{
    printf ("Veuillez entrer un entier a transformer : ");
    gets(NUMBER);
  }while(!controle(NUMBER));
}

//---------------------------suppression de zero a gauche:
void supp_zero(char NUMBER[])
{
int i,j;
for(i=0;i<(strlen(NUMBER))-1;i++)
{
if(NUMBER[i]=='0')
{
    for(j=i;j<strlen(NUMBER)-i;j++) NUMBER[j]=NUMBER[j+1];
     i--;
}
else break;
}}

//--------------------------------fonction qui calcul nombre de bloc:
int nombre_des_blocs(char NUMBER[],int taille)
{int bloc=taille/3;
if ((taille%3)!=0) bloc=bloc+1;
return bloc;
}

//----------------------------------------coversion d'1 blocs:-------
void transform_bloc(char CHAINE[],int nb_blocs,char NUMBER[]){
int entier = atoi(NUMBER);
int centaine=entier/100;
int dizaine=(entier-centaine*100)/10;
int unite=entier-(centaine*100)-(dizaine*10);;
int trouve=0;
if((dizaine==0)&&(unite==0)&&(nb_blocs!=2))
 {
  switch(centaine)
     {
      case 0:break;
      case 1: strcat(CHAINE," cent ");break;
      case 2: strcat(CHAINE," deux-cents ");break;
      case 3: strcat(CHAINE," trois-cents ");break;
      case 4: strcat(CHAINE," quatre-cents ");break;
      case 5: strcat(CHAINE," cinq-cents ");break;
      case 6: strcat(CHAINE," six-cents ");break;
      case 7: strcat(CHAINE," sept-cents ");break;
      case 8: strcat(CHAINE," huit-cents ");break;
      case 9: strcat(CHAINE," neuf-cents ");break;
    }
 }
 else if((dizaine!=0)||(unite!=0)||(nb_blocs==2))
 {
     switch(centaine)
     {
      case 0:break;
      case 1:strcat(CHAINE," cent ");break;
      case 2:strcat(CHAINE," deux-cent");break;
      case 3:strcat(CHAINE," trois-cent");break;
      case 4:strcat(CHAINE," quatre-cent");break;
      case 5:strcat(CHAINE," cinq-cent");break;
      case 6:strcat(CHAINE," six-cent");break;
      case 7:strcat(CHAINE," sept-cent");break;
      case 8:strcat(CHAINE," huit-cent");break;
      case 9:strcat(CHAINE," neuf-cent");break;
    }
 }
 if(centaine==0)
     {
      switch(dizaine)
       { case 0:break;
         case 1:trouve=1;break;
         case 2:strcat(CHAINE," vingt ");break;
         case 3:strcat(CHAINE," trente ");break;
         case 4:strcat(CHAINE," quarante ");break;
         case 5:strcat(CHAINE," cinquante " );break;
         case 6:strcat(CHAINE," soixante" );break;
         case 7:trouve=1;strcat(CHAINE," soixante " );break;
         case 8:if((nb_blocs!=2)&&(unite==0)) strcat(CHAINE," quatre-vingts ");else if((nb_blocs==2)||(unite!=0)) strcat(CHAINE," quatre-vingt");break;
         case 9:trouve=1;strcat(CHAINE," quatre-vingt ");
       }
     }
  else {
      switch(dizaine)
       { case 0:break;
         case 1:trouve=1;break;
         case 2:strcat(CHAINE,"-vingt ");break;
         case 3:strcat(CHAINE,"-trente ");break;
         case 4:strcat(CHAINE,"-quarante ");break;
         case 5:strcat(CHAINE,"-cinquante " );break;
         case 6:strcat(CHAINE,"-soixante" );break;
         case 7:trouve=1;strcat(CHAINE,"-soixante " );break;
         case 8:if((nb_blocs!=2)&&(unite==0)) strcat(CHAINE,"-quatre-vingts " );else if((nb_blocs==2)||(unite!=0)) strcat(CHAINE,"-quatre-vingt" );break;
         case 9:trouve=1;strcat(CHAINE,"-quatre-vingt " );
       }
  }
       if((dizaine==0)||(dizaine==1))
    {
     switch(unite)
       { case 0:if(trouve) strcat(CHAINE," dix ");break;
         case 1:if(trouve) strcat(CHAINE," onze ");else strcat(CHAINE," un ");break;
         case 2:if(trouve) strcat(CHAINE," douze ");else strcat(CHAINE," deux ");break;
         case 3:if(trouve) strcat(CHAINE," treize ");else strcat(CHAINE," trois ");break;
         case 4:if(trouve) strcat(CHAINE," quatorze ");else strcat(CHAINE," quatre ");break;
         case 5:if(trouve) strcat(CHAINE," quinze ");else strcat(CHAINE," cinq ");break;
         case 6:if(trouve) strcat(CHAINE," seize ");else strcat(CHAINE," six ");break;
         case 7:if(trouve) strcat(CHAINE," dix-sept ");else strcat(CHAINE," sept ");break;
         case 8:if(trouve) strcat(CHAINE," dix-huit ");else strcat(CHAINE," huit ");break;
         case 9:if(trouve) strcat(CHAINE," dix-neuf ");else strcat(CHAINE," neuf ");break;
       }
    }
    else {
    switch(unite)
       {
         case 0:if(trouve) strcat(CHAINE,"-dix ");break;
         case 1:if(trouve) strcat(CHAINE,"-onze ");else strcat(CHAINE," et un");break;
         case 2:if(trouve) strcat(CHAINE,"-douze ");else strcat(CHAINE,"-deux " );break;
         case 3:if(trouve) strcat(CHAINE,"-treize ");else strcat(CHAINE,"-trois ");break;
         case 4:if(trouve) strcat(CHAINE,"-quatorze ");else strcat(CHAINE,"-quatre ");break;
         case 5:if(trouve) strcat(CHAINE,"-quinze ");else strcat(CHAINE,"-cinq ");break;
         case 6:if(trouve) strcat(CHAINE,"-seize ");else strcat(CHAINE,"-six ");break;
         case 7:if(trouve) strcat(CHAINE,"-dix-sept ");else strcat(CHAINE,"-sept ");break;
         case 8:if(trouve) strcat(CHAINE,"-dix-huit ");else strcat(CHAINE,"-huit ");break;
         case 9:if(trouve) strcat(CHAINE,"-dix-neuf ");else strcat(CHAINE,"-neuf ");break;
       }
    }
}
//----------------------------ajouter  les zéllions:-------------------------------
void BLOC(char CHAINE[],int k,char aux[]){

int bloc=atoi(aux);

switch (k){
case 2 :if (bloc==1) strcat(CHAINE," mille");        else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE,"-mille-");break;
case 3 :if (bloc==1) strcat(CHAINE," million ");     else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," millions ");break;
case 4 :if (bloc==1) strcat(CHAINE," milliard ");    else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," milliards ");break;
case 5 :if (bloc==1) strcat(CHAINE," billion ");     else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," billions ");break;
case 6 :if (bloc==1) strcat(CHAINE," billiard ");    else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," billiards ");break;
case 7 :if (bloc==1) strcat(CHAINE," trillion ");    else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," trillions ");break;
case 8 :if (bloc==1) strcat(CHAINE," trilliard ");   else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," trilliards ");break;
case 9 :if (bloc==1) strcat(CHAINE," quadrillion "); else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," quadrillions ");break;
case 10:if (bloc==1) strcat(CHAINE," quadrilliard ");else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," quadrilliards ");break;
case 11:if (bloc==1) strcat(CHAINE," quintillion "); else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," quintillions ");break;
case 12:if (bloc==1) strcat(CHAINE," quintilliard ");else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," quintilliards ");break;
case 13:if (bloc==1) strcat(CHAINE," sextillion ");  else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," sextillions ");break;
case 14:if (bloc==1) strcat(CHAINE," sextilliard "); else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," sextilliards ");break;
case 15:if (bloc==1) strcat(CHAINE," septillion ");  else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," septillions ");break;
case 16:if (bloc==1) strcat(CHAINE," septilliard "); else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," septilliards ");break;
case 17:if (bloc==1) strcat(CHAINE," Octillion ");   else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," octillions ");break;
case 18:if (bloc==1) strcat(CHAINE," octilliard ");  else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," octilliards ");break;
case 19:if (bloc==1) strcat(CHAINE," nonillion ");   else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," nonillions ");break;
case 20:if (bloc==1) strcat(CHAINE," nonilliard ");  else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," nonilliards ");break;
case 21:if (bloc==1) strcat(CHAINE," decillion ");   else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," décillions ");break;
case 22:if (bloc==1) strcat(CHAINE," decilliard ");  else if (bloc==0) strcat(CHAINE,"");else strcat(CHAINE," décilliards ");break;
}
}
//
void conversion_finale(char NUMBER[],int nb_blocs,int taille_premier_bloc,char CHAINE[])
{
int i,j;
char aux[3];
strncpy(aux,NUMBER,taille_premier_bloc);

transform_bloc(CHAINE,nb_blocs,aux);

BLOC(CHAINE,nb_blocs,aux);

for(i=taille_premier_bloc;i<=strlen(NUMBER);i=i+3)
{
    for(j=i-taille_premier_bloc;j<3;j++) aux[j]=NUMBER[i+j];//copier un bloc dans aux:
       transform_bloc(CHAINE,nb_blocs,aux);
       nb_blocs--;//dectrementer le nombre de bloc:
       BLOC(CHAINE,nb_blocs,aux);
       taille_premier_bloc+=3;

}}
//procedure qui fait la transformation finale de nombre en tout lettre:
void Transformation_des_nombres_en_lettres(char NUMBER[],char CHAINE[])
{
saisie(NUMBER);
supp_zero(NUMBER);
int taille=strlen(NUMBER);
int nb_blocs=nombre_des_blocs(NUMBER,taille);
int taille_premier_bloc=taille-((nb_blocs-1)*3);//determiner la taille de 1er bloc:
CHAINE[0]='\0';///initialiser la chaine "CHAINE":
if(atoi(NUMBER)==0) strcat(CHAINE,"zero");
else conversion_finale(NUMBER,nb_blocs,taille_premier_bloc,CHAINE);
}
/******************************application cheque*****************************************/
void retoure_ligne_cheque(char ch[],int max_caratere,int l,int x,int y,int *w){

char nb1[10000];
char nb[10000];
 int j,k;
if(strlen(ch)>max_caratere)
{
for(k=max_caratere;k>=0;k--)
  {
  if((ch[k]==' ')||(ch[k]=='-')) break;
  }
strncpy(nb,ch,k);
nb[k]='\0';
EcritXY(x,y-l,nb,22);
     Trait(13,202-l,530,202-l,20);
     Trait(13,202-l,13,213-l,20);
     Trait(530,202-l,530,213-l,20);

for(j=k;j<strlen(ch);j++) nb1[j-k]=ch[j];
nb1[strlen(ch)]='\0';
l+=30;

return(retoure_ligne_cheque(nb1,max_caratere,l,x,y,w));//appel recursive
    }
   else{
     Trait(13,202-l,530,202-l,20);
     Trait(13,202-l,13,213-l,20);
     Trait(530,202-l,530,213-l,20);
     EcritXY(x,y-l,ch,22);
}
   *w=l;
    }
//
void graphique_cheque(char chaine[],char number[])
{
char ch[] ="CHEQUE DE BANQUE";
char ch1[] ="Payer  contre ce cheque non endossable (somme en toutes lettres)  :";
char ch3[] ="à rediger exclusivement en DT";
char ch4[] ="à";
char ch5[] ="Fait à ";
char ch6[] ="Le";
char ch61[] ="            /              /";
char ch7[] =" Compte bancaire n :";
char ch8[] =" Numero de Cheque :";
char ch9[] =" Signature ";
char ch10[] ="    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |";
int w;

     w=(strlen(chaine)/80)*30;
     Initialisation_Graphique(-30,-30-w,780,400);//Dimension fenetre
     //------------------creation couleur-----------------------------
     CreateColorRGB (20,54,195,235);
     CreateColorRGB (21,54,150,235);
     CreateColorRGB (22,39,43,245);
     CreateColorRGB (23,240,240,240);
     CreateColorRGB (24,240,240,240);
     DrawRectangle (-2,-2-w,752,372,1);//dimension cheque
     FillRectangle (0,0-w,750,370,7); //fond cheque
     //----------------------- debut en tete cheque---------------------------
     Disque (100,330,23,20);
     Disque (115,330,23,21);
     Disque (130,330,23,22);
     Hauteur_Texte (25);
     EcritXY (170,328,ch,15);
     EcritXY (170,330,ch,22);
     Trait(130,325,660,325,22);
     Trait(152,323,660,323,20);
     Trait(152,321,660,321,22);
     //-----------------------fin en tete cheque---------------------------
     Hauteur_Texte (12);
     EcritXY (20,250,ch1,0);//Payer  contre ce cheque non endossable
     EcritXY (550,250,ch3,0);//à rediger exclusivement en DT
     //--------------zone affichage nombre en lettre--------------------------
     Hauteur_Texte (13.5);//taille nombre en lettre
     retoure_ligne_cheque(chaine,80,0,20,204,&w);
     FillRectangle (545,200,738,235,23);//zone affichage de nombre en chiffre
     Hauteur_Texte (13.5);//taille nombre en chiffre
     EcritXY (547,212,number,4);//afficher le nombre en chiffre
     Hauteur_Texte (13);
     //-----------------zone beneficitaire------------------------
     EcritXY (13,150-w,ch4,0);
     Trait(26,150-w,530,150-w,20);
     Trait(26,150-w,26,160-w,20);
     Trait(530,150-w,530,160-w,20);
     //-----------------lieu-------------------
     EcritXY (550,150-w,ch5,0);
     Trait(600,150-w,738,150-w,20);
     Trait(600,150-w,600,160-w,20);
     Trait(738,150-w,738,160-w,20);
     //--------------date-------------------
     EcritXY (550,121-w,ch6,0);
     EcritXY (568,121-w,ch61,20);
     Trait(570,120-w,738,120-w,20);
     Trait(570,120-w,570,130-w,20);
     Trait(738,120-w,738,130-w,20);
     //-----------------signature-------------------
     DrawRectangle (18,20-w,530,130-w,5);
     FillRectangle (570,30-w,738,110-w,23);//zone signature
     EcritXY (620,15-w,ch9,0);
     //--------------numero de compte-----------------------
     EcritXY (20,110-w,ch7,0);
     Trait(26,85-w,520,85-w,20);
     Trait(26,85-w,26,95-w,20);
     Trait(520,85-w,520,95-w,20);
     EcritXY (26,84-w,ch10,20);
     //--------------numero de cheque-----------------------
     EcritXY (20,60-w,ch8,0);
     Trait(26,35-w,520,35-w,20);
     Trait(26,35-w,26,45-w,20);
     Trait(520,35-w,520,45-w,20);
     EcritXY (26,34-w,ch10,20);
     Attente();
     Fin_Graphique();
}
/*****************************************************************************/
/************************application jeu**************************************/
void retoure_ligne_jeu(char ch[],int max_caratere,int l,int x,int y,int *w){
 char nb1[10000];
 char nb[10000];
 int j,k;
if(strlen(ch)>max_caratere)
{
for(k=max_caratere;k>=0;k--)
  {
  if((ch[k]==' ')||(ch[k]=='-')) break;
}
strncpy(nb,ch,k);
nb[k]='\0';
EcritXY(x,y-l,nb,22);
for(j=k;j<strlen(ch);j++) nb1[j-k]=ch[j];
nb1[strlen(ch)]='\0';
l+=30;
return(retoure_ligne_jeu(nb1,max_caratere,l,x,y,w));
    }
   else
   {
EcritXY(x,y-l,ch,22);
   }
   *w=l;
    }
void affiche_info(char ch[],int *w){
char ch2[]="Le Premier zero etait invente par les Babyloniens en 2 000 av J.C , en effet c'etait une nouvelle façon de representer les nombres et surtout le vide......";
char ch3[]="Les chiffres arabes sont les dix chiffres (1, 2, 3, 4, 5, 6, 7, 8, 9,0) .Ils ont ete inventes en Inde. Leur existence est mentionnee en Syrie, au milieu du VIIe siecle par l'eveque Severe Sebokt";
char ch4[]="Les chiffres romains, d'apres les regles actuelles, ne permettent de représenter les nombres que jusqu'à 4999, le signe pour 5000 n'existant pas c'est pour cela ils etaient remplaces par les chiffres arabes";
char ch6[]="La premiere apparition connue des nombres negatifs est dans ' Les Neuf Chapitres sur l'art mathematique ' (Jiu zhang suan-shu) , en IIe  siecle  avant  J.C Cela permettait aux chinois de resoudre un systeme d'equations lineaires a coefficients negatifs";
char ch7[]="L'histoire des nombres complexes commence vers le milieu du XVIe siecle avec une premiere apparition en 1545 apres avoir rendre les règles de calcul impossibles  imaginaires.";
char ch8[]="En Egypte, en l'an 3500 avant J.C, la notation des chiffres etait basee, comme l'ecriture, sur les hieroglyphes. Chaque signe possédait une valeur, tel que:les milliers par une fleur de Lotus etc...";

if(strlen(ch)<7) retoure_ligne_jeu(ch6,70,0,140,170,w);
else if(strlen(ch)<11) retoure_ligne_jeu(ch7,70,0,140,170,w);
else if(strlen(ch)<16) retoure_ligne_jeu(ch8,70,0,140,170,w);
	else if(strlen(ch)<22) retoure_ligne_jeu(ch4,70,0,140,170,w);
	else if(strlen(ch)<26) retoure_ligne_jeu(ch3,70,0,140,170,w);
	else retoure_ligne_jeu(ch2,70,0,140,170,w);
}
void graphique_jeu(char ch[],char number[]){
    Initialisation_Graphique(0,0,750,450);
    CreateColorRGB (20,54,195,235);
    CreateColorRGB (21,54,150,235);
    CreateColorRGB (22,39,43,245);
    CreateColorRGB (23,240,240,240);
    CreateColorRGB (24,240,240,240);
    CreateColorRGB (6,110,101,211);
  char ch1[]="Savez-vous que :";
      int k=4,i;

    for(i=830;i>0;i-=50)
   {
		 Disque (375,-50,i,k);
         k++;
         if(k==15)
         k=2;
   }
   int w,w1;
FillRectangle(95,380,650,430,15);

FillRectangle(100,385,645,425,12);

retoure_ligne_jeu(ch,92,0,80,317,&w1);

FillRectangle(60,295-w1,690,350,15);
FillRectangle(65,300-w1,685,345,2);
FillRectangle(70,305-w1,680,340,15);

Hauteur_Texte(13);
retoure_ligne_jeu(ch,92,0,80,317,&w1);

Hauteur_Texte(27);
EcritXY(250,222,ch1,0);
EcritXY(250,222,ch1,15);
EcritXY(250,224,ch1,15);
EcritXY(250,226,ch1,15);
EcritXY(250,228,ch1,0);

Hauteur_Texte(13);

affiche_info(number,&w);
FillRectangle(120,150-w,640,200,15);
FillRectangle(125,155-w,635,195,13);
FillRectangle(130,160-w,630,190,15);

affiche_info(number,&w);
Hauteur_Texte(17);

FillRectangle(110,390,640,420,15);
EcritXY(120,400,number,13);
    Attente();
   Fin_Graphique();
}
/*****************************************************************************/
//choix de l'application à executer:
void choix(char CHAINE[],char NUMBER[]){
int choisir;
printf("\n-Que voulez vous faire ?\n\n1-application de cheque bancaire:\n2-application de jeu d enfant:\n");
scanf("%i",&choisir);
if(choisir==1){
    graphique_cheque(CHAINE,NUMBER);
}
else if(choisir==2){
    graphique_jeu(CHAINE,NUMBER);
}
else{
printf("saisie errone !!!");
}
}
//programme principale:
int main() {
char NUMBER[100000];
char CHAINE[100000];
char c;
Transformation_des_nombres_en_lettres(NUMBER,CHAINE);
printf("interface graphique (o/n):\n");
scanf("%c",&c);
if((c=='O')||(c=='o')){
choix(CHAINE,NUMBER);
}
else if((c=='n')||(c=='N')){
puts(CHAINE);
}
return 0;
}
