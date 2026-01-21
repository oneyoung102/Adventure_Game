#include<stdio.h>
#include<conio.h>

#include<stdlib.h>
#include<time.h>
#include <windows.h>

#define ONE_SECOND 1000 //Sleep(ONE_SECOND);


#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#define TU_DIS 1
#define DIS 0
#define KOR 0
#define ENG 1

void textcolor(int foreground, int background); 

char dis[45][91]= {' ',}; //91x45
char tu_dis[30][51]= {' ',}; //51x30
int tuto=0;
int tu_sel();
int tu_phase=1;
int tu_mov_test[4]={0, }; 

int i,j=0;
char mov_but;
int mov_pos;
int mov_pos1;


int inven=0;
int effect=0;


int coin,key,jew,toc=0;
int dcoin,dkey,djew,dtoc=0;

int level;
int xp,mxp=0;

int health,m_health,dhealth;

int build(int, int, int, int);
int bush(int, int, int);
int wall(int, int, int, int);
int buildset();

int wchest();
int mchest();
int Mchest();
int chestset();

int skin();
int sel_skin();
int store();
int heal();
int sel_heal();
int sword();
int sel_weapon();

int skin_m[11]={0, };  //0은 A 
int skin_s[11]={0, }; 
int skin_z();
int skin9=1;
int shield_m[11]={0, };
int shield_s[11]={0, };
int shield_z();
int weapon_m[9]={0, };
int weapon_s[9]={0, };
int weapon_z();

float shield=1;
float w_shield=0; 
float weapon=1;
int distance=1;

int dead=0;
int dead_s; 

char sell[11];  
char selr[11];
int selplus=0;

int mon_kill();

int lang;

enum {
    False, True
};


