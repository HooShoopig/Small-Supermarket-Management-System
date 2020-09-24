#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
#include <ctime>
#include<time.h>
#include<windows.h>
#include<algorithm>
#include"em.h"
#define COUNT 30  /*声明商品的种类为30种*/

int count=0;      /*商品总数记录*/
int day=0;        /*天数记录*/ 
char date[20];    /*时间记录*/
int location_mainmenu=0;
int location_billsmenu=0;
int location_productmenu=0;
int location_salesmenu=0;

void output();
void begin();
void input(); 
void add();
void dele();
void find();
void modify();
void sort();
void record();
void output_record();
void remove_record();
void bill();
void daily_price(); 
void print_bill();
void intropeople();
void put_date();
void recover(); 
void gotoCoordinate(int x,int y);
void hideCursor();
void myColor(int fore,int back);
int getLocationKey(int *location,int n);
void show_mainmenu(int location_mainmenu);
void show_productmenu(int location_productmenu);
void show_billsmenu(int location_billsmenu);
void show_salesmenu(int location_salesmenu);
void productmenu();
void salesmenu();
void billsmenu();
void Rabit(); 
void Rabit();

/*存数商品信息的结构体*/
struct marketproduct{  
    char   product_id[30];        /*商品编号*/ 
    char   product_name[30];      /*商品名称*/ 
    double product_price;         /*商品价格*/ 
    double product_discount;      /*商品折扣*/ 
    int    product_amount;        /*商品总数目*/ 
    int    product_remain;        /*商品剩余数目*/ 
}product[COUNT]; 

/*存数每日销售记录的结构体*/
struct daily_sales_record{ 
    char product_id[30];          /*商品编号*/ 
    char product_name[30];        /*商品名称*/
    int  sales_number;            /*商品销售量*/
	double total_price;           /*单种商品销售总价*/ 
    int day_record;               /*天数*/
}sales_record[COUNT]; 

/*顾客账单记录结构体*/ 
struct bill_product{
	char product_id[30];          /*商品编号*/ 
    char product_name[30];        /*商品名称*/
    int product_number;           /*单种商品数量*/
    double total_price;           /*单种商品总价*/
}product_record[COUNT];

/*开账单结构体*/ 
struct bill_adults{
	char employee_name[20];       /*开账人员姓名*/ 
	char time[20];                /*开账时间*/ 
	double total_product_price;   /*所有商品总价*/ 
};

/*主菜单展示*/
void show_mainmenu(int location_mainmenu){
	gotoCoordinate(0,0); 
	hideCursor();
	//Rabit();
	Rabit();
	switch(location_mainmenu){
		case 0:{
			myColor(7,1);
			printf("\t*                                      商品信息管理                                           *\n");
			myColor(11,0);
			printf("\t*                                      销售记录管理                                           *\n");
            printf("\t*                                      销售账单记录                                           *\n");
            printf("\t*                                      员工信息管理                                           *\n");
            printf("\t*                                      开发人员介绍                                           *\n");
            printf("\t*                                       系统初始化                                            *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 1:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			myColor(7,1);
			printf("\t*                                      销售记录管理                                           *\n");
			myColor(11,0);
            printf("\t*                                      销售账单记录                                           *\n");
            printf("\t*                                      员工信息管理                                           *\n");
            printf("\t*                                      开发人员介绍                                           *\n");
            printf("\t*                                       系统初始化                                            *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 2:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      销售记录管理                                           *\n");
			myColor(7,1); 
			printf("\t*                                      销售账单记录                                           *\n");
			myColor(11,0);
			printf("\t*                                      员工信息管理                                           *\n");
            printf("\t*                                      开发人员介绍                                           *\n");
            printf("\t*                                       系统初始化                                            *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 3:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      销售记录管理                                           *\n");
	    	printf("\t*                                      销售账单记录                                           *\n");
			myColor(7,1); 
			printf("\t*                                      员工信息管理                                           *\n");
			myColor(11,0); 
            printf("\t*                                      开发人员介绍                                           *\n");
            printf("\t*                                       系统初始化                                            *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 4:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      销售记录管理                                           *\n");
	    	printf("\t*                                      销售账单记录                                           *\n");
	    	printf("\t*                                      员工信息管理                                           *\n");
	    	myColor(7,1);
            printf("\t*                                      开发人员介绍                                           *\n");
            myColor(11,0);
            printf("\t*                                       系统初始化                                            *\n"); 
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 5:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      销售记录管理                                           *\n");
	    	printf("\t*                                      销售账单记录                                           *\n");
	    	printf("\t*                                      员工信息管理                                           *\n");
            printf("\t*                                      开发人员介绍                                           *\n");
            myColor(7,1);
            printf("\t*                                       系统初始化                                            *\n");
            myColor(11,0);
            printf("\t*                                       返回上一级                                            *\n");
            //myColor(3,0); 
		};break;
		case 6:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      销售记录管理                                           *\n");
	    	printf("\t*                                      销售账单记录                                           *\n");
	    	printf("\t*                                      员工信息管理                                           *\n");
            printf("\t*                                      开发人员介绍                                           *\n");
            printf("\t*                                       系统初始化                                            *\n");
            myColor(7,1);
            printf("\t*                                       返回上一级                                            *\n");
            myColor(3,0); 
		};break;
	}
}

