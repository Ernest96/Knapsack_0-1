#include <stdio.h>
#include <stdlib.h>
struct Obiect
{
	int W;
	int V;

}O[20];

int Valori[20][100]={0};
int Luam[20][100]={0} , cr=0,valoare_fin=0,masa_fin=0;
int maxim(int, int);

int main()
{
	int nr , Wmax;
	int k,w;

printf("Introdu numarul de obiecte : ");
scanf("%d",&nr);

printf("\r\nIntrodu capacitatea rucsacului : ");
scanf("%d",&Wmax);

for(k=1;k<=nr;k++)
{
	printf("Introdu Masa obiectului nr %d :",k);
	scanf("%d",&O[k].W);
	printf("Introdu Valoarea obiectului nr %d : ",k);
	scanf("%d",&O[k].V);

}
 for(k=1;k<=nr;k++)
 for(w=0;w<=Wmax;w++)
{
	if (O[k].W>w)
	{
		cr=0;
		Valori[k][w]=Valori[k-1][w];
	}

	else
		Valori[k][w]=maxim(Valori[k-1][w],Valori[k-1][w-O[k].W]+O[k].V);

	if(cr==1) Luam[k][w]=1;


}

for(k=nr,w=Wmax;k>0;k--)
if(Luam[k][w]==1)
{
	printf("\r\n Luam obiectul %d ",k);
	valoare_fin=valoare_fin+O[k].V;
	masa_fin=masa_fin+O[k].W;
	w=w-O[k].W;
}

printf("\r\n\r\n Valoarea maxima ce poate fi luata : %d ",valoare_fin);
printf("\r\n\r\n Masa maxima ce poate fi luata : %d ",masa_fin);


}


int maxim(int a, int b)
{

cr=0;

	if(b>a)
	 {
		cr=1; return b; 
	 } 

	else return a;




}