int main(int argc, char*argv[]) {//main
	
	int mov1=14;
    int mov2=32;
    int tu_mov1=14;
    int tu_mov2=32;
 
   
int mon_mov1;
int mon_mov2;	
	
	if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
	
    level=1;
    mxp=20;
    health=100;
    m_health=100;
    distance=1;
    

    skin_s[0]=1;
    skin_m[0]=1;
    shield_m[9]=1; 
    weapon_m[8]=1;
    shield_s[9]=1; 
    weapon_s[8]=1;
    
    
   
    i=0;
	j=0;
    while(i<=44) {// 전체 멥 세팅 
    	while(j<=90){
        dis[i][j]=' ';
        j+=1;
    }
    j=0;
        i+=1;
    }
    i=0;
	j=0;
    while(i<=29) {// tuto 멥 세팅 
    	while(j<=50){
        tu_dis[i][j]=' ';
        j+=1;
    }
    j=0;
        i+=1;
    }
    
	
    i=0;
	j=0;
    while(i<=6) {//벽 세팅  
    	while(j<=90){
        if((j+i)%17==0||(j+i)%19==0) {
            dis[i][j]='>';
            dis[i+38][j]='>';
        }
        else {
            dis[i][j]='<';
            dis[i+38][j]='<';
        }
        j+=1;
    }
        j=0;
        i+=1;
    }
    i=0;
	j=0;
    while(i<=6) {// 튜토벽 세팅  
    	while(j<=50){
        if((j+i)%17==0||(j+i)%19==0) {
            tu_dis[i][j]='>';
            tu_dis[i+23][j]='>';
        }
        else {
           tu_dis[i][j]='<';
            tu_dis[i+23][j]='<';
        }
        j+=1;
    }
        j=0;
        i+=1;
    }
    i=0;
    j=0;
    while(i<=44) {//벽 세팅 
        while(j<=12) {
            if((i+j)%17==0||(i+j)%13==0) {
                dis[i][j]='>';
                dis[i][j+80]='>';
            }
            else {
                dis[i][j]='<';
                dis[i][j+80]='<';
            }
            
            j+=1;
        }
        j=0;
        i+=1;
    }
    i=0;
	j=0;
	while(i<=29) {// 튜토벽 세팅 
        while(j<=12) {
            if((i+j)%17==0||(i+j)%13==0) {
                tu_dis[i][j]='>';
                tu_dis[i][j+38]='>';
            }
            else {
                tu_dis[i][j]='<';
                tu_dis[i][j+38]='<';
            }
            
            j+=1;
        }
        j=0;
        i+=1;
    }
    i=0;
	j=0;
    
  // 블럭 설정 
   

    bush(7,22,DIS);
    bush(10,22,DIS);
    bush(12,22,DIS);
    bush(7,27,DIS);
    bush(12,30,DIS);
    bush(7,30,DIS);
    bush(7,38,DIS);
    bush(12,15,DIS); 
	bush(8,53,DIS);
	bush(12,53,DIS);   
	bush(7,68,DIS);
	bush(11,68,DIS);
	bush(7,74,DIS);
	bush(9,74,DIS);
	bush(21,23,DIS);
	bush(21,15,DIS);
	bush(34,22,DIS);
	bush(30,22,DIS);
	bush(34,28,DIS);
	bush(34,53,DIS);
	bush(34,59,DIS);
	bush(23,73,DIS);
	bush(26,73,DIS);
	bush(26,68,DIS);
	bush(29,73,DIS);
	bush(16,62,DIS);
	
    buildset(); 
    
    
   chestset();
	
	wall(16, 39, 1,DIS);
	bush(17,39,DIS);
	wall(16, 49, 1,DIS);
	bush(17,49,DIS);
	wall(17, 38, 2,DIS);
	wall(17, 54, 2,DIS);
	wall(26, 39, 1,DIS);
	bush(23,39,DIS);
	wall(26, 49, 1,DIS);
	bush(23,49,DIS);
	wall(23, 38, 2,DIS);
	wall(23, 54, 2,DIS);
	wall(15, 62, 1,DIS);
	wall(26, 67, 2,DIS);
	
	wall(13, 16, 2,TU_DIS);
	bush(16, 13, TU_DIS);
	bush(16, 15, TU_DIS);
	wall(13, 34, 2,TU_DIS);
	bush(16, 33, TU_DIS);
	bush(16, 31, TU_DIS);
	wall(19, 16, 2,TU_DIS);
	wall(19, 34, 2,TU_DIS);
	build(7, 22, 3, TU_DIS);
	tu_dis[11][25]='X';
	tu_dis[9][25]='!';
    
    
    dis[28][41]='!';  //skin store
    wall(30, 39, 1,DIS);
    bush(27,33,DIS);
    dis[28][51]='!';  //skin setting
    wall(30, 49, 1,DIS);
    bush(27,55,DIS);
    dis[18][51]='!';  //game set
    dis[25][21]='!';  //heal&shield
    wall(26,15,1,DIS);
    wall(26,23,1,DIS);
	dis[27][70]='!';  //weapon 
    
    
    
  // 블럭 설정 
  tuto=0; 
 selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
	start :
	textcolor(WHITE, BLACK);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌────────────────────────────────────────┐ \n");
	   printf("│                                        │ \n");
       printf("│                THE GAME                │ \n");
	   printf("│                                        │ \n"); 
	   printf("│     -------------------------------    │ \n"); 
	   printf("│                                        │ \n"); 
	   if(selplus!=0){
	   	printf("│ ");
	   	textcolor(DARKGRAY, BLACK);
	   	if(lang==KOR)
	   	printf("          %c - 새게임 시작 - %c          ",sell[0],selr[0]);
	   	if(lang==ENG)
	   	printf("           %c - New Game - %c            ",sell[0],selr[0]);
	   	textcolor(WHITE, BLACK);
	   	printf("│ \n");
	   }
	   else if(selplus==0){
	   	textcolor(WHITE, BLACK);
	   	if(lang==KOR)
	   	printf("│           %c - 새게임 시작 - %c          │ \n",sell[0],selr[0]);
	   	if(lang==ENG)
	   	printf("│            %c - New Game - %c            │ \n",sell[0],selr[0]);
	   }
	   printf("│                                        │ \n");  
	   printf("│                                        │ \n"); 
	   if(selplus!=1){
	   	printf("│ ");
	   	textcolor(DARKGRAY, BLACK);
	   	if(lang==KOR)
	   	printf("         %c - 튜토리얼 시작 - %c         ",sell[1],selr[1]);
	   	if(lang==ENG)
	   	printf("           %c - Tutorial - %c            ",sell[1],selr[1]);
	   	textcolor(WHITE, BLACK);
	   	printf("│ \n");
	   }
	   else if(selplus==1){
	   	textcolor(WHITE, BLACK);
	   	if(lang==KOR)
	   	printf("│          %c - 튜토리얼 시작 - %c         │ \n",sell[1],selr[1]);
	    if(lang==ENG)
	    printf("│            %c - Tutorial - %c            │ \n",sell[1],selr[1]);
	   }   
	   printf("│                                        │ \n");  
	   printf("│                                        │ \n");
	   if(selplus!=2){
	   	printf("│ ");
	   	textcolor(DARKGRAY, BLACK);
	   	if(lang==KOR)
	    printf("             %c - 언어 - %c              ",sell[2],selr[2]);
	    if(lang==ENG)
	    printf("           %c - Language - %c            ",sell[2],selr[2]);
	   	textcolor(WHITE, BLACK);
	   	printf("│ \n");
	   }
	   else if(selplus==2){
	   	textcolor(WHITE, BLACK);
	   	if(lang==KOR)
	   	printf("│              %c - 언어 - %c              │ \n",sell[2],selr[2]);
	   	if(lang==ENG)
	   	printf("│            %c - Language - %c            │ \n",sell[2],selr[2]);
	   }
	   printf("│                                        │ \n");  
	   printf("│                                        │ \n");
	   if(selplus!=3){
	   	printf("│ ");
	   	textcolor(DARKGRAY, BLACK);
	   	if(lang==KOR)
	    printf("            %c - 나가기 - %c             ",sell[3],selr[3]);
	   if(lang==ENG)
	    printf("             %c - End - %c               ",sell[3],selr[3]);
	   	textcolor(WHITE, BLACK);
	   	printf("│ \n");
	   }
	   else if(selplus==3){
	   	textcolor(WHITE, BLACK);
	   	if(lang==KOR)
	   	printf("│             %c - 나가기 - %c             │ \n",sell[3],selr[3]);
	   	if(lang==ENG)
	   	printf("│              %c - End - %c               │ \n",sell[3],selr[3]);
	   }  	   
	   printf("│                                        │ \n");  
	   printf("│                                        │ \n");
	   if(lang==KOR) 
	   printf("│  위/아래 : w/s  선택 : e               │ \n");
	   if(lang==ENG)
	   printf("│  Up/Dwon : w/s  Select : e             │ \n");

    	printf("└────────────────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
		if(mov_but=='s'){
			if(selplus<=3){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==4){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto start;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=3;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto start;
		}
		if(mov_but=='e'){
	    if(selplus==0){
	    	tuto=0;
	    	selr[selplus]=' ';
    sell[selplus]=' ';
goto Display;
		}  
		else if(selplus==1){
        tuto=1;
         tu_mov1=10;
         tu_mov2=11;
         selr[selplus]=' ';
    sell[selplus]=' ';
        goto Display;
		}
		else if(selplus==2){
			selr[selplus]=' ';
        	sell[selplus]=' ';
		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
	language :
	textcolor(WHITE, BLACK);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌────────────────────────────────┐ \n");
	   printf("│                                │ \n");
	   if(lang==KOR)
       printf("│            언어 설정           │ \n");
       else if(lang==ENG)
       printf("│        Language Setting        │ \n");
	   printf("│                                │ \n"); 
	   printf("│     -----------------------    │ \n"); 
	   printf("│                                │ \n"); 
	   printf("│                                │ \n");
	   if(selplus!=0){
	   	printf("│ ");
	   	textcolor(DARKGRAY, BLACK);
	   	printf("         %c - 한국어 - %c        ",sell[0],selr[0]);
	   	textcolor(WHITE, BLACK);
	   	printf("│ \n");
	   }
	   else if(selplus==0){
	   	textcolor(WHITE, BLACK);
	   	printf("│          %c - 한국어 - %c        │ \n",sell[0],selr[0]);
	   }
	   printf("│                                │ \n");  
	   printf("│                                │ \n"); 
	   if(selplus!=1){
	   	printf("│ ");
	   	textcolor(DARKGRAY, BLACK);
	   	printf("     %c - English(BETA) - %c     ",sell[1],selr[1]);
	   	textcolor(WHITE, BLACK);
	   	printf("│ \n");
	   }
	   else if(selplus==1){
	   	textcolor(WHITE, BLACK);
	   	printf("│      %c - English(BETA) - %c     │ \n",sell[1],selr[1]);
	   }   
	   printf("│                                │ \n");   	   
	   printf("│                                │ \n");  
	   printf("│                                │ \n"); 
	   if(lang==KOR) 
	   printf("│  위/아래 : w/s  선택 : e       │ \n│  나가기 : q                    │ \n");
	   if(lang==ENG)
	   printf("│  Up/Down : w/s  Select : e     │ \n│  Out : q                       │ \n");

    	printf("└────────────────────────────────┘ \n ");
		while(True) {
        mov_but=_getch();
		if(mov_but=='s'){
			if(selplus<=1){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==2){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto language;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=1;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto language;
		}
		if(mov_but=='q'){
			selr[selplus]=' ';
        	sell[selplus]=' ';
			selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
			goto start;
		}
		if(mov_but=='e'){
	    if(selplus==0){
	    	lang=KOR;
	    	goto language;
		}  
		else if(selplus==1){
			lang=ENG;
			goto language;
		}	
		} 
	}
	goto language;
}
		else if(selplus==3){
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
		}
			
		goto start;
	}
		}
		
		
 
if(tuto=0) 
  	dis[mon_mov1][mon_mov2]='e';     
 
    
Display :          //게임시작 
	
	
	
	if(mxp<=xp){// 레벨업  
		xp-=mxp;
		if(level%5==4){
		mxp+=5;	
		}
		level+=1;
		coin+=level*2;
		dcoin+=level*2;
		jew+=3;
		djew=3;
	}
	
	skin9+=1;
	if(dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='_'&&tuto==0) {// 스킨 감지 
		if(skin_s[0]==1)
    dis[(mov1+7)][(mov2+14)]='A';
    if(skin_s[1]==1)
    dis[(mov1+7)][(mov2+14)]='B';
    if(skin_s[2]==1)
    dis[(mov1+7)][(mov2+14)]='C';
    if(skin_s[3]==1)
    dis[(mov1+7)][(mov2+14)]='D';
    if(skin_s[4]==1)
    dis[(mov1+7)][(mov2+14)]='E';
    if(skin_s[5]==1)
    dis[(mov1+7)][(mov2+14)]='F';
    if(skin_s[6]==1)
    dis[(mov1+7)][(mov2+14)]='@';
    if(skin_s[7]==1)
    dis[(mov1+7)][(mov2+14)]='#';
    if(skin_s[8]==1)
    dis[(mov1+7)][(mov2+14)]='*';
    if(skin_s[9]==1){
    	if(skin9%2==0)
    dis[(mov1+7)][(mov2+14)]=',';
    if(skin9%2==1)
    dis[(mov1+7)][(mov2+14)]='.';
	}    
    if(skin_s[10]==1)
    dis[(mov1+7)][(mov2+14)]='K';
}
else if(dis[mov1+7][mov2+14]=='_'&&tuto==0) {
	if(skin_s[9]==1)
    dis[(mov1+7)][(mov2+14)]='_';
    else if(skin_s[8]==1)
    dis[(mov1+7)][(mov2+14)]='-';
    else
	dis[(mov1+7)][(mov2+14)]='-';
}
    if(tuto==0){
    mov_pos=(mov2-45+13);
    mov_pos1=(7-mov1+7);	
	}  
    else if(tuto==1){
    mov_pos=(tu_mov2-45+13+21);
    mov_pos1=(7-tu_mov1+7-4);	
	}
    
if(tu_dis[tu_mov1+7][tu_mov2+14]!='-'&&tu_dis[tu_mov1+7][tu_mov2+14]!='_')
tu_dis[(tu_mov1+7)][(tu_mov2+14)]='A';
else if(tu_dis[tu_mov1+7][tu_mov2+14]=='_')
tu_dis[(tu_mov1+7)][(tu_mov2+14)]='-';
    
if(tuto==1&&tu_phase==1&&tu_mov_test[0]==1&&tu_mov_test[1]==1&&tu_mov_test[2]==1&&tu_mov_test[3]==1){//phase 1   
    tu_phase+=1;
    if(tu_dis[9][17]!='A')
	tu_dis[9][17]='m';
    else if(tu_dis[9][17]=='A')
	tu_dis[9][33]='m';  
}
    if(tuto==1&&tu_phase==4){//phase 4   
	if(tu_dis[9][33]!='A'&&tu_dis[9][17]!='M')
	tu_dis[9][33]='M';
	else if(tu_dis[9][33]=='A'&&tu_dis[9][33]!='M')
	tu_dis[9][17]='M';  
}
    if(tuto==1&&tu_phase==5){//phase 5  
	tu_dis[16][25]='e';
}    
    
    
    
    if(dead==0){
    	textcolor(LIGHTGREEN, BLACK); 
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  XP  | ",level);
        if(xp*7>=mxp)
        printf(" ■");
        else
        printf(" □");
        if(xp*7>=2*mxp)
        printf(" ■");
        else
        printf(" □");
        if(xp*7>=3*mxp)
        printf(" ■");
        else
        printf(" □");
        if(xp*7>=4*mxp)
        printf(" ■");
        else
        printf(" □");
        if(xp*7>=5*mxp)
        printf(" ■");
        else
        printf(" □");
        if(xp*7>=6*mxp)
        printf(" ■");
        else
        printf(" □");
        if(xp*7>=7*mxp)
        printf(" ■");
        else
        printf(" □");
        
        if(inven%2==1||effect%2==1){
        	textcolor(LIGHTGREEN, BLACK);
        	if(lang==KOR) 
        	printf("     레벨 %d (%d / %d)",level,xp,mxp);
        	if(lang==ENG) 
        	printf("     LEVEL %d (%d / %d)",level,xp,mxp);
        }
       textcolor(RED, BLACK);
       if(lang==KOR)
       printf("\n 체력 | ");//\n┌─────────────────────────────┐
       if(lang==ENG)
       printf("\n  HP  | ");
       if(health*7>=m_health)
        printf(" ■");
        else
        printf(" □");
        if(health*7>=2*m_health)
        printf(" ■");
        else
        printf(" □");
        if(health*7>=3*m_health)
        printf(" ■");
        else
        printf(" □");
        if(health*7>=4*m_health)
        printf(" ■");
        else
        printf(" □");
        if(health*7>=5*m_health)
        printf(" ■");
        else
        printf(" □");
        if(health*7>=6*m_health)
        printf(" ■");
        else
        printf(" □");
        if(health*7>=7*m_health)
        printf(" ■");
        else
        printf(" □");
        
        if(inven%2==1||effect%2==1){
        	textcolor(RED, BLACK);
        	printf("     (%d / %d)",health,m_health);
        }
        textcolor(WHITE, BLACK);
        printf("\n┌─────────────────────────────┐ ");
    	
        if(inven%2==1){
    	printf(" ┌────────────────────────────────┐ ");//멥핑 출력 
    }
    if(effect%2==1&&inven%2==0){
    	printf(" ┌─────────────────────┐ ");//멥핑 출력 
    }
	i=0;
	j=0;
	
	
	
	
	printf(" \n");
	dhealth=m_health-100;
	if(tuto==0){                     //튜토리얼
			while(i<=12) {
        while(j<=28){
        	if(j==0) {
            printf("│");
        }
        if(i==6){
			if(j==14){
				if(dis[mov1+7][mov2+14]=='*'){
				if(skin_s[8]==1){
    	           textcolor(YELLOW, BLACK);	
				}	
	}
			}
		}
		printf("%c",dis[(mov1+i+1)][(mov2+j)]);
		    textcolor(WHITE, BLACK);
		if(j==28) {
            printf("│");
            if(inven%2==1){
		if(i==1){
			if(lang==KOR)
			printf("   동전⊙ : %d(%d)",coin,dcoin);
			if(lang==ENG)
			printf("   Coin⊙ : %d(%d)",coin,dcoin);
		}
		if(i==3){
			if(lang==KOR)
			printf("   보석ⓞ : %d(%d) ",jew,djew);
			if(lang==ENG)
			printf("   Gemⓞ : %d(%d)",jew,djew);
		}
		if(i==5){
			if(lang==KOR)
			printf("   열쇠¶ : %d(%d)",key,dkey);
			if(lang==ENG)
			printf("   Key¶ : %d(%d)",key,dkey);
		}
		if(i==7){
			if(lang==KOR)
			printf("   토큰◎ : %d(%d)",toc,dtoc);
			if(lang==ENG)
			printf("   Token ◎ : %d(%d)",toc,dtoc);
		}
		if(i==10){
			if(lang==KOR)
			printf("   갑옷장착 : r  무기장착 : R");
			if(lang==ENG)
			printf("   Armor : r  Weapon : R");
		}
		if(i==12){
			if(lang==KOR)
			printf("   나가기 : e ");
			if(lang==ENG)
			printf("   Out : e ");
		}
		}
		if(inven%2==0&&effect%2==1){
		if(i==1){
			if(lang==KOR)
			printf("   채력증가 : %d ",dhealth); 
			if(lang==ENG)
			printf("   Instant Hp : %d ",dhealth);
		}
		if(i==2){
			if(lang==KOR)
			printf("   공격력 : %f ",weapon); 
			if(lang==ENG)
			printf("   Power : %f ",weapon);
		}
		if(i==3){
			if(shield_s[6]!=1){
			if(lang==KOR)
			printf("   회피 : 0 ");	
			if(lang==ENG)
			printf("   Evasion : 0 ");	
			}			
			else{
			if(lang==KOR)
			printf("   회피 : 96 ");
			if(lang==ENG)
			printf("   Evasion : 96 ");	
			}
		}
		if(i==4){
			if(lang==KOR)
			printf("   방어도 : %f",shield);
			if(lang==ENG)
			printf("   Armor : %f",shield);
		}
		if(i==5){
			if(lang==KOR)
			printf("   무기 방어도 : %f",w_shield);
			if(lang==ENG)
			printf("   Shield : %f",w_shield);
		}
		if(i==6){
			if(shield_s[4]==0&&weapon_s[2]==0){
			if(lang==KOR)
			printf("   처치시 동전획득 : 0");
			if(lang==ENG)
			printf("   Coin On Kill: 0");	
		}	
			else if(shield_s[4]==1&&weapon_s[2]==0){
			if(lang==KOR) 
			printf("   처치시 동전획득 : 2");
			if(lang==ENG)
			printf("   Coin On Kill: 2");	
			}	
			else if(shield_s[4]==0&&weapon_s[2]==1){
			if(lang==KOR)
			printf("   처치시 동전획득 : 2");
			if(lang==ENG)
			printf("   Coin On Kill: 2");	
			}			
			else if(shield_s[4]==1&&weapon_s[2]==1){
			if(lang==KOR)
			printf("   처치시 동전획득 : 4");
			if(lang==ENG)
			printf("   Coin On Kill: 4");	
			}						
		}
		if(i==7){
			if(shield_s[5]!=1){
			if(lang==KOR)
			printf("   활동시 채력회복 : 0");
			if(lang==ENG)
			printf("   Recover On Acting : 0");	
			}		
			else {
			if(lang==KOR)
			printf("   활동시 채력회복 : 1");
			if(lang==ENG)
			printf("   Recover On Acting : 1");	
			}					
        	}
		if(i==8){
			if(lang==KOR)
			printf("   사거리 : %d",distance);
			if(lang==ENG)
			printf("   Intersection : %d",distance);
		}
		if(i==12){
			if(lang==KOR)
			printf("   나가기 : t ");
			if(lang==ENG)
			printf("   Out : t ");
		}
	}
		printf(" \n");
	}
	j+=1;
	}
      	j=0;
		i+=1; 
	}
	}
	else if(tuto==1){                     //튜토리얼
	i=0;
	j=0;
		while(i<=12) {
        while(j<=28){
        	if(j==0) {
            printf("│");
        }
		printf("%c",tu_dis[(tu_mov1+i+1)][(tu_mov2+j)]);
		    textcolor(WHITE, BLACK);
		if(j==28) {
            printf("│");
            if(inven%2==1){
	if(i==1){
			if(lang==KOR)
			printf("   동전⊙ : %d(%d)",coin,dcoin);
			if(lang==ENG)
			printf("   Coin⊙ : %d(%d)",coin,dcoin);
		}
		if(i==3){
			if(lang==KOR)
			printf("   보석ⓞ : %d(%d) ",jew,djew);
			if(lang==ENG)
			printf("   Gemⓞ : %d(%d)",jew,djew);
		}
		if(i==5){
			if(lang==KOR)
			printf("   열쇠¶ : %d(%d)",key,dkey);
			if(lang==ENG)
			printf("   Key¶ : %d(%d)",key,dkey);
		}
		if(i==7){
			if(lang==KOR)
			printf("   토큰◎ : %d(%d)",toc,dtoc);
			if(lang==ENG)
			printf("   Token ◎ : %d(%d)",toc,dtoc);
		}
		if(i==12){
			if(lang==KOR)
			printf("   나가기 : e ");
			if(lang==ENG)
			printf("   Out : e ");
		}
	}
		if(inven%2==0&&effect%2==1){
		if(i==1){
			if(lang==KOR)
			printf("   채력증가 : %d ",dhealth); 
			if(lang==ENG)
			printf("   Instant Hp : %d ",dhealth);
		}
		if(i==2){
			if(lang==KOR)
			printf("   공격력 : %f ",weapon); 
			if(lang==ENG)
			printf("   Power : %f ",weapon);
		}
		if(i==3){
			if(lang==KOR)
			printf("   회피 : 0 ");	
			if(lang==ENG)
			printf("   Evasion : 0 ");	
			}			
		if(i==4){
			if(lang==KOR)
			printf("   방어도 : %f",shield);
			if(lang==ENG)
			printf("   Armor : %f",shield);
		}
		if(i==5){
			if(lang==KOR)
			printf("   사거리 : %d",distance);
			if(lang==ENG)
			printf("   Intersection : %d",distance);
		}
		if(i==12){
			if(lang==KOR)
			printf("   나가기 : t ");
			if(lang==ENG)
			printf("   Out : t ");
		}
	}
	printf(" \n");
}
	j+=1;
}
      	j=0;
		i+=1; 
	}
}
	
	if(inven%2==0&&effect%2==0){
	if(lang==KOR)	
    printf("└─────────────────────────────┘ \n ( 나의 위치 : %d, %d )",mov_pos,mov_pos1);
    if(lang==ENG)
    printf("└─────────────────────────────┘ \n ( Position : %d, %d )",mov_pos,mov_pos1);
}
    else if(inven%2==1&&effect%2==0){
    	if(lang==KOR)
    	printf("└─────────────────────────────┘  └────────────────────────────────┘ \n ( 나의 위치 : %d, %d )",mov_pos,mov_pos1);
	if(lang==ENG)
	printf("└─────────────────────────────┘  └────────────────────────────────┘ \n ( Position : %d, %d )",mov_pos,mov_pos1);
	}
	if(inven%2==0&&effect%2==1){
		if(lang==KOR)
    	printf("└─────────────────────────────┘  └─────────────────────┘ \n ( 나의 위치 : %d, %d )",mov_pos,mov_pos1);
	if(lang==ENG)
	printf("└─────────────────────────────┘  └─────────────────────┘ \n ( Position : %d, %d )",mov_pos,mov_pos1);
	}
if(tuto==1&&tu_phase==1){
	if(lang==KOR)
printf("\n[w a s d 로 이동합니다]");
    if(lang==ENG)
    printf("\n[Move by 'w a s d']");
}
if(tuto==1&&tu_phase==2){
	if(lang==KOR)
printf("\n[q 는 상호작용입니다 상자 m 에 가까이가 여세요]");
    if(lang==ENG)
    printf("\n['q' is the interaction Close the chest 'm' and Open it]");
}
if(tuto==1&&tu_phase==3){
	if(lang==KOR)
printf("\n[e 로 인벤토리를 엽니다]");
    if(lang==ENG)
    printf("\n[Open inventory by 'e']");
}
if(tuto==1&&tu_phase==4){
	if(lang==KOR)
printf("\n[M은 잠긴 상자입니다 열쇠로 여세요]");
    if(lang==ENG)
    printf("\n['M' is locked chest Open it using key]");
}
if(tuto==1&&tu_phase==5){
	if(lang==KOR)
printf("\n[e 는 적이며 사거리에 들어오면 q 로 공격하세요]");
    if(lang==ENG)
	printf("\n['e' is enemy Attack by 'q' if you close it]");
}
if(tuto==1&&tu_phase==6){
	if(lang==KOR)
printf("\n[X는 잠금입니다 열쇠로 여세요]");
    if(lang==ENG)
    printf("\n['X' is the obstruct Open it using key]");
}
if(tuto==1&&tu_phase==7){
	if(tu_dis[9][25]=='!'){
	if(lang==KOR)
printf("\n[!은 npc입니다 튜토리얼을 완료하세요]");
    if(lang==ENG)
    printf("\n['!' is npc Complete the Tutorial]");	
	}
	else if(tu_dis[9][25]=='?'){
	if(lang==KOR)
printf("\n[?은 npc입니다 튜토리얼을 완료하세요]");
    if(lang==ENG)
    printf("\n['?' is npc Complete the Tutorial]");	
	}
	
}
}


else if(dead==1){
	dead_s=3;
	dis[mov1+7][mov2+14]=' ';
		mov1=14;
        mov2=32;
	while(dead_s>=1){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐\n");
	printf("│                             │ \n");
    printf("│                             │ \n"); 
	printf("│                             │ \n");
	printf("│                             │ \n");
	if(lang==KOR)
	printf("│          죽었습니다         │ \n");
	if(lang==ENG)
	printf("│         You're Died         │ \n");
	printf("│                             │ \n");
	printf("│  -------------------------  │ \n");	
	printf("│                             │ \n");
	if(lang==KOR)
	printf("│        %d초 후에 부활        │ \n",dead_s);
	if(lang==ENG)
	printf("│      Reviving later %ds      │ \n",dead_s);
	printf("│                             │ \n");
	printf("│                             │ \n");
	printf("│                             │ \n");
	printf("│                             │ \n");
	printf("└─────────────────────────────┘");
	
	Sleep(ONE_SECOND);
	dead_s-=1;	
	}
	dead=0;
	goto Display;
}    
    
    i=0;
	j=0;

    if(dis[mov1+6][mov2+14]=='e'||dis[mov1+8][mov2+14]=='e'||dis[mov1+7][mov2+15]=='e'||dis[mov1+7][mov2+13]=='e'){
    	if(shield_s[6]==0)
    	health-=(rand()%11+1)/(shield+w_shield);
		else if(shield_s[6]==1){
		if(rand()%100<=4)
		health-=1;	
		}	
		}                           //데미지 
	if(health<=0){
		health=m_health/3;           //데스 회복량 
		if(xp>=15)
		xp-=15;
		else{
		xp=0;
		}
        dead=1;
	}
	
	
	if(shield_s[5]==1){    //빵 갑옷 
	if(health<200&&rand()%10<=5)
		health+=1;
	}




    while(True) {                                                                        //키 감지 
        mov_but=_getch();
        if(mov_but=='w'&&tuto==0) {
            if(dis[mov1+6][mov2+14]==' ') {                                               //움직임 
                if(mov1>=2) {
                	if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					if(mon_mov1-mov1-7>=1){
    	if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		}
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	else if(mov1-mon_mov1+7>=1){
    	if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mon_mov2-mov2-14>=1){
    	if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mov2-mon_mov2+14>=1){
    	if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	
                    mov1-=1;
                    goto Display;
                }
            }
            else if(dis[mov1+6][mov2+14]=='_') {
                if(mov1>=2) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
                    mov1-=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='w'&&tuto==1) {
            if(tu_dis[tu_mov1+6][tu_mov2+14]==' ') {                                               //움직임 
                if(tu_mov1>=2) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }
                else if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
	
                    tu_mov1-=1;
                    tu_mov_test[0]=1;
                    goto Display;
                }
            }
            else if(tu_dis[tu_mov1+6][tu_mov2+14]=='_') {
                if(tu_mov1>=2) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-'&&tu_dis[tu_mov1+7][tu_mov2+14]!='_') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }

                		if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
                    tu_mov1-=1;
                    tu_mov_test[0]=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='s'&&tuto==0) {
            if(dis[mov1+8][mov2+14]==' ') {
                if(mov1<=28) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					if(mon_mov1-mov1-7>=1){
    	if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		}
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	else if(mov1-mon_mov1+7>=1){
    	if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mon_mov2-mov2-14>=1){
    	if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mov2-mon_mov2+14>=1){
    	if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
                    mov1+=1;
                    goto Display;
                }
            }
            else if(dis[mov1+8][mov2+14]=='_') {
                if(mov1<=28) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
                    mov1+=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='s'&&tuto==1) {
            if(tu_dis[tu_mov1+8][tu_mov2+14]==' ') {                                               //움직임 
                if(tu_mov1<=13) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }
                else if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
	
                    tu_mov1+=1;
                    tu_mov_test[1]=1;
                    goto Display;
                }
            }
            else if(tu_dis[tu_mov1+8][tu_mov2+14]=='_') {
                if(tu_mov1<=13) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-'&&tu_dis[tu_mov1+7][tu_mov2+14]!='_') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }

                		if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
                    tu_mov1+=1;
                    tu_mov_test[2]=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='a'&&tuto==0) {
            if(dis[mov1+7][mov2+13]==' ') {
                if(mov2!=0) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					if(mon_mov1-mov1-7>=1){
    	if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		}
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	else if(mov1-mon_mov1+7>=1){
    	if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mon_mov2-mov2-14>=1){
    	if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mov2-mon_mov2+14>=1){
    	if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
                    mov2-=1;
                    goto Display;
                }
            }
            else if(dis[mov1+7][mov2+13]=='_') {
                if(mov2!=1) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
                    mov2-=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='a'&&tuto==1) {
            if(tu_dis[tu_mov1+7][tu_mov2+13]==' ') {                                               //움직임 
                if(tu_mov2!=0) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }
                else if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
	
                    tu_mov2-=1;
                    tu_mov_test[2]=1;
                    goto Display;
                }
            }
            else if(tu_dis[tu_mov1+7][tu_mov2+13]=='_') {
                if(tu_mov2!=0) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-'&&tu_dis[tu_mov1+7][tu_mov2+14]!='_') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }

                	 if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
                    tu_mov2-=1;
                    tu_mov_test[2]=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='d'&&tuto==0) {
            if(dis[mov1+7][mov2+15]==' ') {
                if(mov2!=64) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					if(mon_mov1-mov1-7>=1){
    	if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		}
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	else if(mov1-mon_mov1+7>=1){
    	if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==1){
			if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mon_mov2-mov2-14>=1){
    	if(dis[mon_mov1][mon_mov2-1]==' '){
				mon_mov2-=1;
    		dis[mon_mov1][mon_mov2+1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
	else if(mov2-mon_mov2+14>=1){
    	if(dis[mon_mov1][mon_mov2+1]==' '){
				mon_mov2+=1;
    		dis[mon_mov1][mon_mov2-1]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		else{
		srand(time(NULL));
		if(rand()%2==0){
			if(dis[mon_mov1+1][mon_mov2]==' '){
				mon_mov1+=1;
    		dis[mon_mov1-1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
		else{
			if(dis[mon_mov1-1][mon_mov2]==' '){
				mon_mov1-=1;
    		dis[mon_mov1+1][mon_mov2]=' ';
    	dis[mon_mov1][mon_mov2]='e';
		}
		}
	}
	}
                    mov2+=1;
                    goto Display;
                }
            }
            else if(dis[mov1+7][mov2+15]=='_') {
                if(mov2!=64) {
                    if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]!='_'&&dis[mov1+7][mov2+14]!='-'&&dis[mov1+7][mov2+14]!='-') {
                    dis[mov1+7][mov2+14]=' ';
                }
					}
                	
                if(skin_s[9]==1){
                		if(dis[mov1+7][mov2+14]=='_') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else if(skin_s[8]==1){
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
					else{
                		if(dis[mov1+7][mov2+14]=='-') {
                    dis[mov1+7][mov2+14]='_';
                }
					}
                    mov2+=1;
                    goto Display;
                }
            }
            goto Display;
        }
         else if(mov_but=='d'&&tuto==1) {
            if(tu_dis[tu_mov1+7][tu_mov2+15]==' ') {                                               //움직임 
                if(tu_mov2!=22) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }
                else if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
	
                    tu_mov2+=1;
                    tu_mov_test[3]=1;
                    goto Display;
                }
            }
            else if(tu_dis[tu_mov1+7][tu_mov2+15]=='_') {
                if(tu_mov2!=22) {
                		if(tu_dis[tu_mov1+7][tu_mov2+14]!='-'&&tu_dis[tu_mov1+7][tu_mov2+14]!='_') {
                    tu_dis[tu_mov1+7][tu_mov2+14]=' ';
                }

                		if(tu_dis[tu_mov1+7][tu_mov2+14]=='-') {
                    tu_dis[tu_mov1+7][tu_mov2+14]='_';
                }
                    tu_mov2+=1;
                    tu_mov_test[3]=1;
                    goto Display;
                }
            }
            goto Display;
        }
        else if(mov_but=='q'){                                                      // 상호작용 
        	if(dis[mov1+6][mov2+14]=='e'){                                              //몬스터 삭제 
        if(rand()%1000<=weapon*500)
		dis[mov1+6][mov2+14]=' ';
		else
        goto Display;
        if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
}
        else if(dis[mov1+8][mov2+14]=='e'){
        	if(rand()%1000<=weapon*500)
        dis[mov1+8][mov2+14]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
        else if(dis[mov1+7][mov2+15]=='e'){
        	if(rand()%1000<=weapon*500)
        dis[mov1+7][mov2+15]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
        else if(dis[mov1+7][mov2+13]=='e'){
        	if(rand()%1000<=weapon*500)
        dis[mov1+7][mov2+13]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
		else if(dis[mov1+9][mov2+14]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+9][mov2+14]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+10][mov2+14]=='e'&&distance>=3){
        	if(rand()%1000<=weapon*500)
        dis[mov1+10][mov2+14]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+5][mov2+14]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+5][mov2+14]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+4][mov2+14]=='e'&&distance>=3){
        	if(rand()%1000<=weapon*500)
        dis[mov1+4][mov2+14]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+7][mov2+12]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+7][mov2+12]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}else if(dis[mov1+7][mov2+11]=='e'&&distance>=3){
        	if(rand()%1000<=weapon*500)
        dis[mov1+7][mov2+11]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
	     mon_kill();
	}
	else if(dis[mov1+7][mov2+16]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+7][mov2+16]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+7][mov2+17]=='e'&&distance>=3){
        	if(rand()%1000<=weapon*500)
        dis[mov1+7][mov2+17]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
	     mon_kill();
	}
	else if(dis[mov1+8][mov2+13]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+8][mov2+13]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+8][mov2+15]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+8][mov2+15]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		mon_kill();
	}
	else if(dis[mov1+6][mov2+13]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+6][mov2+13]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
		int mon_kill();
	}
	else if(dis[mov1+6][mov2+15]=='e'&&distance>=2){
        	if(rand()%1000<=weapon*500)
        dis[mov1+6][mov2+15]=' ';
        else
        goto Display;
         if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
		}
	     mon_kill();
	}
	 
	if(distance==10){
		i=0;
	j=0;
	while(i<=44){
		while(j<=90){
			if(dis[i][j]=='e'){
				if(rand()%1000<=weapon*500){
					dis[i][j]=' ';
        if(rand()%4==0){
        	mon_mov1=13;
        	mon_mov2=45;
		}
		else if(rand()%4==1){
        	mon_mov1=25;
        	mon_mov2=45;
		}
		else if(rand()%4==2){
        	mon_mov1=20;
        	mon_mov2=60;
		}
		else{
        	mon_mov1=20;
        	mon_mov2=28;
			}
		 mon_kill();
	     goto Display;
				}	
		}
		j+=1;
		}
		j=0;
	i+=1;
	}
	i=0;
	j=0;
	}                                                                                  //몬스터 삭제 
	
			if(dis[mov1+8][mov2+14]=='m') {
        		dis[mov1+8][mov2+14]=' ';
        		mchest();    		
		}
		else if(dis[mov1+6][mov2+14]=='m') {
			dis[mov1+6][mov2+14]=' ';
			mchest();
		}
		else if(dis[mov1+7][mov2+15]=='m') {
			dis[mov1+7][mov2+15]=' ';
			mchest();
		}
		else if(dis[mov1+7][mov2+13]=='m') {
			dis[mov1+7][mov2+13]=' ';
			mchest();
		}
		if(tuto==1){    //튜토리얼 
		if(tu_dis[tu_mov1+8][tu_mov2+14]=='m') {
        		dis[tu_mov1+8][tu_mov2+14]=' ';
        		coin+=3;
				key+=2;
				dcoin=3;
				dkey=2;  
				tu_phase+=1;  		
		}
		else if(tu_dis[tu_mov1+6][tu_mov2+14]=='m') {
			tu_dis[tu_mov1+6][tu_mov2+14]=' ';
			coin+=3;
				key+=2;
				dcoin=3;
				dkey=2;  
				tu_phase+=1;
		}
		else if(tu_dis[tu_mov1+7][tu_mov2+15]=='m') {
			tu_dis[tu_mov1+7][tu_mov2+15]=' ';
			coin+=3;
				key+=2;
				dcoin=3;
				dkey=2;  
				tu_phase+=1;
		}
		else if(tu_dis[tu_mov1+7][tu_mov2+13]=='m') {
			tu_dis[tu_mov1+7][tu_mov2+13]=' ';
			coin+=3;
				key+=2;
				dcoin=3;
				dkey=2;  
				tu_phase+=1;
			}
		if(tu_dis[tu_mov1+8][tu_mov2+14]=='M') {
        		tu_dis[tu_mov1+8][tu_mov2+14]=' ';
        		coin+=5;
				dcoin=5;
				key-=1;
				dkey=-1;
				tu_phase+=1;  		
		}
		else if(tu_dis[tu_mov1+6][tu_mov2+14]=='M') {
			tu_dis[tu_mov1+6][tu_mov2+14]=' ';
			coin+=5;
				dcoin=5;
				key-=1;
				dkey=-1;
				tu_phase+=1;
		}
		else if(tu_dis[tu_mov1+7][tu_mov2+15]=='M') {
			tu_dis[tu_mov1+7][tu_mov2+15]=' ';
			coin+=5;
				dcoin=5;
				key-=1;
				dkey=-1;
				tu_phase+=1;
		}
		else if(tu_dis[tu_mov1+7][tu_mov2+13]=='M') {
			tu_dis[tu_mov1+7][tu_mov2+13]=' ';
			coin+=5;
				dcoin=5;
				key-=1;
				dkey=-1;
				tu_phase+=1;			
		}
		if(tu_dis[tu_mov1+8][tu_mov2+14]=='e') {
        		tu_dis[tu_mov1+8][tu_mov2+14]=' ';
        		health-=10;
        		toc+=1;
        		dtoc=1;
				tu_phase+=1;  		
		}
		else if(tu_dis[tu_mov1+6][tu_mov2+14]=='e') {
			tu_dis[tu_mov1+6][tu_mov2+14]=' ';
			health-=10;
			toc+=1;
        		dtoc=1;
				tu_phase+=1;
		}
		else if(tu_dis[tu_mov1+7][tu_mov2+15]=='e') {
			tu_dis[tu_mov1+7][tu_mov2+15]=' ';
			health-=10;
			toc+=1;
        		dtoc=1;
				tu_phase+=1;
		}
		else if(tu_dis[tu_mov1+7][tu_mov2+13]=='e') {
			tu_dis[tu_mov1+7][tu_mov2+13]=' ';
			health-=10;
			toc+=1;
        		dtoc=1;
				tu_phase+=1;			
		}
		if(tu_dis[12][25]=='A'&&tu_phase==6){
			key-=1;
			dkey=-1;
			tu_dis[11][25]=' ';
			tu_phase+=1;
			
		}
	}
		
		
		
		
		if(dis[mov1+8][mov2+14]=='w') {
        		dis[mov1+8][mov2+14]=' ';
        		wchest();    		
		}
		else if(dis[mov1+6][mov2+14]=='w') {
			dis[mov1+6][mov2+14]=' ';
			wchest();
		}
		else if(dis[mov1+7][mov2+15]=='w') {
			dis[mov1+7][mov2+15]=' ';
			wchest();
		}
		else if(dis[mov1+7][mov2+13]=='w') {
			dis[mov1+7][mov2+13]=' ';
			wchest();
		}
		
		if(key>=1){
		if(dis[mov1+8][mov2+14]=='M') {
        		dis[mov1+8][mov2+14]=' ';
        		Mchest();
		}
		else if(dis[mov1+6][mov2+14]=='M') {
			dis[mov1+6][mov2+14]=' ';
			Mchest();
		}
		else if(dis[mov1+7][mov2+15]=='M') {
			dis[mov1+7][mov2+15]=' ';
			Mchest();
		}
		else if(dis[mov1+7][mov2+13]=='M') {
			dis[mov1+7][mov2+13]=' ';
			Mchest();
		}
		
}
		if(key>=1){
		if(dis[mov1+8][mov2+14]=='X') {                                                    //닫힘 벽 
        		dis[mov1+8][mov2+14]=' ';  
			key-=1;
    dkey=-1;
	xp+=5;		
		}
		else if(dis[mov1+6][mov2+14]=='X') {
			dis[mov1+6][mov2+14]=' ';
	key-=1;
    dkey=-1;
    xp+=5;	
		}
		else if(dis[mov1+7][mov2+15]=='X') {
			dis[mov1+7][mov2+15]=' ';
	key-=1;
    dkey=-1;
    xp+=5;	
		}
		else if(dis[mov1+7][mov2+13]=='X') {
			dis[mov1+7][mov2+13]=' ';
	key-=1;
    dkey=-1;	
    xp+=5;	
	}
	
	}
	
	if(tuto==0){
	if(dis[29][41]==dis[mov1+7][mov2+14]) {                                                         // NPC 감지 
        	skin();   		
		}
		else if(dis[27][41]==dis[mov1+7][mov2+14]) {
			skin(); 
		}
		else if(dis[28][42]==dis[mov1+7][mov2+14]) {
			skin(); 
		}
		else if(dis[28][40]==dis[mov1+7][mov2+14]) {
			skin(); 
		}
	if(dis[29][51]==dis[mov1+7][mov2+14]) {
        	sel_skin();   		
		}
		else if(dis[27][51]==dis[mov1+7][mov2+14]) {
			sel_skin(); 
		}
		else if(dis[28][52]==dis[mov1+7][mov2+14]) {
			sel_skin(); 
		}
		else if(dis[28][50]==dis[mov1+7][mov2+14]) {
			sel_skin(); 
		}
	if(dis[19][51]==dis[mov1+7][mov2+14]) {
        	store();    		
		}
		else if(dis[17][51]==dis[mov1+7][mov2+14]) {
			store();  
		}
		else if(dis[18][52]==dis[mov1+7][mov2+14]) {
			store();  
		}
		else if(dis[18][50]==dis[mov1+7][mov2+14]) {
			store(); 
		}	
    if(dis[24][21]==dis[mov1+7][mov2+14]) {
        	heal();    		
		}
		else if(dis[26][21]==dis[mov1+7][mov2+14]) {
			heal();    
		}
		else if(dis[25][20]==dis[mov1+7][mov2+14]) {
			heal();    
		}
		else if(dis[25][22]==dis[mov1+7][mov2+14]) {
			heal();   
		}
	if(dis[26][70]==dis[mov1+7][mov2+14]) {
        	sword();    		
		}
		else if(dis[28][70]==dis[mov1+7][mov2+14]) {
			sword();     
		}
		else if(dis[27][71]==dis[mov1+7][mov2+14]) {
			sword();   
		}
		else if(dis[27][69]==dis[mov1+7][mov2+14]) {
			sword(); 
		}
	}
	if(tuto==1){
	if(tu_dis[10][25]==tu_dis[tu_mov1+7][tu_mov2+14]) {            //튜토리얼 종료 
        	tu_sel();   		
		}
		else if(tu_dis[8][25]==tu_dis[tu_mov1+7][tu_mov2+14]) {
			tu_sel();   	     
		}
		else if(tu_dis[9][26]==tu_dis[tu_mov1+7][tu_mov2+14]) {
			tu_sel();   	   
		}
		else if(tu_dis[9][24]==tu_dis[tu_mov1+7][tu_mov2+14]) {
			tu_sel();   	
		} 

    	
	} 
	goto Display; 
}
    else if(mov_but=='e'){//인벤토리 
    	if(effect%2==0){
		inven+=1;
		if(tuto==1&&tu_phase==3)
		tu_phase+=1;
	}
    	goto Display;
    	
	}
	else if(mov_but=='r'&&tuto==0){//인벤토리 
    	if(inven%2==1){
    		sel_heal();
		} 
		goto Display;  	
	}
	else if(mov_but=='R'&&tuto==0){//인벤토리 
    	if(inven%2==1){
    		sel_weapon();
		} 
		goto Display;  	
	}
	else if(mov_but=='t'){//인벤토리 
    	if(inven%2==0){
    		effect+=1;
		} 
		goto Display;  	
	}
	else if(mov_but=='|'&&tuto==0){
	 i=0;
	while(i<=9){
		weapon_m[i]=1;
		i+=1;
	}
	i=0;
    i=0;
	while(i<=8){
		shield_m[i]=1;
		i+=1;
	}
	i=0;
	while(i<=10){
		skin_m[i]=1;
		i+=1;
	}
	i=0;
}
}
}









