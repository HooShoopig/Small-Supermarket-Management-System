#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void dians(){
	int x=8;
	gotoCoordinate(x*3,8);
	printf(" **");
	gotoCoordinate(x*3,9);
	printf(" **");
	gotoCoordinate(x*3,11);
	printf(" **");
	gotoCoordinate(x*3,12);
	printf(" **");
	
	gotoCoordinate(x*6,8);
	printf(" **");
	gotoCoordinate(x*6,9);
	printf(" **");
	gotoCoordinate(x*6,11);
	printf(" **");
	gotoCoordinate(x*6,12);
	printf(" **");
}

void draw_numb(int x,int shu){ 
	if(shu==0){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("*   *");
		gotoCoordinate(x,8);
		printf("*   *");
		gotoCoordinate(x,9);
		printf("*   *");
		gotoCoordinate(x,10);
		printf("*   *");
		gotoCoordinate(x,11);
		printf("*   *");
		gotoCoordinate(x,12);
		printf("*   *");
		gotoCoordinate(x,13);
		printf("*   *");
		gotoCoordinate(x,14);
		printf("*****");
	}
	if(shu==1){
		gotoCoordinate(x,6);
		printf("  *  ");
		gotoCoordinate(x,7);
		printf("  *  ");
		gotoCoordinate(x,8);
		printf("  *  ");
		gotoCoordinate(x,9);
		printf("  *  ");
		gotoCoordinate(x,10);
		printf("  *  ");
		gotoCoordinate(x,11);
		printf("  *  ");
		gotoCoordinate(x,12);
		printf("  *  ");
		gotoCoordinate(x,13);
		printf("  *  ");
		gotoCoordinate(x,14);
		printf("  *  ");
	}
	if(shu==2){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("    *");
		gotoCoordinate(x,8);
		printf("    *");
		gotoCoordinate(x,9);
		printf("    *");
		gotoCoordinate(x,10);
		printf("*****");
		gotoCoordinate(x,11);
		printf("*    ");
		gotoCoordinate(x,12);
		printf("*    ");
		gotoCoordinate(x,13);
		printf("*    ");
		gotoCoordinate(x,14);
		printf("*****");
	}
	if(shu==3){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("    *");
		gotoCoordinate(x,8);
		printf("    *");
		gotoCoordinate(x,9);
		printf("    *");
		gotoCoordinate(x,10);
		printf("*****");
		gotoCoordinate(x,11);
		printf("    *");
		gotoCoordinate(x,12);
		printf("    *");
		gotoCoordinate(x,13);
		printf("    *");
		gotoCoordinate(x,14);
		printf("*****");
	}
	if(shu==4){
		gotoCoordinate(x,6);
		printf("*   *");
		gotoCoordinate(x,7);
		printf("*   *");
		gotoCoordinate(x,8);
		printf("*   *");
		gotoCoordinate(x,9);
		printf("*   *");
		gotoCoordinate(x,10);
		printf("*****");
		gotoCoordinate(x,11);
		printf("    *");
		gotoCoordinate(x,12);
		printf("    *");
		gotoCoordinate(x,13);
		printf("    *");
		gotoCoordinate(x,14);
		printf("    *");
	}
	if(shu==5){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("*    ");
		gotoCoordinate(x,8);
		printf("*    ");
		gotoCoordinate(x,9);
		printf("*    ");
		gotoCoordinate(x,10);
		printf("*****");
		gotoCoordinate(x,11);
		printf("    *");
		gotoCoordinate(x,12);
		printf("    *");
		gotoCoordinate(x,13);
		printf("    *");
		gotoCoordinate(x,14);
		printf("*****");
	} 
	if(shu==6){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("*    ");
		gotoCoordinate(x,8);
		printf("*    ");
		gotoCoordinate(x,9);
		printf("*    ");
		gotoCoordinate(x,10);
		printf("*****");
		gotoCoordinate(x,11);
		printf("*   *");
		gotoCoordinate(x,12);
		printf("*   *");
		gotoCoordinate(x,13);
		printf("*   *");
		gotoCoordinate(x,14);
		printf("*****");
	}
	if(shu==7){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("    *");
		gotoCoordinate(x,8);
		printf("    *");
		gotoCoordinate(x,9);
		printf("    *");
		gotoCoordinate(x,10);
		printf("    *");
		gotoCoordinate(x,11);
		printf("    *");
		gotoCoordinate(x,12);
		printf("    *");
		gotoCoordinate(x,13);
		printf("    *");
		gotoCoordinate(x,14);
		printf("    *");
	}
	if(shu==8){
		gotoCoordinate(x,6);
		printf("*****");
		gotoCoordinate(x,7);
		printf("*   *");
		gotoCoordinate(x,8);
		printf("*   *");
		gotoCoordinate(x,9);
		printf("*   *");
		gotoCoordinate(x,10);
		printf("*****");
		gotoCoordinate(x,11);
		printf("*   *");
		gotoCoordinate(x,12);
		printf("*   *");
		gotoCoordinate(x,13);
		printf("*   *");
		gotoCoordinate(x,14);
		printf("*****");
	}
	if(shu==9){
			gotoCoordinate(x,6);
			printf("*****");
			gotoCoordinate(x,7);
			printf("*   *");
			gotoCoordinate(x,8);
			printf("*   *");
			gotoCoordinate(x,9);
			printf("*   *");
			gotoCoordinate(x,10);
			printf("*****");
			gotoCoordinate(x,11);
			printf("    *");
			gotoCoordinate(x,12);
			printf("    *");
			gotoCoordinate(x,13);
			printf("    *");
			gotoCoordinate(x,14);
			printf("*****");
	}	
}

void draws(char wei,int shu){
	int x=8;
		if(wei=='1'){
			draw_numb(x*1,shu);
		}				
		if(wei=='2'){
			draw_numb(x*2,shu);
		}
		if(wei=='3'){
			draw_numb(x*4,shu);
		}
		if(wei=='4'){
			draw_numb(x*5,shu);
		}
		if(wei=='5'){
			draw_numb(x*7,shu);
		}
		if(wei=='6'){
			draw_numb(x*8,shu);
		}		
}

void clocks(){
	system("cls"); 
    struct tm *curtime; 	
    time_t t;         	
    clock_t start;	
    
    double th_hour,th_min,th_sec;
    while(!kbhit()){
		printf("\t____________________________________________________________________");
  		dians();
        t=time(0);							
        curtime=localtime(&t);
        if((double)curtime->tm_hour<=12)	
		{	gotoCoordinate(5,3);
            draws('1',((int)curtime->tm_hour)/10);
            draws('2',((int)((double)curtime->tm_hour))%10);
		}
        else				
		{	gotoCoordinate(5,3);
            draws('1',(int)curtime->tm_hour/10);
            draws('2',((int)((double)curtime->tm_hour))%10);
		}
        if((double)curtime->tm_min<10) draws('3',0);
        draws('3',(int)curtime->tm_min/10);
        draws('4',(int)curtime->tm_min%10);
        if((double)curtime->tm_sec<10) draws('5',0);
        draws('5',(int)curtime->tm_sec/10);
        draws('6',(int)curtime->tm_sec%10);
        start=clock();
        printf("\n\n\n\n\t____________________________________________________________________");
        while(clock()-start<500);  //µÈ´ýÑÓÊ±1000ms
        system("cls");
    }  
}

