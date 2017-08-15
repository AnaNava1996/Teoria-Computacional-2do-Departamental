#include <stdio.h>////////RECUERDA PONER 1000 EN EL RANDOM!!
#include <stdlib.h>
#include <cstring>



struct ana{
	char dato;
	struct ana *ptrSig;// creo una estructura con un puntero
};

struct ana *ptrCab=NULL;//creo un puntero de tipo structura ana
void meterDato(void);
void sacarDato(void);
void mostrarPila(void);
const int MAX=1000;

int main() {
int i,j,p,q,m,n,r,o,op,random1,random2,k,opcion,estado;
int arre[MAX];
char array[MAX];


while(opcion!=3){
	printf("\n\n1- Para automatico\n2-Para manual\n3-para salir\nElija opcion:  ");
	scanf("%d",&opcion);
	switch(opcion){
	case 1:
		FILE *ar;
		ar=fopen("AutoPila.txt","a+");
		fprintf(ar,"\n\nModo Automatico\n");
		printf("\n");
		random1=rand()%15;//genero la longitud random de ceros
		random2=rand()%15;//de unos
		printf("%d y %d\n",random1, random2);
		//estado=0;
		estado=1;
		k=0;
		printf("(q%d,",estado);
		fprintf(ar,"(q%d,",estado);
		for(r=0;r<random1;r++){
			arre[r]=0;//genero la cadena de ceros
			printf("%d",arre[r]);
			fprintf(ar,"%d",arre[r]);}
		for(p=0;p<random2;p++){
			arre[r+p]=1;//concateno los 1
			printf("%d",arre[r+p]);
			fprintf(ar,"%d",arre[r+p]);}
		fclose(ar);
		mostrarPila();
		for(i=0;i<(r+p);i++){
			k++;	
			if((ptrCab!=NULL || arre[i]==0)){//evaluo cada elemento...
		        switch(arre[i]){
		          	case 0:
		          		estado=1;
		          		meterDato();
		        		FILE *arch;
						arch=fopen("AutoPila.txt","a+");
		          		printf("(q%d,",estado);
		          		fprintf(arch,"(q%d,",estado);
		          		for(m=k;m<(r+p);m++){
		          			printf("%d",arre[m]);
		          			fprintf(arch,"%d",arre[m]);
						  }
						fclose(arch);
						  mostrarPila();
		          		break;
		          	case 1:
		          		//ptrCab=NULL; AQUI NO
		          		sacarDato();
		        		FILE *archi;
						archi=fopen("AutoPila.txt","a+");
		          		if((random1==random2)&&(ptrCab==NULL)){
		          			estado=3;}
		          		else{
		          			estado=2;}
		          		printf("(q%d,",estado);
		          		fprintf(archi,"(q%d,",estado);
		          		for(m=k;m<(r+p);m++){
		          			printf("%d",arre[m]);
		          			fprintf(archi,"%d",arre[m]);
						  }
						  fclose(archi);
						  mostrarPila();
		          		break;
		          	}}
		    else{
			printf("\nNo se puede sacar el vacio");
			ptrCab=NULL;//es necesario para que no agregue mas X a la pila y truene de una vez...
			i=r+p+1;}
		}
		ptrCab=NULL;//para que truene definitivo...
		if(estado==3){
		printf("\nSirve");
		FILE *archivito;
		archivito=fopen("AutoPila.txt","a+");
		fprintf(archivito,"\t\tSIRVE");
		fclose(archivito);
		//fprintf(ar,"\nSirve");
		}
	break;
	
	case 2://///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		estado=1;
		k=0;
		FILE *ar2;
		ar2=fopen("AutoPila.txt","a+");
		fprintf(ar2,"\n\nModo Manual:\n");
		scanf("%s",&array);
		q=strlen(array);//sirve para saber el largo de la cadena
		printf("%d\n\n\n",q); 

		printf("(q%d,",estado);
		fprintf(ar2,"(q%d,",estado);
		for(r=0;r<q;r++){
			array[r]=array[r]-48;//casting
			printf("%d",array[r]);
			fprintf(ar2,"%d",array[r]);}
		fclose(ar2);
		mostrarPila();	
		
		for(i=0;i<q;i++){
			k++;
			o=k;	
			if((ptrCab!=NULL || array[i]==0)){//evaluo cada elemento...
		        switch(array[i]){
		          	case 0:
		          		FILE *arch2;
		          		arch2=fopen("AutoPila.txt","a+");
		          		estado=1;
		          		meterDato();
		          		printf("(q%d,",estado);
		          		fprintf(arch2,"(q%d,",estado);
		          		for(m=k;m<q;m++){
		          			printf("%d",array[m]);
		          			fprintf(arch2,"%d",array[m]);
						  }
						  fclose(arch2);
						  mostrarPila();
		          		break;
		          	case 1:
		          		FILE *archi2;
		          		archi2=fopen("AutoPila.txt","a+");
		          		sacarDato();
		          		if((o==q)&&(ptrCab==NULL)){//compara que ya se hayan leido tantos caracteres como el largo de la cadena
		          			estado=3;}
		          		else{
		          			estado=2;}
		          		printf("(q%d,",estado);
		          		fprintf(archi2,"(q%d,",estado);
		          		for(m=k;m<q;m++){
		          			printf("%d",array[m]);
		          			fprintf(archi2,"%d",array[m]);
						  }
						  fclose(archi2);
						  mostrarPila();
		          		break;
		          	}}
		    else{
			printf("\nNo se puede sacar el vacio, truena");
			ptrCab=NULL;//es necesario para que no agregue mas X a la pila y truene de una vez...
			i=q;}///////////////////////////////////////////////////////////////////////////////////////////////////
		}
		ptrCab=NULL;//para que truene definitivo...		
		if(estado==3){
		FILE *archivito2;
		archivito2=fopen("AutoPila.txt","a+");
		printf("\nSIRVE");
		fprintf(archivito2,"\t\tSIRVE");
		fclose(archivito2);}
		break;

		}
}


}

void meterDato(void){
	struct ana *ptrNew;
	ptrNew=(struct ana *)malloc(sizeof(struct ana));
	ptrNew->dato='X';
	ptrNew->ptrSig=NULL;
	if (ptrCab==NULL){//si lista vacia
	ptrCab=ptrNew;
}
	else{
	ptrNew->ptrSig=ptrCab;//el ptrNew Siguiente, toma el valor que hay en la cima... 
	ptrCab=ptrNew;	//mientras que ptrCab toma el valor de ptrNew
}
}

void sacarDato(void){
if (ptrCab==NULL){
	printf("\nesta vacio, no puede sacar nada, truena\n");
}
else{
	//printf("\nEl dato sacado es: %c\n",ptrCab->dato); codigo viejo
	ptrCab=ptrCab->ptrSig;
}

}


void mostrarPila(void){
FILE *arc;
arc=fopen("AutoPila.txt","a+");
struct ana *ptrAna;
ptrAna=ptrCab;
printf(",");
fprintf(arc,",");
if (ptrCab==NULL){
	printf("Z0),");
	fprintf(arc,"Z0),");
}
else{
while(ptrAna!=NULL){
printf("%c",ptrAna->dato);
fprintf(arc,"%c",ptrAna->dato);
ptrAna=ptrAna->ptrSig;
}
printf("Z0),");
fprintf(arc,"Z0),");
}

fclose(arc);

}