int mchest(void){// 상자 
	if(rand()%100<=20){
		coin+=1;
		dcoin=1;
		xp+=3;
	}
	else if(rand()%100>=21&&rand()%100<=40){
		coin+=4;
		dcoin=4;
		xp+=3;
	}
	else if(rand()%100>=41&&rand()%100<=65){
		coin+=3;
		dcoin=3;
		xp+=3;
	}
	else if(rand()%100>=66&&rand()%100<=90){
		coin+=2;
		dcoin=2;
		xp+=3;
	}
	else{
		coin+=5;
		dcoin=5;
		xp+=4;
	}
	
	if(rand()%100<=55){
		key+=1;
		dkey=1;
	}
	
	
}

int wchest(void){//보석 상자 
	if(rand()%100<=44){
		jew+=1;
		djew=1;
	}
	else if(rand()%100>=45&&rand()%100<=79){
		jew+=2;
		djew=2;
	}
	else{
		jew+=3;
		djew=3;
}
	
}

int Mchest(void){// 큰상자 
	if(rand()%100<=5){
		coin+=1;
		dcoin=1;
		xp+=10;
	}
	else if(rand()%100>=6&&rand()%100<=20){
		coin+=4;
		dcoin=4;
		xp+=8;
	}
	else if(rand()%100>=21&&rand()%100<=38){
		coin+=5;
		dcoin=5;
		xp+=8;
	}
	else if(rand()%100>=39&&rand()%100<=60){
		coin+=6;
		dcoin=6;
		xp+=8;
	}
	else if(rand()%100>=61&&rand()%100<=70){
		coin+=7;
		dcoin=7;
		xp+=8;
	}
	else if(rand()%100>=71&&rand()%100<=79){
		coin+=8;
		dcoin=8;
		xp+=9;
	}
	else if(rand()%100>=80&&rand()%100<=86){
		coin+=9;
		dcoin=9;
		xp+=9;
	}
	else if(rand()%100>=87&&rand()%100<=94){
		coin+=10;
		dcoin=10;
		xp+=8;
	}
	else{
		coin+=15;
		dcoin=15;
		xp+=12;
	}
	if(rand()%100>=14&&rand()%100<=20){
		jew+=2;
		djew=2;
	}
	else if(rand()%100>=53&&rand()%100<=60){
		jew+=3;
		djew=3;
	}
	else if(rand()%100>=94&&rand()%100<=96){
		jew+=4;
		djew=4;
}
	key-=1;
	dkey=-1;
	
}


