#include <stdio.h>
#include <stdlib.h>

//Todos los primos en decimal y binario 1-1000
//ocurrencias de 1's
int Binario(int);
int Cousin(int);
int l=0;

int main() {
	system("color 01");
	system("color F0");


		int op,n,m,k,r;
	
do{
	printf("\n\n1. Escoger numero\n2. Random\n");
	scanf("%d",&op);
	switch(op){
		case 1:
			scanf("%d",&n);
				for(k=0;k<=n;k++){
				if(Cousin(k)==1)
				printf("%d,",k);}
			printf("\n\n");
				for(k=0;k<=n;k++){
				if(Cousin(k)==1){
				Binario(k);}}
			printf("\n\nOcurrencias de 1's: %d",l);
			break;
		case 2:
			m=rand()%1001;
			printf("El numero random es: %d\n\n",m);
				for(r=0;r<=m;r++){
					if(Cousin(r)==1){
					printf("%d,",r);}}
			printf("\n\n");		
				for(r=0;r<=m;r++){
					if(Cousin(r)==1){
					Binario(r);}}
			printf("\n\nOcurrencias de 1's: %d",l);
			break;
	}}while(op==1||op==2);
	return 0;
}


int Binario(int n){

	int i=0;
	int j;
	int a[10];



while(n>0){
	if(n%2==0){
		a[i]=0;
		i++;}
	else{
		a[i]=1;
		l++;
		i++;
		}
	n=n/2;
}

for(j=i-1;j>=0;j--){
printf("%d",a[j]);
}
printf(",");
}


int Cousin(int o){
	int w;
	int cont2=0;
	if(o==1||o==0){
		return 0;}
	else{
	for (w=1;w<o;w++){
		if(o%w==0){
			cont2++;}
	}
	if(cont2>1)
		return 0;
	else
		return 1;
}}
 
