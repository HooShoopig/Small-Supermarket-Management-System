#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "management_system.h"
#include "clock.h"

//8.23 后续还可以考虑字符输入自动居中对齐功能 

/*存储账号信息的结构体*/
struct accounts{
	char accountName[50];      /*用户账号名*/
	char accountPassword[50];  /*账号密码*/
}account[50];

int accCount,location=0,show_location=0;

//获取光标的位置y
int wherey(){
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.Y+1);
}

//获取光标的位置x
int wherex(){
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.X+1);
}

//void gotoCoordinate(int x,int y){ //切换光标位置，可以用gotoCoordinate(0,0)代替system("cls")然后覆盖打印，可实现清屏不闪屏 
//	COORD pos;
//	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
//	pos.X=x;
//	pos.Y=y;
//	SetConsoleCursorPosition(handle,pos);
//}

//隐藏光标
//void hideCursor()
//{
//	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
//}

void showtime()
{
	time_t timep;
	char s[30];
	time(&timep);
	strcpy(s,ctime(&timep));
	printf("%s", s);
}

void color(short x)	//自定义函根据参数改变颜色 
{
	if (x >= 0 && x <= 15)//参数在0-15的范围颜色
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//只有一个参数，改变字体颜色 
	}
	else//默认的颜色白色
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//建议用myColor替代system("color ...")
//void myColor(int fore=7,int back=0){	//fore为前景色，back为背景色 
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore+back*0x10);
//}

/*扫描按键*/ 
int get_LocationKey(int *location,int x){//72为按键 ↑，80为按键 ↓ 
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
	if(*location>x)
		(*location)=x;
	return 0; 
}

/*闪烁*/ 
void shine(int n){  //循环闪一次耗时0.6s，闪n次耗时n*0.6s 
    char s,col[2];
    while(n--){
		for(s='A';s<='F';s++){
    		sprintf(col,"color 0%c",s);  
			system(col);
			Sleep(100);		
		}
	}
}

/*动态logo打印*/ 
void logoprint(){
	int i;
	Sleep(150);system( "color 0A "); 
	printf("\t _____________________________________________________________________________________________  \n");
	Sleep(150);
	printf("\t│                                                                                            │\n");
	Sleep(150);
	printf("\t│                                                                                            │\n");
	Sleep(150);
	printf("\t│                                                                                            │\n");
	Sleep(150);
	printf("\t│                       ******       *     *       ******      *******                       │\n");
	Sleep(150);
	printf("\t│                       *     *      *     *      *               *                          │\n");
	Sleep(150);
	printf("\t│                       ******       *     *      *               *                          │\n");
	Sleep(150);
	printf("\t│                       *     *      *     *      *               *                          │\n");
	Sleep(150);
	printf("\t│                       ******        *****        ******         *                          │\n");
	Sleep(150);
	printf("\t│                                                                                            │\n");
	printf("\t│                                                                                            │\n");
	Sleep(150);
	printf("\t│                  ******     *******     *******     ******      *******                    │\n");
	Sleep(150);
	printf("\t│                 *              *        *     *     *     *     *                          │\n");
	Sleep(150);
	printf("\t│                  *****         *        *     *     ******      *******                    │\n");
	Sleep(150);
	printf("\t│                       *        *        *     *     *   *       *                          │\n");
	Sleep(150);
	printf("\t│                 ******         *        *******     *    **     *******                    │\n");
	Sleep(150);
	printf("\t│                                                                                            │\n");
	Sleep(150);
	printf("\t│                                                                                            │\n");
	Sleep(150);
	printf("\t│____________________________________________________________________________________________│\n");
	Sleep(150);
	printf("\t                                                                                                \n");
	shine(3);
	system( "color 0A ");
	printf("\t                                     欢迎来到BUCT商店！                                         \n");
	printf("\t                                                                                                \n");
}

//void static_logoprint(){
//	int i;
//	myColor(10,0); 
//	printf("\t _____________________________________________________________________________________________  \n");
//	printf("\t│                                                                                            │\n");
//	printf("\t│                                                                                            │\n");
//	printf("\t│                       ******       *     *       ******      *******                       │\n");
//	printf("\t│                       *     *      *     *      *               *                          │\n");
//	printf("\t│                       ******       *     *      *               *                          │\n");
//	printf("\t│                       *     *      *     *      *               *                          │\n");
//	printf("\t│                       ******        *****        ******         *                          │\n");
//	printf("\t│                                                                                            │\n");
//	printf("\t│                                                                                            │\n");
//	printf("\t│                  ******     *******     *******     ******      *******                    │\n");
//	printf("\t│                 *              *        *     *     *     *     *                          │\n");
//	printf("\t│                  *****         *        *     *     ******      *******                    │\n");
//	printf("\t│                       *        *        *     *     *   *       *                          │\n");
//	printf("\t│                 ******         *        *******     *    **     *******                    │\n");
//	printf("\t│                                                                                            │\n");
//	printf("\t│                                                                                            │\n");
//	printf("\t│____________________________________________________________________________________________│\n");
//	printf("\t                                                                                                \n");
//	printf("\t                                     欢迎来到BUCT商店！                                         \n");
//	printf("\t                                                                                                \n");
//}