int chestset(void){// 상자 배치 
	 i,j=0;
    srand((unsigned int)time(NULL));
    while(i<=40){
    	while(j<=88){    		
    		if(rand()%500<=3&&xp==0&&level==1){
    if(rand()%100<=81){
        if(dis[i+1][j+3]==' '||dis[i+1][j+3]=='_'){
    	dis[i+1][j+3]='m';
        }
	}
	else{
		if(dis[i+1][j+3]==' '||dis[i+1][j+3]=='_'){
    	dis[i+1][j+3]='M';
        }
	}	
			}
			if(rand()%500<=3&&xp!=0&&level!=1){      //처음 상자 배치가 아닐때  
    if(rand()%100<=81){
        if(dis[i+1][j+3]==' '){
    	dis[i+1][j+3]='m';
        }
	}
	else{
		if(dis[i+1][j+3]==' '){
    	dis[i+1][j+3]='M';
        }
	}	
			}   		
	j+=1;
		}
    j=0;
	i+=1;
	}
	i=0;
	j=0;
	
	while(i<=10){
		while(j<=16){
			if(dis[i+16][j+38]=='m'||dis[i+16][j+38]=='M')
			dis[i+16][j+38]=' ';
			j+=1;
		}
		j=0;
		i+=1;
	}
	i=0;
	j=0;
}

