#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include "management_system.h"
#include "clock.h"

//8.23 ���������Կ����ַ������Զ����ж��빦�� 

/*�洢�˺���Ϣ�Ľṹ��*/
struct accounts{
	char accountName[50];      /*�û��˺���*/
	char accountPassword[50];  /*�˺�����*/
}account[50];

int accCount,location=0,show_location=0;

//��ȡ����λ��y
int wherey(){
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.Y+1);
}

//��ȡ����λ��x
int wherex(){
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);
    return (pBuffer.dwCursorPosition.X+1);
}

//void gotoCoordinate(int x,int y){ //�л����λ�ã�������gotoCoordinate(0,0)����system("cls")Ȼ�󸲸Ǵ�ӡ����ʵ������������ 
//	COORD pos;
//	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
//	pos.X=x;
//	pos.Y=y;
//	SetConsoleCursorPosition(handle,pos);
//}

//���ع��
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

void color(short x)	//�Զ��庯���ݲ����ı���ɫ 
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ 
	}
	else//Ĭ�ϵ���ɫ��ɫ
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}

//������myColor���system("color ...")
//void myColor(int fore=7,int back=0){	//foreΪǰ��ɫ��backΪ����ɫ 
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fore+back*0x10);
//}

/*ɨ�谴��*/ 
int get_LocationKey(int *location,int x){//72Ϊ���� ����80Ϊ���� �� 
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

/*��˸*/ 
void shine(int n){  //ѭ����һ�κ�ʱ0.6s����n�κ�ʱn*0.6s 
    char s,col[2];
    while(n--){
		for(s='A';s<='F';s++){
    		sprintf(col,"color 0%c",s);  
			system(col);
			Sleep(100);		
		}
	}
}

/*��̬logo��ӡ*/ 
void logoprint(){
	int i;
	Sleep(150);system( "color 0A "); 
	printf("\t _____________________________________________________________________________________________  \n");
	Sleep(150);
	printf("\t��                                                                                            ��\n");
	Sleep(150);
	printf("\t��                                                                                            ��\n");
	Sleep(150);
	printf("\t��                                                                                            ��\n");
	Sleep(150);
	printf("\t��                       ******       *     *       ******      *******                       ��\n");
	Sleep(150);
	printf("\t��                       *     *      *     *      *               *                          ��\n");
	Sleep(150);
	printf("\t��                       ******       *     *      *               *                          ��\n");
	Sleep(150);
	printf("\t��                       *     *      *     *      *               *                          ��\n");
	Sleep(150);
	printf("\t��                       ******        *****        ******         *                          ��\n");
	Sleep(150);
	printf("\t��                                                                                            ��\n");
	printf("\t��                                                                                            ��\n");
	Sleep(150);
	printf("\t��                  ******     *******     *******     ******      *******                    ��\n");
	Sleep(150);
	printf("\t��                 *              *        *     *     *     *     *                          ��\n");
	Sleep(150);
	printf("\t��                  *****         *        *     *     ******      *******                    ��\n");
	Sleep(150);
	printf("\t��                       *        *        *     *     *   *       *                          ��\n");
	Sleep(150);
	printf("\t��                 ******         *        *******     *    **     *******                    ��\n");
	Sleep(150);
	printf("\t��                                                                                            ��\n");
	Sleep(150);
	printf("\t��                                                                                            ��\n");
	Sleep(150);
	printf("\t��____________________________________________________________________________________________��\n");
	Sleep(150);
	printf("\t                                                                                                \n");
	shine(3);
	system( "color 0A ");
	printf("\t                                     ��ӭ����BUCT�̵꣡                                         \n");
	printf("\t                                                                                                \n");
}

//void static_logoprint(){
//	int i;
//	myColor(10,0); 
//	printf("\t _____________________________________________________________________________________________  \n");
//	printf("\t��                                                                                            ��\n");
//	printf("\t��                                                                                            ��\n");
//	printf("\t��                       ******       *     *       ******      *******                       ��\n");
//	printf("\t��                       *     *      *     *      *               *                          ��\n");
//	printf("\t��                       ******       *     *      *               *                          ��\n");
//	printf("\t��                       *     *      *     *      *               *                          ��\n");
//	printf("\t��                       ******        *****        ******         *                          ��\n");
//	printf("\t��                                                                                            ��\n");
//	printf("\t��                                                                                            ��\n");
//	printf("\t��                  ******     *******     *******     ******      *******                    ��\n");
//	printf("\t��                 *              *        *     *     *     *     *                          ��\n");
//	printf("\t��                  *****         *        *     *     ******      *******                    ��\n");
//	printf("\t��                       *        *        *     *     *   *       *                          ��\n");
//	printf("\t��                 ******         *        *******     *    **     *******                    ��\n");
//	printf("\t��                                                                                            ��\n");
//	printf("\t��                                                                                            ��\n");
//	printf("\t��____________________________________________________________________________________________��\n");
//	printf("\t                                                                                                \n");
//	printf("\t                                     ��ӭ����BUCT�̵꣡                                         \n");
//	printf("\t                                                                                                \n");
//}

void upanddown(int location){
	int i;
	gotoCoordinate(0,0); 
	hideCursor();
	static_logoprint();
	switch(location){
		case 0: {
			myColor(7,1);//���װ��� 
			printf("\t*                                         ע���˺�                                            *\n");
			myColor(11,0);//�ڵ����� 
			printf("\t*                                           ��½                                              *\n");
			printf("\t*                                         �޸�����                                            *\n");
			printf("\t*                                         ��ʾ����                                            *\n");
			printf("\t*                                         ˵���ĵ�                                            *\n");
			printf("\t*                                           �˳�                                              *\n"); 
			break;
		}
		case 1: {
			myColor(11,0);
			printf("\t*                                         ע���˺�                                            *\n");
			myColor(7,1);
			printf("\t*                                           ��½                                              *\n");
			myColor(11,0);
			printf("\t*                                         �޸�����                                            *\n");
			printf("\t*                                         ��ʾ����                                            *\n");
			printf("\t*                                         ˵���ĵ�                                            *\n");
			printf("\t*                                           �˳�                                              *\n"); 
			break;
		}
		case 2: {
			myColor(11,0);
			printf("\t*                                         ע���˺�                                            *\n");
			printf("\t*                                           ��½                                              *\n");
			myColor(7,1);
			printf("\t*                                         �޸�����                                            *\n");
			myColor(11,0);
			printf("\t*                                         ��ʾ����                                            *\n");
			printf("\t*                                         ˵���ĵ�                                            *\n");
			printf("\t*                                           �˳�                                              *\n"); 
			break;
		}
		case 3: {
			myColor(11,0);
			printf("\t*                                         ע���˺�                                            *\n");
			printf("\t*                                           ��½                                              *\n");
			printf("\t*                                         �޸�����                                            *\n");
			myColor(7,1);
			printf("\t*                                         ��ʾ����                                            *\n");
			myColor(11,0);
			printf("\t*                                         ˵���ĵ�                                            *\n");
			printf("\t*                                           �˳�                                              *\n"); 
			break;
		}
		case 4: {
			myColor(11,0);
			printf("\t*                                         ע���˺�                                            *\n");
			printf("\t*                                           ��½                                              *\n");
			printf("\t*                                         �޸�����                                            *\n");
			printf("\t*                                         ��ʾ����                                            *\n");
			myColor(7,1);
			printf("\t*                                         ˵���ĵ�                                            *\n");
			myColor(11,0);
			printf("\t*                                           �˳�                                              *\n");
			//myColor(3,0); 
			break;
		}
		case 5: {
			myColor(11,0);
			printf("\t*                                         ע���˺�                                            *\n");
			printf("\t*                                           ��½                                              *\n");
			printf("\t*                                         �޸�����                                            *\n");
			printf("\t*                                         ��ʾ����                                            *\n");
			printf("\t*                                         ˵���ĵ�                                            *\n");
			myColor(7,1); 
			printf("\t*                                           �˳�                                              *\n");
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
			myColor(7,1);//���װ��� 
			printf("\t*                                         ��ʾʱ��                                            *\n");
			myColor(11,0);//�ڵ����� 
			printf("\t*                                         ��������                                            *\n");
			printf("\t*                                         ��ӭ����                                            *\n");
			printf("\t*                                         LOGO��˸                                            *\n");
			printf("\t*                                        ������һ��                                           *\n"); 
			break;
		}
		case 1: {
			myColor(11,0);
			printf("\t*                                         ��ʾʱ��                                            *\n");
			myColor(7,1);
			printf("\t*                                         ��������                                            *\n");
			myColor(11,0);
			printf("\t*                                         ��ӭ����                                            *\n");
			printf("\t*                                         LOGO��˸                                            *\n");
			printf("\t*                                        ������һ��                                           *\n"); 
			break;
		}
		case 2: {
			myColor(11,0);
			printf("\t*                                         ��ʾʱ��                                            *\n");
			printf("\t*                                         ��������                                            *\n");
			myColor(7,1);
			printf("\t*                                         ��ӭ����                                            *\n");
			myColor(11,0);
			printf("\t*                                         LOGO��˸                                            *\n");
			printf("\t*                                        ������һ��                                           *\n"); 
			break;
		}
		case 3: {
			myColor(11,0);
			printf("\t*                                         ��ʾʱ��                                            *\n");
			printf("\t*                                         ��������                                            *\n");
			printf("\t*                                         ��ӭ����                                            *\n");
			myColor(7,1);
			printf("\t*                                         LOGO��˸                                            *\n");
			myColor(11,0);
			printf("\t*                                        ������һ��                                           *\n"); 
			break;
		}
		case 4: {
			myColor(11,0);
			printf("\t*                                         ��ʾʱ��                                            *\n");
			printf("\t*                                         ��������                                            *\n");
			printf("\t*                                         ��ӭ����                                            *\n");
			printf("\t*                                         LOGO��˸                                            *\n");
			myColor(7,1);
			printf("\t*                                        ������һ��                                           *\n");
			myColor(3,0); 
			break;
		}
	}
	Rabit();
}
 
/*��accountCnt.txt�л���û���*/ 
void getAccountCnt(){
    FILE *fp;
    fp = fopen("accountCnt.txt","r");
    fscanf(fp,"%d",&accCount);
    fclose(fp);
}

/*����û�����accountCnt.txt*/ 
void putAccountCnt(){
    FILE *fp;
    fp = fopen("accountCnt.txt","w");
    fprintf(fp,"%d",accCount);
    fclose(fp);
}

/*��account.txt��������û���������*/ 
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

/*��֤��*/ 
void identifyingCode(){
	int i,x,y;
	char identify[4],str[4];
	char index[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJLMNOPQRSTUVWXYZ";
	srand(time(NULL));
	for(i=0;i<4;i++){
    	identify[i]=index[rand()%62];  /*���������*/ 
	}
	printf("\n\t                              ��������֤�� %s   ",identify);
	scanf("%s",str);
	if(strcmp(str,identify)!=0){
		printf("\n\t                            ��֤������������������룡\n");
		identifyingCode();
		return;
	}
}

/*���û�*/ 
void addAccount(){
	FILE *fp;
	int i;
	char password[30],str;
	getAccountCnt();
	getAccount();
	printf("\n\n\t                                     �������˺����� ");
	scanf("%s",account[accCount].accountName);
	for(i=0;i<accCount;i++){
        if(strcmp(account[i].accountName,account[accCount].accountName)==0){              /*�ж��Ƿ�ע��*/
            printf("\n\t                                  ���˺���ע�ᣡ���ٴ����룡");
            getch();
            system("cls");
            return;
        }
    }
	printf("\n\t                                       ���������룺 ");
	scanf("%s",account[accCount].accountPassword);
	printf("\n\t                                       ��ȷ�����룺 ");
	scanf("%s",password);
	if(strcmp(account[accCount].accountPassword,password)!= 0){
        printf("\n\t                                      �������벻һ�£����ٴ����룡 ");
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
	printf("\n\t                                         ע��ɹ���\n");
	getch();
	system("cls");
}

/*��¼ģ��*/ 
void logIn(){
	int i; 
	char str[30],password[30];
	getAccountCnt();
	getAccount(); 
	printf("\n\t                                     �������˺����� ");
    scanf("%s",str);
    for(i=0;i<accCount;i++){
        if(strcmp(account[i].accountName,str)==0){
            while(1){
            	printf("\n\t                                      ���������룺 ");
            	scanf("%s",password);
            	if(strcmp(account[i].accountPassword,password)==0){
            		printf("\n\t                                          ��½�ɹ���");
            		getch();
            		system("cls");
					begin();       /*��תbegin����*/ 
					break;
				}
				else{
					printf("\n\t                                   ��������������������룡\n");
				}
			}
            break;
        }
    }
    if(i==accCount){ 
    	printf("\n\t                    ���޴��˺ţ������Ƿ��˺�����������ע�����˺ţ�");
    	getch();
		system("cls");
	} 
}

/*�޸�����*/  
void changePw(){
	int i,j;
	FILE *fp; 
	char str[30],password[30];
	getAccountCnt();
	getAccount(); 
	printf("\n\t                                     �������˺����� ");
    scanf("%s",str);
    for(i=0;i<accCount;i++){
        if(strcmp(account[i].accountName,str)==0){
            while(1){
            	printf("\n\t                                     ������ԭ���룺 ");
            	scanf("%s",password);
            	if(strcmp(account[i].accountPassword,password)==0){
            		printf("\n\t                                     �����������룺 ");
            		scanf("%s",password); 
            		identifyingCode();
            		strcpy(account[i].accountPassword,password);
            		printf("\n\t                                       �޸ĳɹ���");
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
					printf("\n\t                              ��������������������룡\n");
				}
			}
            break;
        }
    }
    if(i==accCount){ 
    	printf("\n\t                           ���޴��˺ţ������Ƿ��˺�����������ע�����˺ţ�");
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
	printf("\n\n\n\t\t��ʾ�˵���\n");
	myColor(10,0);
	printf("ע���˺ţ����û���ע���˺�\n");
	printf("��½���˺�ע���ɽ��е�½\n");
	printf("�޸����룺��ע���û�������ԭ������޸�����\n");
	printf("��ʾ���ܣ������ڵ�������ƣ������˿ͣ�����������\n");
	printf("˵���ĵ������뱾˵���ĵ�\n");
	myColor(14,0);
	printf("\n\n\n\t\t��Ʒ����ϵͳ��\n");
	myColor(10,0);
	printf("��Ʒ��Ϣ���룺�½�һ��student.txt���ֶ�������Ʒ��Ϣ��\n");
	printf("��Ʒ��Ϣ��ӣ�����µ���Ʒ��ͬʱ������Ϣ��\n��Ʒ��Ϣɾ����ɾ��һ����Ʒ��Ϣ��\n��Ʒ��Ϣ���ң�������Ʒid�����������Ʒ����Ϣ��\n��Ʒ��Ϣ�޸ģ�������ƷId���޸������Ʒ����Ϣ���������ʱ�Ĵ����޸ġ�\n");
	printf("��Ʒ�۸����򣺸��ݼ۸��С����or������ʾ��\n");
	printf("��Ʒ��Ϣ��������������Ʒ��Ϣ��\n");
	myColor(14,0);
	printf("\n\n\n\t\t���ۼ�¼����\n");
	myColor(10,0);
    printf("ÿ����Ʒ���ۼ�¼����¼ÿ����Ʒ�����������¼��record.txt�С�\nÿ�����ۼ�¼��������ÿ����Ʒ���������\n���ÿ�����ۼ�¼�����ÿ�����ۼ�¼�������ǰ������¼��\n");
	myColor(14,0);
	printf("\n\n\n\t\t�����˵���¼��\n");
	myColor(10,0);
	printf("ÿ���̵������ܼۣ���¼ÿ���̵������ܼۡ�\n");
	printf("�˿͹����˵���¼����¼ĳλ�˿͹��������ͬʱ��ȥ���ʣ�ಢ��¼����¼��.txt�ļ��С�\n");
	printf("��ӡ�˿��˵���¼����ӡ�˿͵��˵���������������¼��ʱ���뿪���˵ȡ�\nϵͳ��ʼ���������м�¼��ա�\n������Ա���ܣ��������ߡ�\n�˳�ϵͳ���˳�ϵͳ��\n");
	printf("\n\n__________________________________________________________________________________");
	getch();
	system("cls");
}

void login(){
	hideCursor();
	logoprint();
	//loginprint(); //��ӡ��½���� 
	while(1){
		upanddown(location);
		if(get_LocationKey(&location,5)){
			switch(location){
				case 0: addAccount();break;
				case 1: logIn();break;
				case 2: changePw();break;
				case 3: showFunc();break; 
				case 4: file();break;
				case 5: printf("�ٺ�");exit(-1);
			}
		}
	}
}

int main(){
	//system( "color 0A ");
	//printf("|��������������\n");
	login(); 
}