void upanddown(int location){
	int i;
	gotoCoordinate(0,0); 
	hideCursor();
	static_logoprint();
	switch(location){
		case 0: {
			myColor(7,1);//蓝底白字 
			printf("\t*                                         注册账号                                            *\n");
			myColor(11,0);//黑底绿字 
			printf("\t*                                           登陆                                              *\n");
			printf("\t*                                         修改密码                                            *\n");
			printf("\t*                                         显示功能                                            *\n");
			printf("\t*                                         说明文档                                            *\n");
			printf("\t*                                           退出                                              *\n"); 
			break;
		}
		case 1: {
			myColor(11,0);
			printf("\t*                                         注册账号                                            *\n");
			myColor(7,1);
			printf("\t*                                           登陆                                              *\n");
			myColor(11,0);
			printf("\t*                                         修改密码                                            *\n");
			printf("\t*                                         显示功能                                            *\n");
			printf("\t*                                         说明文档                                            *\n");
			printf("\t*                                           退出                                              *\n"); 
			break;
		}
		case 2: {
			myColor(11,0);
			printf("\t*                                         注册账号                                            *\n");
			printf("\t*                                           登陆                                              *\n");
			myColor(7,1);
			printf("\t*                                         修改密码                                            *\n");
			myColor(11,0);
			printf("\t*                                         显示功能                                            *\n");
			printf("\t*                                         说明文档                                            *\n");
			printf("\t*                                           退出                                              *\n"); 
			break;
		}
		case 3: {
			myColor(11,0);
			printf("\t*                                         注册账号                                            *\n");
			printf("\t*                                           登陆                                              *\n");
			printf("\t*                                         修改密码                                            *\n");
			myColor(7,1);
			printf("\t*                                         显示功能                                            *\n");
			myColor(11,0);
			printf("\t*                                         说明文档                                            *\n");
			printf("\t*                                           退出                                              *\n"); 
			break;
		}
		case 4: {
			myColor(11,0);
			printf("\t*                                         注册账号                                            *\n");
			printf("\t*                                           登陆                                              *\n");
			printf("\t*                                         修改密码                                            *\n");
			printf("\t*                                         显示功能                                            *\n");
			myColor(7,1);
			printf("\t*                                         说明文档                                            *\n");
			myColor(11,0);
			printf("\t*                                           退出                                              *\n");
			//myColor(3,0); 
			break;
		}
		case 5: {
			myColor(11,0);
			printf("\t*                                         注册账号                                            *\n");
			printf("\t*                                           登陆                                              *\n");
			printf("\t*                                         修改密码                                            *\n");
			printf("\t*                                         显示功能                                            *\n");
			printf("\t*                                         说明文档                                            *\n");
			myColor(7,1); 
			printf("\t*                                           退出                                              *\n");
			myColor(3,0); 
			break;
		}
	}
	Rabit();
}

void show_upanddown(int show_location){
	int i;
	gotoCoordinate(0,0); 
	static_logoprint();
	switch(show_location){
		case 0: {
			myColor(7,1);//蓝底白字 
			printf("\t*                                         显示时钟                                            *\n");
			myColor(11,0);//黑底绿字 
			printf("\t*                                         闪光兔子                                            *\n");
			printf("\t*                                         欢迎光临                                            *\n");
			printf("\t*                                         LOGO闪烁                                            *\n");
			printf("\t*                                        返回上一级                                           *\n"); 
			break;
		}
		case 1: {
			myColor(11,0);
			printf("\t*                                         显示时钟                                            *\n");
			myColor(7,1);
			printf("\t*                                         闪光兔子                                            *\n");
			myColor(11,0);
			printf("\t*                                         欢迎光临                                            *\n");
			printf("\t*                                         LOGO闪烁                                            *\n");
			printf("\t*                                        返回上一级                                           *\n"); 
			break;
		}
		case 2: {
			myColor(11,0);
			printf("\t*                                         显示时钟                                            *\n");
			printf("\t*                                         闪光兔子                                            *\n");
			myColor(7,1);
			printf("\t*                                         欢迎光临                                            *\n");
			myColor(11,0);
			printf("\t*                                         LOGO闪烁                                            *\n");
			printf("\t*                                        返回上一级                                           *\n"); 
			break;
		}
		case 3: {
			myColor(11,0);
			printf("\t*                                         显示时钟                                            *\n");
			printf("\t*                                         闪光兔子                                            *\n");
			printf("\t*                                         欢迎光临                                            *\n");
			myColor(7,1);
			printf("\t*                                         LOGO闪烁                                            *\n");
			myColor(11,0);
			printf("\t*                                        返回上一级                                           *\n"); 
			break;
		}
		case 4: {
			myColor(11,0);
			printf("\t*                                         显示时钟                                            *\n");
			printf("\t*                                         闪光兔子                                            *\n");
			printf("\t*                                         欢迎光临                                            *\n");
			printf("\t*                                         LOGO闪烁                                            *\n");
			myColor(7,1);
			printf("\t*                                        返回上一级                                           *\n");
			myColor(3,0); 
			break;
		}
	}
	Rabit();
}
 