int buildset(void){                                // 집 배치 
srand((unsigned int)time(NULL));
    build(7,14,3,DIS);
    build(16,14,4,DIS);
    build(7,45,3,DIS);
    build(7,59,2,DIS);
    build(12,74,2,DIS);
    build(17,74,2,DIS);
    build(33,45,1,DIS);
    build(33,66,2,DIS);
    build(33,73,1,DIS);
    build(33,37,1,DIS);
    build(33,14,4,DIS);
    build(28,14,4,DIS);
	
}

int build(int y, int x, int door, int tuto){                            //집 
	if(tuto==TU_DIS){
	tu_dis[y][x]='O';
	tu_dis[y][x+1]='o';
	tu_dis[y][x+2]='o';
	tu_dis[y][x+3]='o';
	tu_dis[y][x+4]='o';
	tu_dis[y][x+5]='o';
	tu_dis[y][x+6]='O';
	tu_dis[y+1][x]='8';
	tu_dis[y+2][x]='8';
	tu_dis[y+3][x]='8';
	tu_dis[y+4][x]='O';
	tu_dis[y+1][x+6]='8';
	tu_dis[y+2][x+6]='8';
	tu_dis[y+3][x+6]='8';
	tu_dis[y+4][x+1]='o';
	tu_dis[y+4][x+2]='o';
	tu_dis[y+4][x+3]='o';
	tu_dis[y+4][x+4]='o';
	tu_dis[y+4][x+5]='o';
	tu_dis[y+4][x+6]='O';
	if(door==1){
		tu_dis[y][x+3]=' ';
	}
	else if(door==2){
		tu_dis[y+2][x]=' ';
	}
	else if(door==4){
		tu_dis[y+2][x+6]=' ';
	}
	else if(door==3){
		tu_dis[y+4][x+3]=' ';
	}	
	}
	
if(tuto==DIS){	
dis[y][x]='O';
	dis[y][x+1]='o';
	dis[y][x+2]='o';
	dis[y][x+3]='o';
	dis[y][x+4]='o';
	dis[y][x+5]='o';
	dis[y][x+6]='O';
	dis[y+1][x]='8';
	dis[y+2][x]='8';
	dis[y+3][x]='8';
	dis[y+4][x]='O';
	dis[y+1][x+6]='8';
	dis[y+2][x+6]='8';
	dis[y+3][x+6]='8';
	dis[y+4][x+1]='o';
	dis[y+4][x+2]='o';
	dis[y+4][x+3]='o';
	dis[y+4][x+4]='o';
	dis[y+4][x+5]='o';
	dis[y+4][x+6]='O';
if(rand()%100<=68){
	if(door==1){
		dis[y][x+3]=' ';
	}
	else if(door==2){
		dis[y+2][x]=' ';
	}
	else if(door==4){
		dis[y+2][x+6]=' ';
	}
	else if(door==3){
		dis[y+4][x+3]=' ';
	}
}
else{
	if(door==1){
		dis[y][x+3]='X';
	}
	else if(door==2){
		dis[y+2][x]='X';
	}
	else if(door==4){
		dis[y+2][x+6]='X';
	}
	else if(door==3){
		dis[y+4][x+3]='X';
	}
}
if(dis[y][x+3]=='X'||dis[y+2][x]=='X'||dis[y+2][x+6]=='X'||dis[y+4][x+3]=='X'){
	while(i<=2){
		while(j<=4){
			if(rand()%100<=20){
				if(rand()%100<=67){
				dis[i+y+1][j+x+1]='m';	
				}
    	else{
    	dis[i+y+1][j+x+1]='w';
        }
        }
			j+=1;
		}
		j=0;
		i+=1;
	}
	i=0;
	j=0;
}
}
   return 0;
}

int bush(int y, int x, int tuto){                                                                        //덤불 
	if(tuto==TU_DIS){
		tu_dis[y][x]='_';
	tu_dis[y][x+1]='_';
	tu_dis[y][x+2]='_';
	tu_dis[y][x+3]='_';
	tu_dis[y][x+4]='_';
	tu_dis[y+1][x]='_';
	tu_dis[y+1][x+1]='_';
	tu_dis[y+1][x+2]='_';
	tu_dis[y+1][x+3]='_';
	tu_dis[y+1][x+4]='_';
	tu_dis[y+2][x]='_';
	tu_dis[y+2][x+1]='_';
	tu_dis[y+2][x+2]='_';
	tu_dis[y+2][x+3]='_';
	tu_dis[y+2][x+4]='_';
	}
	else if(tuto==DIS){
		dis[y][x]='_';
	dis[y][x+1]='_';
	dis[y][x+2]='_';
	dis[y][x+3]='_';
	dis[y][x+4]='_';
	dis[y+1][x]='_';
	dis[y+1][x+1]='_';
	dis[y+1][x+2]='_';
	dis[y+1][x+3]='_';
	dis[y+1][x+4]='_';
	dis[y+2][x]='_';
	dis[y+2][x+1]='_';
	dis[y+2][x+2]='_';
	dis[y+2][x+3]='_';
	dis[y+2][x+4]='_';
	}
	
	return 0;
}

int wall(int y, int x, int turn, int tuto){                                                                   //벽 
	if(tuto==TU_DIS){
		if(turn==1){
		tu_dis[y][x]='O';
	tu_dis[y][x+1]='o';
	tu_dis[y][x+2]='o';
	tu_dis[y][x+3]='o';
	tu_dis[y][x+4]='o';
	tu_dis[y][x+4]='O';
	}
	else if(turn==2){
		tu_dis[y][x]='O';
	tu_dis[y+1][x]='8';
	tu_dis[y+2][x]='O';
	}
	}
	else if(tuto==DIS){
		if(turn==1){
		dis[y][x]='O';
	dis[y][x+1]='o';
	dis[y][x+2]='o';
	dis[y][x+3]='o';
	dis[y][x+4]='o';
	dis[y][x+4]='O';
	}
	else if(turn==2){
		dis[y][x]='O';
	dis[y+1][x]='8';
	dis[y+2][x]='O';
	}
	}
	
 return 0;
}


