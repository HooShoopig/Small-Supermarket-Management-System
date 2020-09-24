#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
#include <ctime>
#include<time.h>
#include<windows.h>
#include<algorithm>
#define employees_COUNT 30  //员工上限 

int employees_count;

void employees_input();
void employees_add();
void employees_dele();
void employees_find();
void employees_modify();
void employees_sort();
void employees_output();
void gotoCoordinate(int,int);
void static_logoprint();
void myColor(int,int); 
void Rabit();
void begin(); 
void employeesmenu();
int location_employeesmenu; 
void employeesmenu();
void show_employeesmenu(int);
int getLocationKey(int *location,int n); 


/*存放员工数据的结构体*/
struct employees_information{  
    char   employees_id[20];        /*员工编号*/ 
    char   employees_name[20];      /*员工名字*/ 
    char   employees_gender[20];    /*员工性别*/ 
    int    employees_age;           /*员工年龄*/ 
    double employees_wage;          /*员工工资*/ 
}employees[employees_COUNT];


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

//int main(){
//	begin();
//	return 0;
//}

/* 
void begin(){
	myColor(11,0);
	fflush(stdin);
	int flag=0;
	printf("\t*                                      员工信息输入                                           *\n");
	printf("\t*                                      员工信息添加                                           *\n"); 
	printf("\t*                                      员工信息删减                                           *\n");
	printf("\t*                                      员工信息查找                                           *\n");
	printf("\t*                                      员工信息删减                                           *\n");
	printf("\t*                                      员工信息排序                                           *\n");
	printf("\t*                                      员工信息输出                                           *\n"); 
	printf("输入选项：\n"); 
	scanf("%d",&flag); 
	//while(1){
	//	show_mainmenu(location_mainmenu);
	//	if(getLocationKey(&location_mainmenu,5)){
			switch(flag){
				case 0: system("cls");employees_input();break;
				case 1: system("cls");employees_add();break;
				case 2: system("cls");employees_dele();break;
				case 3: system("cls");employees_find();break; 
				case 4: system("cls");employees_modify();break; 
				case 5: system("cls");employees_sort();break;
				case 6: system("cls");employees_output();break;
			}
	//	}
//		if(flag)
//			break;
//	}
}
*/

/*商品管理菜单*/ 
void employeesmenu(){
	int employees_flag=0;
    while(1){
    	show_employeesmenu(location_employeesmenu); 
    	if(getLocationKey(&location_employeesmenu,7)){
    		switch(location_employeesmenu){
    			case 0: system("cls");employees_input();break;
    	        case 1: system("cls");employees_add();break;
    	        case 2: system("cls");employees_dele();break;
    	        case 3: system("cls");employees_find();break;
    	        case 4: system("cls");employees_modify();break;
    	        case 5: system("cls");employees_sort();break;
    	        case 6: system("cls");employees_output();break;
    	        case 7: system("cls");employees_flag=1;break;
			}
		}
		if(employees_flag)
			break;
    }
}