void show_productmenu(int location_productmenu){
	gotoCoordinate(0,0); 
	//Rabit();
	Rabit();
	switch(location_productmenu){
		case 0:{
			myColor(7,1);
			printf("\t*                                      商品信息管理                                           *\n");
			myColor(11,0);
			printf("\t*                                      商品信息添加                                           *\n");
            printf("\t*                                      商品信息删减                                           *\n");
            printf("\t*                                      商品信息查找                                           *\n");
            printf("\t*                                      商品信息修改                                           *\n");
            printf("\t*                                      商品价格排序                                           *\n");
            printf("\t*                                      商品信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 1:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			myColor(7,1);
			printf("\t*                                      商品信息添加                                           *\n");
			myColor(11,0);
			printf("\t*                                      商品信息删减                                           *\n");
            printf("\t*                                      商品信息查找                                           *\n");
            printf("\t*                                      商品信息修改                                           *\n");
            printf("\t*                                      商品价格排序                                           *\n");
            printf("\t*                                      商品信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 2:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      商品信息添加                                           *\n");
			myColor(7,1);
			printf("\t*                                      商品信息删减                                           *\n");
			myColor(11,0);
            printf("\t*                                      商品信息查找                                           *\n");
            printf("\t*                                      商品信息修改                                           *\n");
            printf("\t*                                      商品价格排序                                           *\n");
            printf("\t*                                      商品信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 3:{
			myColor(11,0);
		    printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      商品信息添加                                           *\n");
			printf("\t*                                      商品信息删减                                           *\n");
			myColor(7,1); 
            printf("\t*                                      商品信息查找                                           *\n");
            myColor(11,0);
            printf("\t*                                      商品信息修改                                           *\n");
            printf("\t*                                      商品价格排序                                           *\n");
            printf("\t*                                      商品信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break; 
		case 4:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      商品信息添加                                           *\n");
			printf("\t*                                      商品信息删减                                           *\n");
			printf("\t*                                      商品信息查找                                           *\n");
			myColor(7,1);
			printf("\t*                                      商品信息修改                                           *\n");
		    myColor(11,0);	
		    printf("\t*                                      商品价格排序                                           *\n");
            printf("\t*                                      商品信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 5:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      商品信息添加                                           *\n");
			printf("\t*                                      商品信息删减                                           *\n");
			printf("\t*                                      商品信息查找                                           *\n");
			printf("\t*                                      商品信息修改                                           *\n");
			myColor(7,1);
			printf("\t*                                      商品价格排序                                           *\n");
			myColor(11,0);
			printf("\t*                                      商品信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		}break;
		case 6:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      商品信息添加                                           *\n");
			printf("\t*                                      商品信息删减                                           *\n");
			printf("\t*                                      商品信息查找                                           *\n");
			printf("\t*                                      商品信息修改                                           *\n");
			printf("\t*                                      商品价格排序                                           *\n");
			myColor(7,1);
			printf("\t*                                      商品信息输出                                           *\n");
			myColor(11,0);
			printf("\t*                                       返回上一级                                            *\n");
		}break;
		case 7:{
			myColor(11,0);
			printf("\t*                                      商品信息管理                                           *\n");
			printf("\t*                                      商品信息添加                                           *\n");
			printf("\t*                                      商品信息删减                                           *\n");
			printf("\t*                                      商品信息查找                                           *\n");
			printf("\t*                                      商品信息修改                                           *\n");
			printf("\t*                                      商品价格排序                                           *\n");
			printf("\t*                                      商品信息输出                                           *\n");
			myColor(7,1);
			printf("\t*                                       返回上一级                                            *\n");
			myColor(3,0); 
		}break;
	}
}

void show_billsmenu(int location_billsmenu){
	gotoCoordinate(0,0); 
	//Rabit();
	Rabit();
	switch(location_billsmenu){
		case 0:{
			myColor(7,1);
			printf("\t*                                    每日商店销售总价                                         *\n");
			myColor(11,0);
			printf("\t*                                    顾客购买账单记录                                         *\n");
            printf("\t*                                    打印顾客账单记录                                         *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 1:{
			myColor(11,0);
			printf("\t*                                    每日商店销售总价                                         *\n");	
			myColor(7,1);
			printf("\t*                                    顾客购买账单记录                                         *\n");
			myColor(11,0);
			printf("\t*                                    打印顾客账单记录                                         *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 2:{
			myColor(11,0);
			printf("\t*                                    每日商店销售总价                                         *\n");	
			printf("\t*                                    顾客购买账单记录                                         *\n");
			myColor(7,1);
			printf("\t*                                    打印顾客账单记录                                         *\n");
			myColor(11,0);
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 3:{
			myColor(11,0);
			printf("\t*                                    每日商店销售总价                                         *\n");	
			printf("\t*                                    顾客购买账单记录                                         *\n");
			printf("\t*                                    打印顾客账单记录                                         *\n");
			myColor(7,1);
            printf("\t*                                       返回上一级                                            *\n");
            myColor(3,0); 
		};break;
	}
}

void show_salesmenu(int location_salesmenu){
	gotoCoordinate(0,0); 
	//Rabit(); 
	Rabit();
	switch(location_salesmenu){
		case 0:{
			myColor(7,1);
			printf("\t*                                    每日商品销售记录                                         *\n");
			myColor(11,0);
			printf("\t*                                    每日销售记录输出                                         *\n");
            printf("\t*                                    清除每日销售记录                                         *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 1:{
			myColor(11,0);
			printf("\t*                                    每日商品销售记录                                         *\n");	
			myColor(7,1);
			printf("\t*                                    每日销售记录输出                                         *\n");
			myColor(11,0);
			printf("\t*                                    清除每日销售记录                                         *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 2:{
			myColor(11,0);
			printf("\t*                                    每日商品销售记录                                         *\n");	
			printf("\t*                                    每日销售记录输出                                         *\n");
			myColor(7,1);
			printf("\t*                                    清除每日销售记录                                         *\n");
			myColor(11,0);
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 3:{
			myColor(11,0);
			printf("\t*                                    每日商品销售记录                                         *\n");	
			printf("\t*                                    每日销售记录输出                                         *\n");
			printf("\t*                                    清除每日销售记录                                         *\n");
			myColor(7,1);
            printf("\t*                                       返回上一级                                            *\n");
            myColor(3,0); 
		};break;
	}
}

/*启动项*/ 
void begin(){
	//system("color 0A");
	int flag=0;
	while(1){
		show_mainmenu(location_mainmenu);
		if(getLocationKey(&location_mainmenu,6)){
			switch(location_mainmenu){
				case 0: system("cls");productmenu();break;
				case 1: system("cls");salesmenu();break;
				case 2: system("cls");billsmenu();break;
				case 3: employeesmenu();break;
				case 4: system("cls");intropeople();break; 
				case 5: system("cls");recover();break; 
				case 6: system("cls");flag=1;break;
			}
		}
		if(flag)
			break;
	}
}

/*商品管理菜单*/ 
void productmenu(){
	int flag=0;
    while(1){
    	show_productmenu(location_productmenu); 
    	if(getLocationKey(&location_productmenu,7)){
    		switch(location_productmenu){
    			case 0: system("cls");input();break;
    	        case 1: system("cls");add();break;
    	        case 2: system("cls");dele();break;
    	        case 3: system("cls");find();break;
    	        case 4: system("cls");modify();break;
    	        case 5: system("cls");sort();break;
    	        case 6: system("cls");output();break;
    	        case 7: system("cls");flag=1;break;
			}
		}
		if(flag)
			break;
    }
}

/*账单菜单*/ 
void billsmenu(){	
	int flag=0;
	while(1){
		show_billsmenu(location_billsmenu); 
		if(getLocationKey(&location_billsmenu,3)){
			switch(location_billsmenu){
		        case 0: system("cls");daily_price();break;
		        case 1: system("cls");bill();break;
		        case 2: system("cls");print_bill();break;
			    case 3: system("cls");flag=1;break;	
	        }
		}
	    if(flag)
			break;
    }
}

/*销售记录菜单*/ 
void salesmenu(){
	int flag=0;
	while(1){
		show_salesmenu(location_salesmenu); 
        if(getLocationKey(&location_salesmenu,3)){
            switch(location_salesmenu){
            	case 0: system("cls");record();break;
            	case 1: system("cls");output_record();break;
    	        case 2: system("cls");remove_record();break;
            	case 3: system("cls");flag=1;break;
            }
        }
        if(flag)
			break;
    }
}

/*开发人员信息*/
void intropeople()
{
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    printf("\t***********************************************************************************************\n");
    printf("\t*                                                                                             *\n");
    printf("\t*                                      开发人员信息                                           *\n");
    printf("\t*                                                                                             *\n");
    printf("\t*                      自控1701 封尚武                                                        *\n");
    printf("\t*                                                                                             *\n");
    printf("\t*                      自控1704 胡潇                                                          *\n");
    printf("\t*                                                                                             *\n");
    printf("\t***********************************************************************************************\n");
	getch();
	system("cls");
	begin();
} 

/*系统初始化*/
void recover(){
	char ch[20]; 
    FILE *fp; 
    int i; 
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	while(1){
		printf("\n 你确定要初始化吗？(y/n): "); 
        scanf("%s",ch); 
        if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
            fp=fopen("record.txt","wb");
            fclose(fp);
            fp=fopen("student.txt","wb");
            fclose(fp);
            day=0;
            count=0;
	        for(i=0;i<20;i++)
	            date[i]='\0'; 
	        break; 
        } 
        else if(strcmp(ch,"n")==0||strcmp(ch,"N")==0)
            break;
        else
            printf("\n 输入错误！\n"); 
	}
    printf("\n 点击任意键进入启动菜单 ");
    getch(); 
    system("cls"); 
    begin(); 
} 

/*获取当前时间*/ 
void put_date(){
	time_t t;
	int i;
	char q[20];
    struct tm *p;
    time(&t);
    p=localtime(&t);
    i=1900+p->tm_year;
    itoa(i,date,10);
    strcat(date,"-");
    i=1+p->tm_mon;
    itoa(i,q,10);
    strcat(date,q);
    strcat(date,"-");
    i=p->tm_mday;
    itoa(i,q,10);
    strcat(date,q);
    strcat(date," ");
    i=p->tm_hour;
    itoa(i,q,10);
    strcat(date,q);
    strcat(date,":");
    i=p->tm_min;
    itoa(i,q,10);
    strcat(date,q);
    strcat(date,":");
    i=p->tm_sec;
    itoa(i,q,10);
    strcat(date,q);
}   

/*每日销售记录*/
void record(){
	char flag[20];
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	printf("是否更新每日销售记录？(y/n)：");
	scanf("%s",flag);
	if(strcmp(flag,"y")==0||strcmp(flag,"Y")==0){
	    FILE *fp; 
	    struct daily_sales_record pa;
        int i,m=0; 
        fp=fopen("student.txt","rb"); 
        while(fread(&product[m],sizeof(struct marketproduct),1,fp)!=NULL) 
            m++; 
        fclose(fp); 
        fp=fopen("record.txt","rb+");
        while(fread(&pa,sizeof(struct daily_sales_record),1,fp)!=NULL)
	        if(pa.day_record>=day){       
	        	day=pa.day_record;
	        	day++; 
	    	} 
        for(i=0;i<m;i++){
        	sales_record[i].sales_number=product[i].product_amount-product[i].product_remain; 
        	sales_record[i].day_record=day;
        	memcpy(sales_record[i].product_id,product[i].product_id,sizeof(product[i].product_id));
        	memcpy(sales_record[i].product_name,product[i].product_name,sizeof(product[i].product_name));
        	sales_record[i].total_price=sales_record[i].sales_number*product[i].product_price*(1-product[i].product_discount);
    	}
    	fwrite(&sales_record,sizeof(struct daily_sales_record),m,fp); 
    	fclose(fp);
    	day++;
    	output_record(); 
	}
	getch(); 
    system("cls"); 
    begin();  
} 

/*销售记录输出*/ 
void output_record(){ 
    FILE *fp; 
    struct daily_sales_record pa;
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("record.txt","rb"); 
    printf(" 编号 名称 销售量 销售总价 天数 \n"); 
    while(fread(&pa,sizeof(struct daily_sales_record),1,fp)!=NULL) 
        printf("  %s    %s %5d    %.2lf %5d \n",pa.product_id,pa.product_name,pa.sales_number,pa.total_price,pa.day_record); 
    getch(); 
    system("cls"); 
    begin();  
}  

/*删除每日销售记录*/
void remove_record(){
	char ch[20]; 
    FILE *fp; 
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    printf("\n 你确定要清除每日销售记录吗？(y/n): "); 
    scanf("%s",ch); 
    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
        fp=fopen("record.txt","wb");
        fclose(fp);
    } 
    day=0;
    printf("\n 点击任意键进入启动菜单 ");
    getch(); 
    system("cls"); 
    begin(); 
} 
 
/*顾客账单记录*/ 
void bill(){
	FILE *fp; 
	char number[20]="\0";
	struct bill_adults pa; 
	int i,j=0,k,n;
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	printf("输入商品的种类数：");
	scanf("%d",&n); 
	fp=fopen("student.txt","rb");
	while(fread(&product[j],sizeof(struct marketproduct),1,fp)!=NULL)
	    j++;
	fclose(fp);
	for(i=0;i<n;i++){
		printf("输入商品的id：");
		scanf("%s",&product_record[i].product_id);
		for(k=0;k<j;k++)
			if(strcmp(product[k].product_id,product_record[i].product_id)==0){
				memcpy(product_record[i].product_name,product[k].product_name,sizeof(product[k].product_name));
				break;
			}
		printf("输入商品的数量：");
		scanf("%d",&product_record[i].product_number);  
		product[k].product_remain=product[k].product_remain-product_record[i].product_number; 
		product_record[i].total_price=product_record[i].product_number*product[k].product_price*(1-product[k].product_discount);
	}
	printf("输入开账单人员姓名：");
	scanf("%s",&pa.employee_name); 
	put_date(); 
	strcpy(pa.time,date); 
	pa.total_product_price=0;
	for(i=0;i<n;i++)
	    pa.total_product_price=product_record[i].total_price+pa.total_product_price;
	printf("商品id  商品名称  商品的数量  单种商品的总价\n");
	for(i=0;i<n;i++)
	    printf("  %s       %s  %9d            %.2lf\n",product_record[i].product_id,product_record[i].product_name,product_record[i].product_number,product_record[i].total_price); 
	printf("开账人员：%s  时间：%s  总价：%.2lf",pa.employee_name,pa.time,pa.total_product_price);
	printf("\n请输入账单编号：");
	fflush(stdin);
	gets(number); 
	fp=fopen(strcat(number,".txt"),"wb+"); 
	fwrite(&product_record,sizeof(struct bill_product),n,fp); 
	fwrite(&pa,sizeof(struct bill_adults),1,fp);
	fclose(fp);
	fp=fopen("student.txt","rb+");
	fwrite(&product,sizeof(struct marketproduct),j,fp); 
	fclose(fp);
	getch(); 
    system("cls"); 
    begin(); 
}

/*打印顾客账单*/ 
void print_bill(){
	FILE *fp;
	char number[20]="\0";
	int i,j=0,k;
	struct bill_adults pa;
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	printf("输入账单编号：");
	fflush(stdin);
	gets(number); 
	fp=fopen(strcat(number,".txt"),"rb+"); 
	while(fread(&product_record[j],sizeof(struct bill_product),1,fp)!=NULL) 
        j++;
    fseek(fp,j*sizeof(struct bill_product),SEEK_SET);
    fread(&pa,sizeof(struct bill_adults),1,fp); 
    printf("商品id  商品名称  商品的数量  单种商品的总价\n");
    for(i=0;i<j;i++)
	    printf("  %s       %s  %9d            %.2lf\n",product_record[i].product_id,product_record[i].product_name,product_record[i].product_number,product_record[i].total_price); 
	printf("\n开账人员：%s  时间：%s  总价：%.2lf",pa.employee_name,pa.time,pa.total_product_price);
	fclose(fp);
	getch(); 
    system("cls"); 
    begin(); 
}

/*每日销售总价*/
void daily_price(){
	FILE *fp; 
	int day=0;
	struct daily_sales_record pa;
	double daily_total_price=0;
	fp=fopen("record.txt","rb+");
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	printf("天数  单日销售总价\n"); 
    while(fread(&pa,sizeof(struct daily_sales_record),1,fp)!=NULL){
    	if(pa.day_record >day){
    		printf(" %d     %.2lf\n",pa.day_record-1,daily_total_price);
    		day++; 
    		daily_total_price=0;
    		daily_total_price=pa.total_price+daily_total_price;
		}	
		else
			daily_total_price=pa.total_price+daily_total_price;	    
	} 
	printf(" %d     %.2lf\n",pa.day_record,daily_total_price);
	fclose(fp);
	getch(); 
    system("cls"); 
    begin(); 
}

/*商品信息输出*/
void output(){ 
    FILE *fp; 
    int i,j=0; 
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("student.txt","rb"); 
    while(fread(&product[j],sizeof(struct marketproduct),1,fp)!=NULL) 
        j++; 
	fclose(fp); 
    printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
    for(i=0;i<j;i++) 
        printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	getch();
    system("cls"); 
    begin(); 
} 

/*商品信息输入*/
void input(){ 
    FILE *fp; 
    char flag[20]; 
    char ch; 
    int i,j;
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("student.txt","wb"); 
    count=0; 
    do{ 
        printf(" 请输入你的商品信息 :\n"); 
        while(1){
        	j=0;
        	printf(" 商品编号 :"); 
        	scanf("%s",product[count].product_id);
			if(!count) 
			    break;
			else{
				for(i=0;i<count;i++)
        	        if(strcmp(product[count].product_id,product[i].product_id)==0){
        	    	    printf(" 重复id！请再次输入！\n");
        	    	    j=1;
        	    	    break; 
				    } 
			} 
			if(!j)
			    break;
		} 
        printf(" 商品名字 :"); 
        scanf("%s",product[count].product_name); 
        printf(" 商品价格 :"); 
        scanf("%lf",&product[count].product_price); 
        printf(" 商品折扣 :"); 
        scanf("%lf",&product[count].product_discount); 
        printf(" 商品总数目 :"); 
        scanf("%d",&product[count].product_amount); 
        printf(" 商品剩余数目 :"); 
        scanf("%d",&product[count].product_remain); 
        count++;
        printf(" 你是否还想继续输入数据？ (y/n) : "); 
        scanf("%s",flag); 
    }while(strcmp(flag,"y")==0||strcmp(flag,"Y")==0); 
    fwrite(&product,sizeof(struct marketproduct),count,fp); 
    fclose(fp); 
    system("cls"); 
    output(); 
    getch(); 
    system("cls"); 
    begin(); 
} 

/*商品信息添加*/ 
void add(){
	FILE *fp; 
	char flag[20];
	int i=0,j,k; 
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	fp=fopen("student.txt","rb+"); 
	struct marketproduct pa;
	while(fread(&product[i],sizeof(struct marketproduct),1,fp)!=NULL)
	    i++;
	do{ 
        printf(" 请输入你的商品信息 :\n");        
        while(1){
        	k=0;
        	printf(" 商品编号 :"); 
        	scanf("%s",product[i].product_id);
			if(!i) 
			    break;
			else{
				for(j=0;j<i;j++)
        	        if(strcmp(product[i].product_id,product[j].product_id)==0){
        	    	    printf(" 重复id！请再次输入！\n");
        	    	    k=1;
        	    	    break; 
				    }  
			} 
			if(!k)
			    break;
		} 
        printf(" 商品名字 :"); 
        scanf("%s",product[i].product_name); 
        printf(" 商品价格 :"); 
        scanf("%lf",&product[i].product_price); 
        printf(" 商品折扣 :"); 
        scanf("%lf",&product[i].product_discount); 
        printf(" 商品总数目 :"); 
        scanf("%d",&product[i].product_amount); 
        printf(" 商品剩余数目 :"); 
        scanf("%d",&product[i].product_remain); 
        i++;
        printf(" 你是否还想继续输入数据？ (y/n) : "); 
        scanf("%s",flag); 
    }while(strcmp(flag,"y")==0||strcmp(flag,"Y")==0); 
    rewind(fp);
	fwrite(&product,sizeof(struct marketproduct),i,fp); 
	count=i; 
    fclose(fp);
	system("cls"); 
    output(); 
    getch(); 
    system("cls"); 
    begin(); 
}

/*商品信息删除 */ 
void dele(){ 
    FILE *fp; 
    int i,j,k=0,u; 
    char c[20];  
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("student.txt","rb"); 
    while(fread(&product[k],sizeof(struct marketproduct),1,fp)!=NULL)
        k++; 
    count=k;
    fclose(fp); 
    while(1){
    	u=0;
    	printf("\n 输入你想要删除的商品id ："); 
        scanf("%s",c);  
        for(i=0;i<count;i++)
            if(strcmp(c,product[i].product_id)==0) 
                break; 
        if(i==count)
        	printf("未找到！"); 
        else{
        	u=1;
        	for(j=i;j<count-1;j++) 
            product[j]=product[j+1]; 
            printf("\n 你已经删除商品id--%s\n",c); 
            getch();
            count--; 
            fp=fopen("student.txt","wb"); 
            fwrite(&product,sizeof(struct marketproduct),count,fp); 
            fclose(fp); 
            system("cls"); 
            output(); 
		}
        if(u)
		    break; 
	}
    getch(); 
    system("cls"); 
    begin(); 
} 

/*商品信息修改 */ 
void modify(){ 
    FILE *fp; 
    int i,j=0,k; 
    char ch[20],a[20];
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);  
    fp=fopen("student.txt","rb+"); 
    while(fread(&product[j],sizeof(struct marketproduct),1,fp)!=NULL) 
        j++; 
    printf("\n 你确定要更改商品吗？ (y/n): ");  
    scanf("%s",ch); 
    while(1){
    	k=0;
    	if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){  
            printf("\n 输入你想要更改的商品id："); 
            scanf("%s",a); 
            for(i=0;i<j;i++){ 
                if(strcmp(product[i].product_id,a)==0){ 
                    k=1; 
                    printf("\n 你想要更改商品的名字吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n name:"); 
                        scanf("%s",&product[i].product_name); 
                    } 
                    printf("\n 你想要更改商品价格吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n price:"); 
                        scanf("%lf",&product[i].product_price); 
                    } 
                    printf("\n 你想要更改折扣吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n discount:"); 
                        scanf("%lf",&product[i].product_discount); 
                    } 
                    printf("\n 你想要的更改总量吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n amount:"); 
                        scanf("%d",&product[i].product_amount); 
                    } 
                    printf("\n 你想要更改剩余量吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n remain:"); 
                        scanf("%d",&product[i].product_remain); 
                    } 
                } 
            } 
            if(!k)
                printf("\n 未找到该商品id！"); 
        } 
        if(k)
		    break;
	} 
    rewind(fp);
    printf("%d",j);
    fwrite(&product,sizeof(struct marketproduct),j,fp); 
    fclose(fp); 
    system("cls"); 
    output(); 
    getch(); 
    system("cls"); 
    begin(); 
} 

/*商品信息查找*/ 
void find(){ 
    FILE *fp; 
    int i,j=0,u=0; 
    char a[20]; 
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("student.txt","rb"); 
    while(fread(&product[j],sizeof(struct marketproduct),1,fp)!=NULL)
        j++; 
    printf("\n 输入需要查找的商品名字:"); 
    scanf("%s",a); 
    system("cls");
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    for(i=0;i<j;i++){ 
        if(strcmp(product[i].product_name,a)==0){
        	printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n");
			printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
			u=1; 
		} 
    } 
    if(!u)
	    printf("未找到！\n"); 
    getch(); 
    system("cls"); 
    begin(); 
} 

/*商品价格排序*/ 
void sort() 
{ 
    FILE *fp; 
    int m=0,i,j,k,u;
    char flag[20]; 
    struct marketproduct pa;
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("student.txt","rb"); 
    while(fread(&product[m],sizeof(struct marketproduct),1,fp)!=NULL) 
        m++; 
    fclose(fp); 
    fflush(stdin);
    while(1){
    	u=0;
    	printf("选择排序变量 0.price 1.discount 2.amount：");
        scanf("%d",&k);
    	switch(k){
    		case 0:{
                        printf("请输入排序方式(y：升序 n：降序)："); 
                        scanf("%s",&flag); 
                        if(strcmp(flag,"y")==0||strcmp(flag,"Y")==0){
    	                    for(i=0;i<m-1;i++) 
                                for(j=0;j<m-1-j;j++) 
                                    if(product[j].product_price>product[j+1].product_price){ 
                                        pa=product[j]; 
                                        product[j]=product[j+1]; 
                                        product[j+1]=pa; 
                                    } 
                            printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
                            for(i=0;i<m;i++) 
                            printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	                    }
	                    else{
    	                    for(i=0;i<m-1;i++) 
                                for(j=0;j<m-1-j;j++) 
                                    if(product[j].product_price<product[j+1].product_price){ 
                                        pa=product[j]; 
                                        product[j]=product[j+1]; 
                                        product[j+1]=pa; 
                                    } 
                            printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
                            for(i=0;i<m;i++) 
                                printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	                        }
	                    u=1;
			       };break;
		    case 1:{
		    	        printf("请输入排序方式(y：升序 n：降序)："); 
                        scanf("%s",&flag); 
                        if(strcmp(flag,"y")==0||strcmp(flag,"Y")==0){
    	                    for(i=0;i<m-1;i++) 
                                for(j=0;j<m-1-j;j++) 
                                    if(product[j].product_discount>product[j+1].product_discount){ 
                                        pa=product[j]; 
                                        product[j]=product[j+1]; 
                                        product[j+1]=pa; 
                                    } 
                            printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
                            for(i=0;i<m;i++) 
                            printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	                    }
	                    else{
    	                    for(i=0;i<m-1;i++) 
                                for(j=0;j<m-1-j;j++) 
                                    if(product[j].product_discount<product[j+1].product_discount){ 
                                        pa=product[j]; 
                                        product[j]=product[j+1]; 
                                        product[j+1]=pa; 
                                    } 
                            printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
                            for(i=0;i<m;i++) 
                                printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	                        }
	                    u=1; 
	                };break;
			case 2:{
				        printf("请输入排序方式(y：升序 n：降序)："); 
                        scanf("%s",&flag); 
                        if(strcmp(flag,"y")==0||strcmp(flag,"Y")==0){
    	                    for(i=0;i<m-1;i++) 
                                for(j=0;j<m-1-j;j++) 
                                    if(product[j].product_amount>product[j+1].product_amount){ 
                                        pa=product[j]; 
                                        product[j]=product[j+1]; 
                                        product[j+1]=pa; 
                                    } 
                            printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
                            for(i=0;i<m;i++) 
                            printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	                    }
	                    else{
    	                    for(i=0;i<m-1;i++) 
                                for(j=0;j<m-1-j;j++) 
                                    if(product[j].product_amount<product[j+1].product_amount){ 
                                        pa=product[j]; 
                                        product[j]=product[j+1]; 
                                        product[j+1]=pa; 
                                    } 
                            printf(" 编号 名称 价格 折扣 总数目 剩余数目 \n"); 
                            for(i=0;i<m;i++) 
                                printf("  %s   %s  %.2lf %.2lf %4d %6d \n",product[i].product_id,product[i].product_name,product[i].product_price,product[i].product_discount,product[i].product_amount,product[i].product_remain); 
	                        }
	                    u=1;
			       };break;
		    default:{
                        printf("输入错误！\n");
		        	};break;	       
        }
        if(u)
	       break;
	}
    getch();
    system("cls"); 
    begin(); 
}


//隐藏光标
void hideCursor(){
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

/*
int getLocationKey(int *location,int n){//72为按键 ↑，80为按键 ↓ 
	int ch;
	ch=getch();
	if(ch==72)
		(*location)--;
	else if(ch==80)
		(*location)++;
	else if(ch==13)              
		return 1;
	if(*location<0)
		(*location)=0;
	if(*location>n)
		(*location)=n;
	return 0; 
}
*/ 