int sk_selected=0;
int sel_skin(){ 
dis[28][51]='?';                                                                                          //스킨 선택 
	selplus=sk_selected;
	selr[sk_selected]=']';
    sell[sk_selected]='[';
	sel_point :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ \n");
       printf("│          외형 선택          │ \n"); 
	   printf("│ ----------------------------│ \n"); 
	   printf("│                             │ \n"); 
	    if(skin_m[0]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[0],selr[0]);
	   else if(skin_m[0]==1&&skin_s[0]==0)
	   printf("│       %c A : 선택하기 %c      │ \n",sell[0],selr[0]);
	   else if(skin_m[0]==1&&skin_s[0]==1)
	   printf("│       %c A : 선택 중 %c       │ \n",sell[0],selr[0]);  
	   if(skin_m[1]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[1],selr[1]);
	   else if(skin_m[1]==1&&skin_s[1]==0)
	   printf("│       %c B : 선택하기 %c      │ \n",sell[1],selr[1]);
	   else if(skin_m[1]==1&&skin_s[1]==1)
	   printf("│       %c B : 선택 중 %c       │ \n",sell[1],selr[1]); 
	   if(skin_m[2]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[2],selr[2]);
	   else if(skin_m[2]==1&&skin_s[2]==0)
	   printf("│       %c C : 선택하기 %c      │ \n",sell[2],selr[2]);
	   else if(skin_m[2]==1&&skin_s[2]==1)
	   printf("│       %c C : 선택 중 %c       │ \n",sell[2],selr[2]);
	   if(skin_m[3]==0) 
	   printf("│          %c 미발견 %c         │ \n",sell[3],selr[3]);
	   else if(skin_m[3]==1&&skin_s[3]==0)
	   printf("│       %c D : 선택하기 %c      │ \n",sell[3],selr[3]);
	   else if(skin_m[3]==1&&skin_s[3]==1)
	   printf("│       %c D : 선택 중 %c       │ \n",sell[3],selr[3]);
	   if(skin_m[4]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[4],selr[4]);
	   else if(skin_m[4]==1&&skin_s[4]==0)
	   printf("│       %c E : 선택하기 %c      │ \n",sell[4],selr[4]);
	   else if(skin_m[4]==1&&skin_s[4]==1)
	   printf("│       %c E : 선택 중 %c       │ \n",sell[4],selr[4]);
	   if(skin_m[5]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[5],selr[5]);
	   else if(skin_m[5]==1&&skin_s[5]==0)
	   printf("│       %c F : 선택하기 %c      │ \n",sell[5],selr[5]);
	   else if(skin_m[5]==1&&skin_s[5]==1)
	   printf("│       %c F : 선택 중 %c       │ \n",sell[5],selr[5]);
	   if(skin_m[6]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[6],selr[6]);
	   else if(skin_m[6]==1&&skin_s[6]==0)
	   printf("│       %c @ : 선택하기 %c      │ \n",sell[6],selr[6]);
	   else if(skin_m[6]==1&&skin_s[6]==1)
	   printf("│       %c @ : 선택 중 %c       │ \n",sell[6],selr[6]);
	   if(skin_m[7]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[7],selr[7]);
	   else if(skin_m[7]==1&&skin_s[7]==0)
	   printf("│       %c # : 선택하기 %c      │ \n",sell[7],selr[7]);
	   else if(skin_m[7]==1&&skin_s[7]==1)
	   printf("│       %c # : 선택 중 %c       │ \n",sell[7],selr[7]);
	   if(skin_m[8]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[8],selr[8]);
	   else if(skin_m[8]==1&&skin_s[8]==0)
	   printf("│       %c * : 선택하기 %c      │ \n",sell[8],selr[8]);
	   else if(skin_m[8]==1&&skin_s[8]==1)
	   printf("│       %c * : 선택 중 %c       │ \n",sell[8],selr[8]);
	   if(skin_m[9]==0) 
	   printf("│          %c 미발견 %c         │ \n",sell[9],selr[9]);
	   else if(skin_m[9]==1&&skin_s[9]==0)
	   printf("│       %c . : 선택하기 %c      │ \n",sell[9],selr[9]);
	   else if(skin_m[9]==1&&skin_s[9]==1)
	   printf("│       %c . : 선택 중 %c       │ \n",sell[9],selr[9]);
	   if(skin_m[10]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[10],selr[10]);
	   else if(skin_m[10]==1&&skin_s[10]==0)
	   printf("│       %c K : 선택하기 %c      │ \n",sell[10],selr[10]);
	   else if(skin_m[10]==1&&skin_s[10]==1)
	   printf("│       %c K : 선택 중 %c       │ \n",sell[10],selr[10]);
	   printf("│                             │\n"); 
	   printf("│  위/아래 : w/s  선택 : e    │\n│  나가기 : q                 │ \n");
	       
	

    	printf("└─────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='q'){
        	i=0;
        	while(i<=10){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=10){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==11){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto sel_point;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=10;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto sel_point;
		}
		if(mov_but=='e'){
		if(selplus==0){
			if(skin_m[0]==1){
			skin_z();
			skin_s[0]=1;
			sk_selected=0; 	
			}
		}
	    else if(selplus==1){
	    	if(skin_m[1]==1){
	    	skin_z();
			skin_s[1]=1;
			sk_selected=1; 	
	    	}
		}  
		else if(selplus==2){
			if(skin_m[2]==1){
	    	skin_z();
			skin_s[2]=1; 
			sk_selected=2;	
	    	}
		}	
		else if(selplus==3){
			if(skin_m[3]==1){
	    		
	    	}
			skin_z();
			skin_s[3]=1;
			sk_selected=3; 
			
		}
		else if(selplus==4){
			if(skin_m[4]==1){
	    	skin_z();
			skin_s[4]=1;
			sk_selected=4;	
	    	}
		}
		else if(selplus==5){
			if(skin_m[5]==1){
	    	skin_z();
			skin_s[5]=1;
			sk_selected=5;	
	    	}
		}
		else if(selplus==6){
			if(skin_m[6]==1){
	    	skin_z();
			skin_s[6]=1; 
			sk_selected=6;	
	    	}	
		}
		else if(selplus==7){
			if(skin_m[7]==1){
	    	skin_z();
			skin_s[7]=1;
			sk_selected=7;	
	    	}
		}
		else if(selplus==8){
			if(skin_m[8]==1){
	    	skin_z();
			skin_s[8]=1;
			sk_selected=8; 	
	    	}	
		}
		else if(selplus==9){
			if(skin_m[9]==1){
	    	skin_z();
			skin_s[9]=1; 
			sk_selected=9;	
	    	}
        }
        else if(selplus==10){
			if(skin_m[10]==1){
	    	skin_z();
			skin_s[10]=1;
			sk_selected=10; 	
	    	}
}

		goto sel_point;
		}
		
    }
	
}

int skin_z(void){                                                                             //스킨 선택  등 초기화 
	i=0;
	while(i<=10){
		skin_s[i]=0;
		i+=1;
	}
	i=0;
}







