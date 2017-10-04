#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main (){
	//input
	float x[10],y[10],m,c,hasil;
	//other
	int i,j,n;
	//temp
	float x2[10],y2[10],xy[10];
	float error[10],y1[10];
	//Jumlah
	float Ex=0,Ey=0,Ex2=0,Ey2=0,Exy=0;
	float Eerror=0,Ey1=0;
	
	printf("\t\tTUGAS METNUM 2 Regresi Linier\n \t   Akbar Nugraha & Devy Rizky Andriana \n N max = 10\n\n");
	printf("Masukan Nilai N:"); scanf("%d",&n);
	for (i=1;i<=n;i++){
	
	printf("Masukan Nilai X %d:",i); scanf("%f",&x[i]);
	printf("Masukan Nilai Y %d:",i); scanf("%f",&y[i]);
	}
	
	
	
	system("cls");
	
	printf("|no|\tx\t|\t y \t |\t x^2\t |\t y^2\t |\t xy\t |\t error\t|\t y^1\t|\n");
	for (j=1;j<=n;j++){
		
		
		// isi nilai var iterasi
		x2[j]		=x[j]*x[j];
		y2[j]		=y[j]*y[j];
		xy[j]		=x[j]*y[j];
		// isi jumlah keseluruhan
		Ex= Ex+x[j];
		Ey= Ey+y[j];
		Exy= Exy+xy[j];
		Ex2= Ex2+x2[j];
		Ey2= Ey2+y2[j];
		//hitungan m dan c
		m= ((n*Exy)-(Ex*Ey))/((n*Ex2)-(Ex*Ex));
		c= ((Ey*Ex2)-(Ex*Exy))/((n*Ex2)-(Ex*Ex));
		
		y1[j]= m*x[j]+c;
		error[j]= y[j]-y1[j];	
		Eerror= Eerror+error[j];
		Ey1= Ey1+y1[j];
		//cek agar absolut
		if(c<=0){
			c=c*(-1);
		}
		if(y1[j]<0){
			y1[j]=y1[j]*(-1);
		}
		if(error[j]<0){
			error[j]=error[j]*(-1);
			
		}
		//cetak Nilai
		printf (" %d\t",j);
		printf ("%f\t",x[j]);
		printf ("%f\t",y[j]);
		printf ("%f\t",x2[j]);
		printf ("%f\t",y2[j]);
		printf ("%f\t",xy[j]);
		printf ("%f\t",error[j]);
		printf ("%f\n",y1[j]);
	
	}
	
	
	
	printf("Jumlah x=%f\t",Ex);
	printf("y=%f\t",Ey);
	printf("x^2=%f\t",Ex2);
	printf("y^2=%f\t",Ey2);
	printf("xy=%f\t",Exy);
	printf("error=%f\t",Eerror);
	printf("y^1=%f\t",Ey1);
	printf("\n\nFungsi Utamanya\n F(x)=%f(x)+%f",m,c);
	printf("\nmaka untuk F(%d)=%f(%d)+%f",n,m,n,c);
	hasil=(m*n)+c;
	printf("\nHasilnya adalah : +- %f",hasil);
		
	
	getch();
	
	return 0;
}