/*从accountCnt.txt中获得用户数*/ 
void getAccountCnt(){
    FILE *fp;
    fp = fopen("accountCnt.txt","r");
    fscanf(fp,"%d",&accCount);
    fclose(fp);
}

/*输出用户数到accountCnt.txt*/ 
void putAccountCnt(){
    FILE *fp;
    fp = fopen("accountCnt.txt","w");
    fprintf(fp,"%d",accCount);
    fclose(fp);
}

/*从account.txt获得所有用户名与密码*/ 
void getAccount(){
    FILE *fp;
    int i;
    fp = fopen("account.txt","r");
    for(i=0;i<=accCount;i++){
        fscanf(fp,"%s",account[i].accountName);
        fscanf(fp,"%s",account[i].accountPassword);
    }
	fclose(fp);
}

/*验证码*/ 
void identifyingCode(){
	int i,x,y;
	char identify[4],str[4];
	char index[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ";
	srand(time(NULL));
	for(i=0;i<4;i++){
    	identify[i]=index[rand()%62];  /*产生随机数*/ 
	}
	printf("\n\t                              请输入验证码 %s   ",identify);
	scanf("%s",str);
	if(strcmp(str,identify)!=0){
		printf("\n\t                            验证码输入错误！请重新输入！\n");
		identifyingCode();
		return;
	}
}

/*新用户*/ 
void addAccount(){
	FILE *fp;
	int i;
	char password[30],str;
	getAccountCnt();
	getAccount();
	printf("\n\n\t                                     请输入账号名： ");
	scanf("%s",account[accCount].accountName);
	for(i=0;i<accCount;i++){
        if(strcmp(account[i].accountName,account[accCount].accountName)==0){              /*判断是否注册*/
            printf("\n\t                                  此账号已注册！请再次申请！");
            getch();
            system("cls");
            return;
        }
    }
	printf("\n\t                                       请输入密码： ");
	scanf("%s",account[accCount].accountPassword);
	printf("\n\t                                       请确认密码： ");
	scanf("%s",password);
	if(strcmp(account[accCount].accountPassword,password)!= 0){
        printf("\n\t                                      输入密码不一致！请再次申请！ ");
        getch(); 
        system("cls");
        return;
    }
    identifyingCode();
	fp=fopen("account.txt","wt");
    for(i=0;i<=accCount;i++){
        fprintf(fp,"%s\n",account[i].accountName);
        fprintf(fp,"%s\n",account[i].accountPassword);
    }
    fclose(fp); 
	accCount++;
	putAccountCnt(); 
	printf("\n\t                                         注册成功！\n");
	getch();
	system("cls");
}

/*登录模块*/ 
void logIn(){
	int i; 
	char str[30],password[30];
	getAccountCnt();
	getAccount(); 
	printf("\n\t                                     请输入账号名： ");
    scanf("%s",str);
    for(i=0;i<accCount;i++){
        if(strcmp(account[i].accountName,str)==0){
            while(1){
            	printf("\n\t                                      请输入密码： ");
            	scanf("%s",password);
            	if(strcmp(account[i].accountPassword,password)==0){
            		printf("\n\t                                          登陆成功！");
            		getch();
            		system("cls");
					begin();       /*跳转begin界面*/ 
					break;
				}
				else{
					printf("\n\t                                   密码错误！请重新输入密码！\n");
				}
			}
            break;
        }
    }
    if(i==accCount){ 
    	printf("\n\t                    查无此账号！请检查是否账号名输入错误或注册新账号！");
    	getch();
		system("cls");
	} 
}

/*修改密码*/  
void changePw(){
	int i,j;
	FILE *fp; 
	char str[30],password[30];
	getAccountCnt();
	getAccount(); 
	printf("\n\t                                     请输入账号名： ");
    scanf("%s",str);
    for(i=0;i<accCount;i++){
        if(strcmp(account[i].accountName,str)==0){
            while(1){
            	printf("\n\t                                     请输入原密码： ");
            	scanf("%s",password);
            	if(strcmp(account[i].accountPassword,password)==0){
            		printf("\n\t                                     请输入新密码： ");
            		scanf("%s",password); 
            		identifyingCode();
            		strcpy(account[i].accountPassword,password);
            		printf("\n\t                                       修改成功！");
            		fp=fopen("account.txt","wt");
    				for(j=0;j<=accCount;j++){
        				fprintf(fp,"%s\n",account[j].accountName);
        				fprintf(fp,"%s\n",account[j].accountPassword);
   					}
   					fclose(fp); 
            		getch();
					system("cls");
					break;
				}
				else{
					printf("\n\t                              密码错误！请重新输入密码！\n");
				}
			}
            break;
        }
    }
    if(i==accCount){ 
    	printf("\n\t                           查无此账号！请检查是否账号名输入错误或注册新账号！");
    	getch();
		system("cls");
	} 	
}

void logoShine(){
	system("cls");
	static_logoprint();
	while(!kbhit()){
		shine(1);
	}
}

void RBShine(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	Rabit(); 
	while(!kbhit()){
		shine(1);
	}
}

void showFunc(){
	system("cls");
	int flag=0;
	while(1){
		show_upanddown(show_location);
		if(get_LocationKey(&show_location,4)){
			switch(show_location){
				case 0: clocks();break;
				case 1: RBShine();system("cls");break;
				case 2: break;
				case 3: logoShine();break;
				case 4: flag=1;break;
			}
		}
		if(flag)
			break;
	}
}

void file(){
	system("cls");
	printf("__________________________________________________________________________________"); 
	myColor(14,0);
	printf("\n\n\n\t\t显示菜单：\n");
	myColor(10,0);
	printf("注册账号：新用户可注册账号\n");
	printf("登陆：账号注册后可进行登陆\n");
	printf("修改密码：已注册用户可输入原密码后修改密码\n");
	printf("显示功能：可用于店面的招牌，吸引顾客，增加人流量\n");
	printf("说明文档：进入本说明文档\n");
	myColor(14,0);
	printf("\n\n\n\t\t商品管理系统：\n");
	myColor(10,0);
	printf("商品信息输入：新建一个student.txt，手动输入商品信息。\n");
	printf("商品信息添加：添加新的商品，同时输入信息。\n商品信息删减：删减一个商品信息。\n商品信息查找：输入商品id，查找这个商品的信息。\n商品信息修改：根据商品Id，修改这个商品的信息，例如进货时的存量修改。\n");
	printf("商品价格排序：根据价格大小升序or降序显示。\n");
	printf("商品信息输出：输出所有商品信息。\n");
	myColor(14,0);
	printf("\n\n\n\t\t销售记录管理：\n");
	myColor(10,0);
    printf("每日商品销售记录：记录每日商品销售情况，记录在record.txt中。\n每日销售记录输出：输出每日商品销售情况。\n清楚每日销售记录：清除每日销售记录，即清除前述所记录。\n");
	myColor(14,0);
	printf("\n\n\n\t\t销售账单记录：\n");
	myColor(10,0);
	printf("每日商店销售总价：记录每日商店销售总价。\n");
	printf("顾客购买账单记录：记录某位顾客购买情况，同时减去库存剩余并记录，记录在.txt文件中。\n");
	printf("打印顾客账单记录：打印顾客的账单情况，包括购买记录，时间与开账人等。\n系统初始化：将所有记录清空。\n开发人员介绍：介绍作者。\n退出系统：退出系统。\n");
	printf("\n\n__________________________________________________________________________________");
	getch();
	system("cls");
}

void login(){
	hideCursor();
	logoprint();
	//loginprint(); //打印登陆界面 
	while(1){
		upanddown(location);
		if(get_LocationKey(&location,5)){
			switch(location){
				case 0: addAccount();break;
				case 1: logIn();break;
				case 2: changePw();break;
				case 3: showFunc();break; 
				case 4: file();break;
				case 5: printf("嘿嘿");exit(-1);
			}
		}
	}
}

int main(){
	//system( "color 0A ");
	//printf("|︳│┃┃│▏▏\n");
	login(); 
}