int skin(void){  
dis[28][41]='?';                                                                                 //스킨 
	selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
	store :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ ");
    printf(" ┌────────────────────────────────┐ \n");
       printf("│          외형 상점          │ \n"); 
	   printf("│ ----------------------------│   동전⊙ : %d(%d)      \n",coin,dcoin); 
	   printf("│                             │ \n"); 
	   if(skin_m[1]==0)
	   printf("│       %c B : 동전 20 %c       │   보석ⓞ : %d(%d)                        \n",sell[0],selr[0],jew,djew);
	   if(skin_m[1]==1)
	   printf("│       %c B : 구매완료 %c      │   보석ⓞ : %d(%d)                        \n",sell[0],selr[0],jew,djew); 
	   if(skin_m[2]==0)
	   printf("│       %c C : 동전 20 %c       │ \n",sell[1],selr[1]); 
	   if(skin_m[2]==1)
	   printf("│       %c C : 구매완료 %c      │ \n",sell[1],selr[1]);
	   if(skin_m[3]==0) 
	   printf("│       %c D : 동전 20 %c       │   열쇠¶ : %d(%d)                        \n",sell[2],selr[2],key,dkey);
	   if(skin_m[3]==1)
	   printf("│       %c D : 구매완료 %c      │   열쇠¶ : %d(%d)                        \n",sell[2],selr[2],key,dkey);
	   if(skin_m[4]==0)
	   printf("│       %c E : 동전 20 %c       │ \n",sell[3],selr[3]);
	   if(skin_m[4]==1)
	   printf("│       %c E : 구매완료 %c      │ \n",sell[3],selr[3]);
	   if(skin_m[5]==0)
	   printf("│       %c F : 동전 20 %c       │   토큰◎ : %d(%d)                        \n",sell[4],selr[4],toc,dtoc);
	   if(skin_m[5]==1)
	   printf("│       %c F : 구매완료 %c      │   토큰◎ : %d(%d)                        \n",sell[4],selr[4],toc,dtoc);
	   if(skin_m[6]==0)
	   printf("│       %c @ : 보석 30 %c       │ \n",sell[5],selr[5]);
	   if(skin_m[6]==1)
	   printf("│       %c @ : 구매완료 %c      │ \n",sell[5],selr[5]);
	   if(skin_m[7]==0)
	   printf("│       %c # : 보석 40 %c       │ \n",sell[6],selr[6]);
	   if(skin_m[7]==1)
	   printf("│       %c # : 구매완료 %c      │ \n",sell[6],selr[6]);
	   if(skin_m[8]==0)
	   printf("│       %c * : 보석 70 %c       │ \n",sell[7],selr[7]); 
	   if(skin_m[8]==1)
	   printf("│       %c * : 구매완료 %c      │ \n",sell[7],selr[7]);
	   if(skin_m[9]==0)
	   printf("│       %c . : 보석 100 %c      │ \n",sell[8],selr[8]);
	   if(skin_m[9]==1)
	   printf("│       %c . : 구매완료 %c      │ \n",sell[8],selr[8]);
	   printf("│                             │ \n"); 
	    printf("│  위/아래 : w/s  선택 : e    │ \n│  나가기 : q                 │ \n");
	       
	

    	printf("└─────────────────────────────┘  └────────────────────────────────┘ \n ");
	while(True) { 
        mov_but=_getch();
        if(mov_but=='q'){
        	i=0;
        	while(i<=8){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=8){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==9){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto store;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=8;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto store;
		}
		if(mov_but=='e'){
		if(selplus==0){
			if(coin>=20){
				coin-=20;
				dcoin=-20;
				skin_m[1]=1;
			}
		}
	    else if(selplus==1){
			if(coin>=20){
				coin-=20;
				dcoin=-20;
				skin_m[2]=1;
			}
		}  
		else if(selplus==2){
			if(coin>=20){
				coin-=20;
				dcoin=-20;
				skin_m[3]=1;
			}
		}	
		else if(selplus==3){
			if(coin>=20){
				coin-=20;
				dcoin=-20;
				skin_m[4]=1;
			}
		}
		else if(selplus==4){
			if(coin>=20){
				coin-=20;
				dcoin=-20;
				skin_m[5]=1;
			}
		}
		else if(selplus==5){
			if(jew>=30){
				jew-=30;
				djew=-30;
				skin_m[6]=1;
			}
		}
		else if(selplus==6){
			if(jew>=40){
				jew-=40;
				djew=-40;
				skin_m[7]=1;
			}
		}
		else if(selplus==7){
			if(jew>=70){
				jew-=70;
				djew=-70;
				skin_m[8]=1;
			}
		}
		else if(selplus==8){
			if(jew>=100){
				jew-=100;
				djew=-100;
				skin_m[9]=1;
			}
		}
		goto store;
		}
		
    }
	
}

 int startprize=0;
int store(){                                                                            //게임 세팅 
 dis[18][51]='?';
      
	selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
	store :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ ");
	printf(" ┌────────────────────────────────┐ \n");
       printf("│           멥 설정           │ \n"); 
	   printf("│ ----------------------------│   동전⊙ : %d(%d)      \n",coin,dcoin); 
	   printf("│                             │ \n"); 
	   printf("│                             │   보석ⓞ : %d(%d)                        \n",jew,djew); 
	   printf("│   %c 상자 생성 : 토큰 5 %c    │ \n",sell[0],selr[0]);
	   printf("│                             │   열쇠¶ : %d(%d)                        \n",key,dkey); 
	   printf("│                             │ \n"); 
	   printf("│  %c 잠금(X) 생성 : 토큰 5 %c  │   토큰◎ : %d(%d)                        \n",sell[1],selr[1],toc,dtoc);
	   printf("│                             │ \n"); 
	   printf("│                             │ \n"); 
	   if(startprize==0) 
	   printf("│  %c ☆시작 보상 : 수령☆ %c   │ \n",sell[2],selr[2]);
	   else if(startprize==1) 
	   printf("│        %c 수령 완료 %c        │ \n",sell[2],selr[2]);
	   printf("│                             │ \n"); 
	   printf("│                             │ \n"); 

	    printf("│  위/아래 : w/s  선택 : e    │ \n│  나가기 : q                 │ \n");

    	printf("└─────────────────────────────┘  └────────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='q'){
        	i=0;
        	while(i<=8){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=2){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==3){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto store;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=2;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto store;
		}
		if(mov_but=='e'){
		}
	    if(selplus==0){
			if(toc>=5){
				toc-=5;
				dtoc=-5;
				chestset();
			}
		}  
		else if(selplus==1){
			if(toc>=5){
				toc-=5;
				dtoc=-5;
				buildset();
			}
		}  
		else if(selplus==2){
				jew+=5;
                coin+=10;
                key+=1;
				djew=5;
				dcoin=10;
				dkey=1;
				skin_s[10]=0;
                skin_m[10]=1;
				startprize=1; 
		}
			
		goto store;
		}
		
    }
	
int heal(){
	
	dis[25][21]='?';
	selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
	heal :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ ");
    printf(" ┌────────────────────────────────┐ \n");
       printf("│            치유사           │ \n"); 
	   printf("│ ----------------------------│   동전⊙ : %d(%d)      \n",coin,dcoin); 
	   printf("│                             │ \n"); 
	   printf("│    %c 회복하기 : 동전 8 %c    │   보석ⓞ : %d(%d)                        \n",sell[0],selr[0],jew,djew);
	   printf("│                             │ \n"); 
	   printf("│ ----------------------------│   열쇠¶ : %d(%d)                        \n",key,dkey); 
	   printf("│                             │ \n"); 
	   if(shield_m[0]==0)
	   printf("│   %c 일반갑옷 : 동전 25 %c    │   토큰◎ : %d(%d)                        \n",sell[1],selr[1],toc,dtoc); 
	   if(shield_m[0]==1)
	   printf("│   %c 일반갑옷 : 구매완료 %c   │   토큰◎ : %d(%d)                        \n",sell[1],selr[1],toc,dtoc);
	   if(shield_m[1]==0) 
	   printf("│   %c 특수갑옷 : 동전 45 %c    │ \n",sell[2],selr[2]);
	   if(shield_m[1]==1)
	   printf("│   %c 특수갑옷 : 구매완료 %c   │ \n",sell[2],selr[2]);
	   if(shield_m[2]==0)
	   printf("│   %c 마법갑옷 : 동전 70 %c    │ \n",sell[3],selr[3]);
	   if(shield_m[2]==1)
	   printf("│   %c 마법갑옷 : 구매완료 %c   │\n",sell[3],selr[3]);
	   if(shield_m[3]==0)
	   printf("│   %c 강철갑옷 : 보석 70 %c    │ \n",sell[4],selr[4]);
	   if(shield_m[3]==1)
	   printf("│   %c 강철갑옷 : 구매완료 %c   │\n",sell[4],selr[4]);
	   if(shield_m[4]==0)
	   printf("│   %c 황금갑옷 : 보석 150 %c   │ \n",sell[5],selr[5]);
	   if(shield_m[4]==1)
	   printf("│   %c 황금갑옷 : 구매완료 %c   │ \n",sell[5],selr[5]);
	   printf("│                             │ \n"); 
	    printf("│  위/아래 : w/s  선택 : e    │ \n│  나가기 : q                 │ \n");
	       
	

    	printf("└─────────────────────────────┘  └────────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='q'){
        	i=0;
        	while(i<=8){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=5){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==6){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto heal;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=5;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto heal;
		}
		if(mov_but=='e'){
		if(selplus==0){
			if(coin>=8){
				coin-=8;
				dcoin=-8;
				health=m_health;    //회복하기 
			}
		}
	    else if(selplus==1){
			if(coin>=25){
				coin-=25;
				dcoin=-25;
				shield_m[0]=1;
			}
		}  
		else if(selplus==2){
			if(coin>=45){
				coin-=45;
				dcoin=-45;
				shield_m[1]=1;
			}
		}	
		else if(selplus==3){
			if(coin>=70){
				coin-=70;
				dcoin=-70;
				shield_m[2]=1;
			}
		}
		else if(selplus==4){
			if(jew>=70){
				jew-=70;
				djew=-70;
				shield_m[3]=1;
			}
		}
		else if(selplus==5){
			if(jew>=150){
				jew-=150;
				djew=-150;
				shield_m[4]=1;
			}
		}
		goto heal;
		}
		
    }
	
	
}



int s_selected=9;
int sel_heal(){                                                                                           //갑옷  선택 
	
	selplus=s_selected;
	selr[s_selected]=']';
    sell[s_selected]='[';
	sel_point :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ \n");
       printf("│          갑옷 장착          │ \n"); 
	   printf("│ ----------------------------│ \n"); 
	   printf("│                             │ \n"); 
	    if(shield_m[0]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[0],selr[0]);
	   else if(shield_m[0]==1&&shield_s[0]==0)
	   printf("│   %c 일반갑옷 : 장착하기 %c   │ \n",sell[0],selr[0]);
	   else if(shield_m[0]==1&&shield_s[0]==1)
	   printf("│   %c 일반갑옷 : 장착 중 %c    │ \n",sell[0],selr[0]);  
	   if(shield_m[1]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[1],selr[1]);
	   else if(shield_m[1]==1&&shield_s[1]==0)
	   printf("│   %c 특수갑옷 : 장착하기 %c   │ \n",sell[1],selr[1]);
	   else if(shield_m[1]==1&&shield_s[1]==1)
	   printf("│   %c 특수갑옷 : 장착 중 %c    │ \n",sell[1],selr[1]); 
	   if(shield_m[2]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[2],selr[2]);
	   else if(shield_m[2]==1&&shield_s[2]==0)
	   printf("│   %c 마법갑옷 : 장착하기 %c   │ \n",sell[2],selr[2]);
	   else if(shield_m[2]==1&&shield_s[2]==1)
	   printf("│   %c 마법갑옷 : 장착 중 %c    │ \n",sell[2],selr[2]);
	   if(shield_m[3]==0) 
	   printf("│          %c 미발견 %c         │ \n",sell[3],selr[3]);
	   else if(shield_m[3]==1&&shield_s[3]==0)
	   printf("│   %c 강철갑옷 : 장착하기 %c   │ \n",sell[3],selr[3]);
	   else if(shield_m[3]==1&&shield_s[3]==1)
	   printf("│   %c 강철갑옷 : 장착 중 %c    │ \n",sell[3],selr[3]); 
	   if(shield_m[4]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[4],selr[4]);
	   else if(shield_m[4]==1&&shield_s[4]==0)
	   printf("│   %c 황금갑옷 : 장착하기 %c   │ \n",sell[4],selr[4]);
	   else if(shield_m[4]==1&&shield_s[4]==1)
	   printf("│   %c 황금갑옷 : 장착 중 %c    │ \n",sell[4],selr[4]);
	   if(shield_m[5]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[5],selr[5]);
	   else if(shield_m[5]==1&&shield_s[5]==0)
	   printf("│   %c 샌드위치 : 장착하기 %c   │ \n",sell[5],selr[5]);
	   else if(shield_m[5]==1&&shield_s[5]==1)
	   printf("│   %c 샌드위치 : 장착 중 %c    │ \n",sell[5],selr[5]);
	   if(shield_m[6]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[6],selr[6]);
	   else if(shield_m[6]==1&&shield_s[6]==0)
	   printf("│   %c 투명망토 : 장착하기 %c   │ \n",sell[6],selr[6]);
	   else if(shield_m[6]==1&&shield_s[6]==1)
	   printf("│   %c 투명망토 : 장착 중 %c    │ \n",sell[6],selr[6]);
	   if(shield_m[7]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[7],selr[7]);
	   else if(shield_m[7]==1&&shield_s[7]==0)
	   printf("│    %c 티셔츠 : 장착하기 %c    │ \n",sell[7],selr[7]);
	   else if(shield_m[7]==1&&shield_s[7]==1)
	   printf("│    %c 티셔츠 : 장착 중 %c     │ \n",sell[7],selr[7]);
	   if(shield_m[8]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[8],selr[8]);
	   else if(shield_m[8]==1&&shield_s[8]==0)
	   printf("│    %c 방탄복 : 장착하기 %c    │ \n",sell[8],selr[8]);
	   else if(shield_m[8]==1&&shield_s[8]==1)
	   printf("│    %c 방탄복 : 장착 중 %c     │ \n",sell[8],selr[8]);
	   if(shield_m[9]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[9],selr[9]);
	   else if(shield_m[9]==1&&shield_s[9]==0)
	   printf("│     %c 헌옷 : 장착하기 %c     │ \n",sell[9],selr[9]);
	   else if(shield_m[9]==1&&shield_s[9]==1)
	   printf("│      %c 헌옷 : 장착 중 %c     │ \n",sell[9],selr[9]);
	   printf("│                             │ \n"); 
	   printf("│  위/아래 : w/s  선택 : e    │ \n│  나가기 : r                 │ \n");
	       
	

    	printf("└─────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='r'){
        	i=0;
        	while(i<=10){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=9){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==10){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto sel_point;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=9;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto sel_point;
		}
		if(mov_but=='e'){
		if(selplus==0){
			if(shield_m[0]==1){
			shield_z();
			shield_s[0]=1; 	
			shield=1.205;
			m_health=102;
			if(health>100)
			health=100;
			s_selected=0;
			}
		}
	    else if(selplus==1){
	    	if(shield_m[1]==1){
	    	shield_z();
			shield_s[1]=1;
			shield=1.514;
			m_health=102;
			if(health>100)
			health=100; 
			s_selected=1;	
	    	}
		}  
		else if(selplus==2){
			if(shield_m[2]==1){
	    	shield_z();
			shield_s[2]=1;
			shield=1.851;
			m_health=105;
			if(health>100)
			health=100;
			s_selected=2; 	
	    	}
		}	
		else if(selplus==3){
			if(shield_m[3]==1){
	    		
	    	}
			shield_z();
			shield_s[3]=1;
			shield=2.215;
			m_health=115; 
			s_selected=3;
			
		}
		else if(selplus==4){
			if(shield_m[4]==1){
	    	shield_z();
			shield_s[4]=1;
			shield=3.05;
			m_health=125;
			s_selected=4;	
	    	}
		}
		else if(selplus==5){
			if(shield_m[5]==1){
	    	shield_z();
			shield_s[5]=1;
			shield=1;
			m_health=150;
			s_selected=5;	
	    	}
		}
		else if(selplus==6){
			if(shield_m[6]==1){
	    	shield_z();
			shield_s[6]=1;
			m_health=10;
			shield=1;
			if(health>10)
			health=10;
			s_selected=6;	
	    	}
		}
		else if(selplus==7){
			if(shield_m[7]==1){
	    	shield_z();
			shield_s[7]=1;
			shield=1.225;
			m_health=101;
			if(health>101)
			health=101;
			s_selected=7;	
	    	}
		}
		else if(selplus==8){
			if(shield_m[8]==1){
	    	shield_z();
			shield_s[8]=1;
			shield=1.545 ;
			m_health=105;
			if(health>105)
			health=105;	
			s_selected=8;
	    	}
		}
		else if(selplus==9){
			if(shield_m[9]==1){
	    	shield_z();
			shield_s[9]=1;
			shield=1 ;
			m_health=100;
			s_selected=9;
		}
	}
}

		goto sel_point;
		}
		
    }
    
int shield_z(void){                                                                             //스킨 선택  등 초기화 
	i=0;
	while(i<=9){
		shield_s[i]=0;
		i+=1;
	}
	i=0;
}
	
int sword(){
	
	dis[27][70]='?';
	selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
	sword :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ ");
    printf(" ┌────────────────────────────────┐ \n");
       printf("│           대장장이          │ \n"); 
	   printf("│ ----------------------------│   동전⊙ : %d(%d)      \n",coin,dcoin); 
	   printf("│                             │ \n");
	   if(weapon_m[0]==0)
	   printf("│     %c 도검 : 동전 20 %c      │   보석ⓞ : %d(%d)                        \n",sell[0],selr[0],jew,djew); 
	   if(weapon_m[0]==1)
	   printf("│     %c 도검 : 구매완료 %c     │   보석ⓞ : %d(%d)                        \n",sell[0],selr[0],jew,djew); 
	   printf("│                             │ \n"); 	   
	   if(weapon_m[1]==0) 
	   printf("│    %c 방망이 : 동전 40 %c     │   토큰◎ : %d(%d)                        \n",sell[1],selr[1],toc,dtoc);
	   if(weapon_m[1]==1)
	   printf("│    %c 방망이 : 구매완료 %c    │   토큰◎ : %d(%d)                        \n",sell[1],selr[1],toc,dtoc);
	   printf("│                             │ \n"); 
	   if(weapon_m[2]==0)
	   printf("│    %c 황금검 : 보석 70 %c     │   열쇠¶ : %d(%d)                        \n",sell[2],selr[2],key,dkey);
	   if(weapon_m[2]==1)
	   printf("│    %c 황금검 : 구매완료 %c    │   열쇠¶ : %d(%d)                        \n",sell[2],selr[2],key,dkey);
	   printf("│                             │ \n"); 
	   if(weapon_m[3]==0)
	   printf("│      %c 창 : 보석 100 %c      │ \n",sell[3],selr[3]);
	   if(weapon_m[3]==1)
	   printf("│      %c 창 : 구매완료 %c      │ \n",sell[3],selr[3]);
	   printf("│                             │ \n"); 
	    printf("│  위/아래 : w/s  선택 : e    │ \n│  나가기 : q                 │ \n");
	       
	

    	printf("└─────────────────────────────┘  └────────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='q'){
        	i=0;
        	while(i<=8){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=3){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==4){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto sword;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=3;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto sword;
		}
		if(mov_but=='e'){
		if(selplus==0){
			if(coin>=20){
				coin-=20;
				dcoin=-20;
				weapon_m[0]=1; 
			}
		}
	    else if(selplus==1){
			if(coin>=40){
				coin-=40;
				dcoin=-40;
				weapon_m[1]=1; 
			}
		}  
		else if(selplus==2){
			if(jew>=70){
				jew-=70;
				djew=-70;
				weapon_m[2]=1; 
			}
		}	
		else if(selplus==3){
			if(jew>=100){
				jew-=100;
				djew=-100;
				weapon_m[3]=1; 
			}
		}
		goto sword;
		}
		
    }
	
	
}



int w_selected=8; 
int sel_weapon(){                                                                                       //갑옷  선택 
	selplus=w_selected;
	selr[w_selected]=']';
    sell[w_selected]='[';
	sel_point :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ \n");
       printf("│          무기 장착          │ \n"); 
	   printf("│ ----------------------------│ \n"); 
	   printf("│                             │ \n"); 
	    if(weapon_m[0]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[0],selr[0]);
	   else if(weapon_m[0]==1&&weapon_s[0]==0)
	   printf("│     %c 도검 : 장착하기 %c     │ \n",sell[0],selr[0]);
	   else if(weapon_m[0]==1&&weapon_s[0]==1)
	   printf("│     %c 도검 : 장착 중 %c      │ \n",sell[0],selr[0]);  
	   if(weapon_m[1]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[1],selr[1]);
	   else if(weapon_m[1]==1&&weapon_s[1]==0)
	   printf("│    %c 방망이 : 장착하기 %c    │ \n",sell[1],selr[1]);
	   else if(weapon_m[1]==1&&weapon_s[1]==1)
	   printf("│    %c 방망이 : 장착 중 %c     │ \n",sell[1],selr[1]); 
	   if(weapon_m[2]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[2],selr[2]);
	   else if(weapon_m[2]==1&&weapon_s[2]==0)
	   printf("│    %c 황금검 : 장착하기 %c    │ \n",sell[2],selr[2]);
	   else if(weapon_m[2]==1&&weapon_s[2]==1)
	   printf("│    %c 황금검 : 장착 중 %c     │ \n",sell[2],selr[2]);
	   if(weapon_m[3]==0) 
	   printf("│          %c 미발견 %c         │ \n",sell[3],selr[3]);
	   else if(weapon_m[3]==1&&weapon_s[3]==0)
	   printf("│      %c 창 : 장착하기 %c      │ \n",sell[3],selr[3]);
	   else if(weapon_m[3]==1&&weapon_s[3]==1)
	   printf("│      %c 창 : 장착 중 %c       │ \n",sell[3],selr[3]); 
	   if(weapon_m[4]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[4],selr[4]);
	   else if(weapon_m[4]==1&&weapon_s[4]==0)
	   printf("│     %c 풍선 : 장착하기 %c     │ \n",sell[4],selr[4]);
	   else if(weapon_m[4]==1&&weapon_s[4]==1)
	   printf("│     %c 풍선 : 장착 중 %c      │ \n",sell[4],selr[4]);
	   if(weapon_m[5]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[5],selr[5]);
	   else if(weapon_m[5]==1&&weapon_s[5]==0)
	   printf("│     %c 방페 : 장착하기 %c     │ \n",sell[5],selr[5]);
	   else if(weapon_m[5]==1&&weapon_s[5]==1)
	   printf("│     %c 방페 : 장착 중 %c      │ \n",sell[5],selr[5]);
	   if(weapon_m[6]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[6],selr[6]);
	   else if(weapon_m[6]==1&&weapon_s[6]==0)
	   printf("│  %c 클레이모어 : 장착하기 %c  │ \n",sell[6],selr[6]);
	   else if(weapon_m[6]==1&&weapon_s[6]==1)
	   printf("│  %c 클레이모어 : 장착 중 %c   │ \n",sell[6],selr[6]);
	   if(weapon_m[7]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[7],selr[7]);
	   else if(weapon_m[7]==1&&weapon_s[7]==0)
	   printf("│     %c 막대기 : 장착하기 %c   │ \n",sell[7],selr[7]);
	   else if(weapon_m[7]==1&&weapon_s[7]==1)
	   printf("│     %c 막대기 : 장착 중 %c    │ \n",sell[7],selr[7]);
	   if(weapon_m[8]==0)
	   printf("│          %c 미발견 %c         │ \n",sell[8],selr[8]);
	   else if(weapon_m[8]==1&&weapon_s[8]==0)
	   printf("│      %c 장갑 : 장착하기 %c    │ \n",sell[8],selr[8]);
	   else if(weapon_m[8]==1&&weapon_s[8]==1)
	   printf("│      %c 장갑 : 장착 중 %c     │ \n",sell[8],selr[8]);
	   
	   printf("│                             │ \n"); 
	   printf("│  위/아래 : w/s  선택 : e    │ \n│  나가기 : R                 │ \n");
	       
	

    	printf("└─────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='R'){
        	i=0;
        	while(i<=10){
        	sell[i]=' ';
			selr[i]=' ';
			i+=1;
		}
		return 0;
		}
		else if(mov_but=='s'){
			if(selplus<=8){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus+=1;
        	if(selplus==9){
        		selplus=0;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
			selr[selplus]=']';
        	sell[selplus]='[';	
			}	
			}
        	
			goto sel_point;
		}
		else if(mov_but=='w'){
			if(selplus>=0){
			sell[selplus]=' ';
			selr[selplus]=' ';
        	selplus-=1;
        	if(selplus==-1){
        		selplus=8;
	selr[selplus]=']';
    sell[selplus]='[';
        		
			}
			else{
				selr[selplus]=']';
        	sell[selplus]='[';
			}	
			}
        	
			goto sel_point;
		}
		if(mov_but=='e'){
		if(selplus==0){
			if(weapon_m[0]==1){
			weapon_z();
			weapon_s[0]=1; 	
			weapon=1.255;
			distance=1;
			w_selected=0;
			}
		}
	    else if(selplus==1){
	    	if(weapon_m[1]==1){
	    	weapon_z();
			weapon_s[1]=1;
			weapon=1.336;
			distance=1;
			w_selected=1;	
	    	}
		}  
		else if(selplus==2){
			if(weapon_m[2]==1){
	    	weapon_z();
			weapon_s[2]=1;
			weapon=1.511;
			distance=1;	
			w_selected=2;
	    	}
		}	
		else if(selplus==3){
			if(weapon_m[3]==1){
	    		
	    	}
			weapon_z();
			weapon_s[3]=1;
			weapon=1.301; 
			distance=3;
			w_selected=3;
			
		}
		else if(selplus==4){
			if(weapon_m[4]==1){
	    	weapon_z();
			weapon_s[4]=1;
			weapon=0.06;
			distance=10;
			w_selected=4;	
	    	}
		}
		else if(selplus==5){
			if(weapon_m[5]==1){
	    	weapon_z();
			weapon_s[5]=1;
			weapon=1.425;
			w_shield=0.664;
			distance=1;
			w_selected=5;	
	    	}
		}
		else if(selplus==6){
			if(weapon_m[6]==1){
	    	weapon_z();
			weapon_s[6]=1;
			weapon=2;
			distance=2;	
			w_selected=6;
	    	}
		}
		else if(selplus==7){
			if(weapon_m[7]==1){
	    	weapon_z();
			weapon_s[7]=1;
			weapon=1.175;
			distance=1;
			w_selected=7;
	    	}
		}
		else if(selplus==8){
			if(weapon_m[8]==1){
	    	weapon_z();
			weapon_s[8]=1;
			weapon=1;
			distance=1;
			w_selected=8;
	    	}
		}
}

		goto sel_point;
		}
		
    }
    