void show_employeesmenu(int location_employeesmenu){
	gotoCoordinate(0,0); 
	Rabit();
	switch(location_employeesmenu){
		case 0:{
			myColor(7,1);
			printf("\t*                                      员工信息输入                                           *\n");
			myColor(11,0);
			printf("\t*                                      员工信息添加                                           *\n");
            printf("\t*                                      员工信息删减                                           *\n");
            printf("\t*                                      员工信息查找                                           *\n");
            printf("\t*                                      员工信息修改                                           *\n");
            printf("\t*                                      员工信息排序                                           *\n");
            printf("\t*                                      员工信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 1:{
			myColor(11,0);
			printf("\t*                                      员工信息输入                                           *\n");
			myColor(7,1);
			printf("\t*                                      员工信息添加                                           *\n");
			myColor(11,0);
			printf("\t*                                      员工信息删减                                           *\n");
            printf("\t*                                      员工信息查找                                           *\n");
            printf("\t*                                      员工信息修改                                           *\n");
            printf("\t*                                      员工信息排序                                           *\n");
            printf("\t*                                      员工信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 2:{
			myColor(11,0);
			printf("\t*                                      员工信息输入                                           *\n");
			printf("\t*                                      员工信息添加                                           *\n");
			myColor(7,1);
			printf("\t*                                      员工信息删减                                           *\n");
			myColor(11,0);
            printf("\t*                                      员工信息查找                                           *\n");
            printf("\t*                                      员工信息修改                                           *\n");
            printf("\t*                                      员工信息排序                                           *\n");
            printf("\t*                                      员工信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 3:{
			myColor(11,0);
		    printf("\t*                                      员工信息输入                                           *\n");
			printf("\t*                                      员工信息添加                                           *\n");
			printf("\t*                                      员工信息删减                                           *\n");
			myColor(7,1); 
            printf("\t*                                      员工信息查找                                           *\n");
            myColor(11,0);
            printf("\t*                                      员工信息修改                                           *\n");
            printf("\t*                                      员工信息排序                                           *\n");
            printf("\t*                                      员工信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break; 
		case 4:{
			myColor(11,0);
			printf("\t*                                      员工信息输入                                           *\n");
			printf("\t*                                      员工信息添加                                           *\n");
			printf("\t*                                      员工信息删减                                           *\n");
			printf("\t*                                      员工信息查找                                           *\n");
			myColor(7,1);
			printf("\t*                                      员工信息修改                                           *\n");
		    myColor(11,0);	
		    printf("\t*                                      员工信息排序                                           *\n");
            printf("\t*                                      员工信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		};break;
		case 5:{
			myColor(11,0);
			printf("\t*                                      员工信息输入                                           *\n");
			printf("\t*                                      员工信息添加                                           *\n");
			printf("\t*                                      员工信息删减                                           *\n");
			printf("\t*                                      员工信息查找                                           *\n");
			printf("\t*                                      员工信息修改                                           *\n");
			myColor(7,1);
			printf("\t*                                      员工信息排序                                           *\n");
			myColor(11,0);
			printf("\t*                                      员工信息输出                                           *\n");
            printf("\t*                                       返回上一级                                            *\n");
		}break;
		case 6:{
			myColor(11,0);
			printf("\t*                                      员工信息输入                                           *\n");
			printf("\t*                                      员工信息添加                                           *\n");
			printf("\t*                                      员工信息删减                                           *\n");
			printf("\t*                                      员工信息查找                                           *\n");
			printf("\t*                                      员工信息修改                                           *\n");
			printf("\t*                                      员工信息排序                                           *\n");
			myColor(7,1);
			printf("\t*                                      员工信息输出                                           *\n");
			myColor(11,0);
			printf("\t*                                       返回上一级                                            *\n");
		}break;
		case 7:{
			myColor(11,0);
			printf("\t*                                      员工信息输入                                           *\n");
			printf("\t*                                      员工信息添加                                           *\n");
			printf("\t*                                      员工信息删减                                           *\n");
			printf("\t*                                      员工信息查找                                           *\n");
			printf("\t*                                      员工信息修改                                           *\n");
			printf("\t*                                      员工信息排序                                           *\n");
			printf("\t*                                      员工信息输出                                           *\n");
			myColor(7,1);
			printf("\t*                                       返回上一级                                            *\n");
			myColor(3,0); 
		}break;
	}
}

/*员工信息输入*/
void employees_input(){
	FILE *fp; 
    char flag[20]; 
    char ch; 
    int i,j;
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("employees.txt","wb"); 
    employees_count=0; 
    do{ 
        printf(" 请输入员工信息 :\n"); 
        while(1){
        	j=0;
        	printf(" 员工编号 :"); 
        	scanf("%s",employees[employees_count].employees_id);
			if(!employees_count) 
			    break;
			else{
				for(i=0;i<employees_count;i++)
        	        if(strcmp(employees[employees_count].employees_id,employees[i].employees_id)==0){
        	    	    printf(" 重复id！请再次输入！\n");
        	    	    j=1;
        	    	    break; 
				    } 
			} 
			if(!j)
			    break;
		} 
        printf(" 员工名字 :"); 
        scanf("%s",employees[employees_count].employees_name); 
        printf(" 员工性别 :"); 
        scanf("%s",&employees[employees_count].employees_gender); 
        printf(" 员工年龄 :"); 
        scanf("%d",&employees[employees_count].employees_age); 
        printf(" 员工工资 :"); 
        scanf("%lf",&employees[employees_count].employees_wage); 
        employees_count++;
        printf(" 你是否还想继续输入数据？ (y/n) : "); 
        scanf("%s",flag); 
    }while(strcmp(flag,"y")==0||strcmp(flag,"Y")==0); 
    fwrite(&employees,sizeof(struct employees_information),employees_count,fp); 
    fclose(fp); 
    system("cls");
    employees_output(); 
}

/*员工信息添加*/
void employees_add(){
	FILE *fp; 
	char flag[20];
	int i=0,j,k; 
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
	fp=fopen("employees.txt","rb+"); 
	struct employees_information pa;
	while(fread(&employees[i],sizeof(struct employees_information),1,fp)!=NULL)
	    i++;
	do{ 
        printf(" 请输入员工信息 :\n");        
        while(1){
        	k=0;
        	printf(" 员工编号 :"); 
        	scanf("%s",employees[i].employees_id);
			if(!i) 
			    break;
			else{
				for(j=0;j<i;j++)
        	        if(strcmp(employees[i].employees_id,employees[j].employees_id)==0){
        	    	    printf(" 重复id！请再次输入！\n");
        	    	    k=1;
        	    	    break; 
				    }  
			} 
			if(!k)
			    break;
		} 
        printf(" 商品名字 :"); 
        scanf("%s",employees[i].employees_name); 
        printf(" 员工性别 :"); 
        scanf("%s",&employees[i].employees_gender); 
        printf(" 员工年龄 :"); 
        scanf("%d",&employees[i].employees_age); 
        printf(" 员工工资 :"); 
        scanf("%lf",&employees[i].employees_wage); 
        i++;
        printf(" 你是否还想继续输入数据？ (y/n) : "); 
        scanf("%s",flag); 
    }while(strcmp(flag,"y")==0||strcmp(flag,"Y")==0); 
    rewind(fp);
	fwrite(&employees,sizeof(struct employees_information),i,fp); 
	employees_count=i; 
    fclose(fp);
	system("cls"); 
    employees_output(); 
}

/*员工信息删除*/
void employees_dele(){
	FILE *fp; 
    int i,j,k=0,u; 
    char c[20];  
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("employees.txt","rb"); 
    while(fread(&employees[k],sizeof(struct employees_information),1,fp)!=NULL)
        k++; 
    employees_count=k;
    fclose(fp); 
    while(1){
    	u=0;
    	printf("\n 输入你想要删除的员工id ："); 
        scanf("%s",c);  
        for(i=0;i<employees_count;i++)
            if(strcmp(c,employees[i].employees_id)==0) 
                break; 
        if(i==employees_count)
        	printf("未找到！"); 
		else{
			u=1;
			for(j=i;j<employees_count-1;j++) 
                employees[j]=employees[j+1]; 
            printf("\n 你已经删除员工id--%s\n",c); 
            getch();
            employees_count--; 
            fp=fopen("employees.txt","wb"); 
            fwrite(&employees,sizeof(struct employees_information),employees_count,fp); 
            fclose(fp); 
            system("cls"); 
            employees_output();
		} 
		if(u)
		    break;   
	} 
    getch(); 
    system("cls"); 
    begin(); 
}

/*员工信息查找*/
void employees_find(){
	FILE *fp; 
    int i,j=0,u=0; 
    char a[20]; 
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("employees.txt","rb"); 
    while(fread(&employees[j],sizeof(struct employees_information),1,fp)!=NULL)
        j++; 
    printf("\n 输入需要查找的员工名字:"); 
    scanf("%s",a); 
    system("cls");
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0); 
    for(i=0;i<j;i++){ 
        if(strcmp(employees[i].employees_name,a)==0){
        	printf(" 编号 名字 性别 年龄 工资 \n"); 
        	printf("  %s   %s    %s  %4d %.2lf \n",employees[i].employees_id,employees[i].employees_name,employees[i].employees_gender,employees[i].employees_age,employees[i].employees_wage); 
		    u=1;
		} 
            
    } 
    if(!u)
	    printf("未找到！\n");  
    getch(); 
    system("cls"); 
    begin(); 
}

/*员工信息改变*/
void employees_modify(){
	FILE *fp; 
    int i,j=0,k; 
    char ch[20],a[20];
	gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);  
    fp=fopen("employees.txt","rb+"); 
    while(fread(&employees[j],sizeof(struct employees_information),1,fp)!=NULL) 
        j++; 
    printf("\n 你确定要更改员工信息吗？ (y/n): ");  
    scanf("%s",ch); 
    while(1){
    	k=0;
    	if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
            printf("\n 输入你想要更改的员工id："); 
            scanf("%s",a); 
            for(i=0;i<j;i++){ 
                if(strcmp(employees[i].employees_id,a)==0){ 
                    k=1;
                    printf("\n 你想要更改员工的名字吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n name:"); 
                        scanf("%s",&employees[i].employees_name); 
                    } 
                    printf("\n 你想要更改员工性别吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n gender:"); 
                        scanf("%s",&employees[i].employees_gender); 
                    } 
                    printf("\n 你想要更改员工年龄吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n age:"); 
                        scanf("%d",&employees[i].employees_age); 
                     } 
                    printf("\n 你想要的更改员工工资吗？(y/n): "); 
                    scanf("%s",ch); 
                    if(strcmp(ch,"y")==0||strcmp(ch,"Y")==0){ 
                        printf("\n wage:"); 
                        scanf("%lf",&employees[i].employees_wage); 
                    } 
                }
            } 
            if(!k)
                printf("\n 未找到该员工id！"); 
        } 
		if(k)
		    break;
	} 
    rewind(fp);
    fwrite(&employees,sizeof(struct employees_information),j,fp); 
    fclose(fp); 
    system("cls"); 
    employees_output(); 
    getch(); 
    system("cls"); 
    employees_output(); 
}

/*员工信息排序*/
void employees_sort(){
	FILE *fp; 
    int m=0; 
    int i,j,k,u;
    char flag[20]; 
    struct employees_information pa;
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("employees.txt","rb"); 
    while(fread(&employees[m],sizeof(struct employees_information),1,fp)!=NULL) 
        m++; 
    fclose(fp); 
    fflush(stdin);
    while(1){
    	u=0;
    	printf("选择排序变量 0.age 1.wage：");
    	scanf("%d",&k);
    	switch(k){
    	    case 0:
    		    {
    			    printf("请输入排序方式(y：升序 n：降序)："); 
                    scanf("%s",&flag); 
                    if(strcmp(flag,"y")==0||strcmp(flag,"Y")==0){
    	                for(i=0;i<m-1;i++) 
                            for(j=0;j<m-1-j;j++) 
                                if(employees[j].employees_age>employees[j+1].employees_age){ 
                                    pa=employees[j]; 
                                    employees[j]=employees[j+1]; 
                                    employees[j+1]=pa; 
                                } 
                        printf(" 编号 名字 性别 年龄 工资 \n");  
                        for(i=0;i<m;i++) 
                            printf("  %s   %s   %s %4d   %.2lf \n",employees[i].employees_id,employees[i].employees_name,employees[i].employees_gender,employees[i].employees_age,employees[i].employees_wage); 
	                }
	                else{
    	                for(i=0;i<m-1;i++) 
                            for(j=0;j<m-1-j;j++) 
                                if(employees[j].employees_age<employees[j+1].employees_age){ 
                                    pa=employees[j]; 
                                    employees[j]=employees[j+1]; 
                                    employees[j+1]=pa; 
                                } 
                        printf(" 编号 名字 性别 年龄 工资 \n"); 
                        for(i=0;i<m;i++) 
                            printf("  %s   %s   %s %4d   %.2lf \n",employees[i].employees_id,employees[i].employees_name,employees[i].employees_gender,employees[i].employees_age,employees[i].employees_wage); 
	                    }
	                u=1;
		    	};break;
		    case 1:
			    {
    			    printf("请输入排序方式(y：升序 n：降序)："); 
                    scanf("%s",&flag); 
                    if(strcmp(flag,"y")==0||strcmp(flag,"Y")==0){
    	                for(i=0;i<m-1;i++) 
                        for(j=0;j<m-1-j;j++) 
                        if(employees[j].employees_wage>employees[j+1].employees_wage){ 
                            pa=employees[j]; 
                            employees[j]=employees[j+1]; 
                            employees[j+1]=pa; 
                        } 
                    printf(" 编号 名字 性别 年龄 工资 \n");  
                    for(i=0;i<m;i++) 
                        printf("  %s   %s   %s %4d   %.2lf \n",employees[i].employees_id,employees[i].employees_name,employees[i].employees_gender,employees[i].employees_age,employees[i].employees_wage); 
	                }
	                else{
    	            for(i=0;i<m-1;i++) 
                        for(j=0;j<m-1-j;j++) 
                            if(employees[j].employees_wage<employees[j+1].employees_wage){ 
                                pa=employees[j]; 
                                employees[j]=employees[j+1]; 
                                employees[j+1]=pa; 
                            } 
                    printf(" 编号 名字 性别 年龄 工资 \n"); 
                    for(i=0;i<m;i++) 
                        printf("  %s   %s   %s %4d   %.2lf \n",employees[i].employees_id,employees[i].employees_name,employees[i].employees_gender,employees[i].employees_age,employees[i].employees_wage); 
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

/*员工信息输出*/
void employees_output(){
	FILE *fp; 
    int i,j=0; 
    gotoCoordinate(0,0); 
	Rabit();
	myColor(11,0);
    fp=fopen("employees.txt","rb"); 
    while(fread(&employees[j],sizeof(struct employees_information),1,fp)!=NULL) 
        j++; 
	fclose(fp); 
    printf(" 编号 名字 性别 年龄 工资 \n"); 
    for(i=0;i<j;i++) 
        printf("  %s   %s    %s  %4d %.2lf \n",employees[i].employees_id,employees[i].employees_name,employees[i].employees_gender,employees[i].employees_age,employees[i].employees_wage); 
	getch();
    system("cls"); 
    begin(); 
}

void gotoCoordinate(int x,int y){ 
	COORD pos;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}

void static_logoprint(){
	int i;
	myColor(10,0); 
	printf("\t _____________________________________________________________________________________________  \n");
	printf("\t│                                                                                            │\n");
	printf("\t│                                                                                            │\n");
	printf("\t│                       ******       *     *       ******      *******                       │\n");
	printf("\t│                       *     *      *     *      *               *                          │\n");
	printf("\t│                       ******       *     *      *               *                          │\n");
	printf("\t│                       *     *      *     *      *               *                          │\n");
	printf("\t│                       ******        *****        ******         *                          │\n");
	printf("\t│                                                                                            │\n");
	printf("\t│                                                                                            │\n");
	printf("\t│                  ******     *******     *******     ******      *******                    │\n");
	printf("\t│                 *              *        *     *     *     *     *                          │\n");
	printf("\t│                  *****         *        *     *     ******      *******                    │\n");
	printf("\t│                       *        *        *     *     *   *       *                          │\n");
	printf("\t│                 ******         *        *******     *    **     *******                    │\n");
	printf("\t│                                                                                            │\n");
	printf("\t│                                                                                            │\n");
	printf("\t│____________________________________________________________________________________________│\n");
	printf("\t                                                                                                \n");
	printf("\t                                     欢迎来到BUCT商店！                                         \n");
	printf("\t                                                                                                \n");
}

void Rabit()
{
	myColor(10,0);
	printf("\n	                          	            ▆▆	▆  \n");
	printf("	                          	         ▋      ▋　  ▋  ▋			\n");
	printf("	                          	        ▌　 　 　▌　▌     ▌				\n");
	printf("	                          	        ▌　　　　▌ ▌　　　▌				\n");
	printf("	                          	　 　　  ▌      ▌  ▌      ▌				\n");
	printf("	          ▅               	         ■ 　 　▌ ▌	     ▌	\n");
	printf("	         ▅▅              	　　　◢◤　　　　　　　　　 ▃				\n");
	printf("	       ▅    ▅           	　　◢◤　　　　　　　　　 　　◥◣				\n");
	printf("	       ▅    ▅            	　　▌　　　　　　　　　　 　　　▌ 				\n");
	printf("	     ▅        ▅         	　  ▌  ●　　 　　　　●　　　　▌			\n");
	printf("	   ◢▅        ▅◣       	　　▌　　　　　　　　　　　　　 ▌				\n");
	printf("	       ▅    ▅            	　　◥◣ 　 　　 ╳ 　　　　　　◢◤				\n");
	printf("	         ▅▅              	　　 ◢ ▅▃▂　　　▂▂▃▅ ▅				\n");
	printf("	         ▅▅              	　◢◤　　　　▂▂▂　　　　◥◣				\n");
	printf("	         ▅▅             	 ◣▃▌　　　　　　　　　　　 ▃◢▌				\n");
	printf("	         ▅▅            	◥◣▃▌　　　　 　　 　　　　 ▃◢◤				\n");
	printf("	         ▅▅              	　  ▅▃　　　　　 　 　　▂▅				\n");
	printf("	         ▅▅              	　　 　  ■▆▅▅▅▅▅▆■█				\n");
	printf("	         ▅▅              	　　　 　 ▃▃▃▲▃▃▃◢				    \n");
	printf("    ▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆\n\n");
}

void myColor(int fore=7,int back=0){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore+back*0x10);
}