int weapon_z(void){                                                                             //스킨 선택  등 초기화 
	i=0;
	while(i<=8){
		weapon_s[i]=0;		
		w_shield=0;
		distance=1;
		i+=1;
	}
	i=0;
}

int mon_kill(void){
	srand((unsigned int)time(NULL));
	toc+=1;
		dtoc=1;
		xp+=6;
		if(shield_s[4]==1){
		coin+=2;
		dcoin=2; 	
		}
		if(weapon_s[2]==0){
			coin+=2;
		dcoin=2; 	
		}
		if(rand()%100<=1){
			shield_m[5]=1;
		}
		else if(rand()%100==99){
			shield_m[6]=1;
		}
		else if(rand()%100<=15){
			shield_m[7]=1;
		}
		else if(rand()%100>=96){
			shield_m[8]=1;
		}
		else if(rand()%98==20){
			weapon_m[4]=1;
		}
		else if(rand()%95==51){
			weapon_m[5]=1;
		}
		else if(rand()%120==50){
			weapon_m[6]=1;
		}
}

int tu_sel(){
  tu_dis[9][25]='?';
	tut :
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n┌─────────────────────────────┐ \n");
	if(lang==KOR)
       printf("│         튜토리얼 종료       │ \n");
    if(lang==ENG) 
       printf("│         End Tutorial        │ \n");
	   printf("│ ----------------------------│ \n"); 
	   printf("│                             │ \n"); 
	   printf("│                             │ \n");
	   printf("│                             │ \n");
	   printf("│                             │ \n");
	   printf("│                             │ \n");
	   if(lang==KOR) 
	   printf("│       [ 새개임 실행 ]       │ \n");
	   if(lang==ENG)
	   printf("│      [ New Game Start ]     │ \n");   
	   printf("│                             │ \n"); 
	   printf("│                             │ \n");
	   printf("│                             │ \n");
	   printf("│                             │ \n");
	   printf("│                             │ \n");
	   if(lang==KOR) 
	    printf("│  선택 : e                   │ \n│  나가기 : q                 │ \n");
       if(lang==ENG)
	   printf("│  Selct : e                  │ \n│  Out : q                    │ \n");    

    	printf("└─────────────────────────────┘ \n ");
	while(True) {
        mov_but=_getch();
        if(mov_but=='q'){
		return 0;
		}
		if(mov_but=='e'){
		  tuto=0;
		  health=100;
		  xp+=10;
		  return 0; 
		}	
		goto tut;
		}	
	
	
}



void textcolor(int foreground, int background) //글자색 
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
