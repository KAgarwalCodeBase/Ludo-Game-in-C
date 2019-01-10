#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
int moving(int *dice,int *xy,int *yy,void *white,void *black,void *black2,int *c,int *status);
void display(int *dice,int*xy,int*yy,void *store,int c,int *status,int *sttx,int *stty);
void vanish(int*dice,int*xy,int*yy,void*white,int c,int *status,int *sttx,int *stty);
void paste(void *hg,void *hb,void *hr,void *hy);
struct name
{char  nm[16];
};
int main()
{
char stringb[3];
struct name aaa[4];
int win=0;//for finding the winner
	   //starting area coordinates y /g /r/b order
int sttx[]={180,180,150,150,180,180,150,150,486,486,456,456,486,486,456,456};
int stty[]={320,290,290,320,95,65,65,95,95,65,65,95,320,290,290,320};
		 // coordinates for pieces after they reaching home vertical column beside game board
int hommyx[]={40,40,40,40,40,40,40,40,595,595,595,595,595,595,595,595};
int hommyy[]={265,290,315,340,30,55,80,105,30,55,80,105,265,290,315,340};
int gd=DETECT,gm,err,i,c=0,a,num=0;
int xy[]={284,284,284,284,284,250,216,182,148,114,80,80,80,114,148,182,216,250,284,284,284,284,284,284,318,352,352,352,352,352,352,386,420,454,488,522,556,556,556,522,488,454,420,386,352,352,352,352,352,352,318,318,318,318,318,318,318};
int yy[]={343,318,293,268,243,218,218,218,218,218,218,193,168,168,168,168,168,168,143,118,93,68,43,18,18,18,43,68,93,118,143,168,168,168,168,168,168,193,218,218,218,218,218,218,243,268,293,318,343,368,368,343,318,293,268,243,218};
int size,status[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int xg[]={114,148,182,216,250,284,284,284,284,284,284,318,352,352,352,352,352,352,386,420,454,488,522,556,556,556,522,488,454,420,386,352,352,352,352,352,352,318,284,284,284,284,284,284,250,216,182,148,114,80,80,114,148,182,216,250,284};
int yg[]={168,168,168,168,168,143,118,93,68,43,18,18,18,43,68,93,118,143,168,168,168,168,168,168,193,218,218,218,218,218,218,243,268,293,318,343,368,368,368,343,318,293,268,243,218,218,218,218,218,218,193,193,193,193,193,193,193};
int xr[]={352,352,352,352,352,386,420,454,488,522,556,556,556,522,488,454,420,386,352,352,352,352,352,352,318,284,284,284,284,284,284,250,216,182,148,114,80,80,80,114,148,182,216,250,284,284,284,284,284,284,318,318,318,318,318,318,318};
int yr[]={43,68,93,118,143,168,168,168,168,168,168,193,218,218,218,218,218,218,243,268,293,318,343,368,368,368,343,318,293,268,243,218,218,218,218,218,218,193,168,168,168,168,168,168,143,118,93,68,43,18,18,43,68,93,118,143,168};
int xb[]={522,488,454,420,386,352,352,352,352,352,352,318,284,284,284,284,284,284,250,216,182,148,114,80,80,80,114,148,182,216,250,284,284,284,284,284,284,318,352,352,352,352,352,352,386,420,454,488,522,556,556,522,488,454,420,386,352};
int yb[]={218,218,218,218,218,243,268,293,318,343,368,368,368,343,318,293,268,243,218,218,218,218,218,218,193,168,168,168,168,168,168,143,118,93,68,43,18,18,18,43,68,93,118,143,168,168,168,168,168,168,193,193,193,193,193,193,193};
void *store,*white,*black,*store1,*store2,*store3,*black2;//white for coloring the white on block after increasing the position
void *hy,*hg,*hr,*hb; //void pointer for copying the image of home path
char arr[10];
int dice[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char exitt='1';
int check=0;//for checking whether the pieces overlapped or not
clrscr();
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
err=graphresult();
if(err!=grOk)
{
printf("graphics error is: %s",grapherrormsg(err));
printf("enter for exit");
getch();
exit(1);

}
srand(time(0));
size=imagesize(0,0,220,15);
black2=malloc(size);
getimage(5,385,225,400,black2);
size=imagesize(0,0,20,15);
black=malloc(size);
getimage(145,385,165,400,black);
  setcolor(RED);
      settextstyle(5, HORIZ_DIR, 9);
      outtextxy(100,15, "WELCOME");
     setcolor(YELLOW);
      outtextxy(300,115, "IN");
   setcolor(GREEN);
      outtextxy(150,215, "LUDO");
   setcolor(BLUE);
      outtextxy(250,315, "GAME");
settextstyle(0, HORIZ_DIR, 0);
getch();
setfillstyle(0,0);
bar(0,0,636,476);
setcolor(YELLOW);
outtextxy(25,100,"YELLOW");
outtextxy(125,100,"Enter the player 1 name");
for(i=0;i<15;i++)
{aaa[0].nm[i]=getch();
aaa[0].nm[i]=toupper(aaa[0].nm[i]);
if(aaa[0].nm[i]<91&&aaa[0].nm[i]>64||aaa[0].nm[i]<58&&aaa[0].nm[i]>47)
{
sprintf(stringb,"%c",aaa[0].nm[i]);
outtextxy(400+i*9,100,stringb);
continue;
}
break;
}
aaa[0].nm[i]='\0';
setcolor(GREEN);
outtextxy(25,200,"GREEN");
outtextxy(125,200,"Enter the player 2 name");
for(i=0;i<15;i++)
{aaa[1].nm[i]=getch();
aaa[1].nm[i]=toupper(aaa[1].nm[i]);
if(aaa[1].nm[i]<91&&aaa[1].nm[i]>64||aaa[1].nm[i]<58&&aaa[1].nm[i]>47)
{
sprintf(stringb,"%c",aaa[1].nm[i]);
outtextxy(400+i*9,200,stringb);
continue;
}
break;
}
aaa[1].nm[i]='\0';
setcolor(RED);
outtextxy(25,300,"RED");
outtextxy(125,300,"Enter the player 3 name");
for(i=0;i<15;i++)
{aaa[2].nm[i]=getch();
aaa[2].nm[i]=toupper(aaa[2].nm[i]);
if(aaa[2].nm[i]<91&&aaa[2].nm[i]>64||aaa[2].nm[i]<58&&aaa[2].nm[i]>47)
{
sprintf(stringb,"%c",aaa[2].nm[i]);
outtextxy(400+i*9,300,stringb);
continue;
}
break;
}
aaa[2].nm[i]='\0';
setcolor(BLUE);
outtextxy(25,400,"BLUE");
outtextxy(125,400,"Enter the player 4 name");
for(i=0;i<15;i++)
{aaa[3].nm[i]=getch();
aaa[3].nm[i]=toupper(aaa[3].nm[i]);
if(aaa[3].nm[i]<91&&aaa[3].nm[i]>64||aaa[3].nm[i]<58&&aaa[3].nm[i]>47)
{
sprintf(stringb,"%c",aaa[3].nm[i]);
outtextxy(400+i*9,400,stringb);
continue;
}
break;
}
aaa[3].nm[i]='\0';
bar(0,0,636,476);
//getch();
setcolor(WHITE);
size=imagesize(0,0,170,25);
hg=malloc(size);
hb=malloc(size);
size=imagesize(0,0,34,125);
hy=malloc(size);
hr=malloc(size);
size=imagesize(0,0,11,11);
store=malloc(size);
store1=malloc(size);
store2=malloc(size);
store3=malloc(size);
white=malloc(size);
rectangle(1,1,638,478);   // biggest board
rectangle(3,3,636,382);   //upper half board
rectangle(3,384,636,476); //lower half board
setfillstyle(1,15);
bar(62,5,573,380);//game board
setcolor(WHITE);
outtextxy(15,15,"G");
outtextxy(15,40,"R");
outtextxy(15,65,"E");
outtextxy(15,90,"E");
outtextxy(15,115,"N");
outtextxy(15,255,"Y");
outtextxy(15,275,"E");
outtextxy(15,295,"L");
outtextxy(15,315,"L");
outtextxy(15,335,"O");
outtextxy(15,355,"W");
outtextxy(615,25,"R");
outtextxy(615,65,"E");
outtextxy(615,105,"D");
outtextxy(615,245,"B");
outtextxy(615,280,"L");
outtextxy(615,315,"U");
outtextxy(615,350,"E");
circle(40,30,5);
circle(40,55,5);
circle(40,80,5);
circle(40,105,5);
circle(40,265,5);
circle(40,290,5);
circle(40,315,5);
circle(40,340,5);
circle(595,30,5);
circle(595,55,5);
circle(595,80,5);
circle(595,105,5);
circle(595,265,5);
circle(595,290,5);
circle(595,315,5);
circle(595,340,5);
setcolor(8);
setfillstyle(1,2);  // GREEN HOME PATH
bar(97,180,267,205);
setfillstyle(1,1); //BLUE HOME PATH
bar(369,180,539,205);
setfillstyle(1,4); //RED HOME PATH
bar(301,30,335,155);
setfillstyle(1,14);//YELLOW HOME PATH
bar(301,230,335,355);
setfillstyle(1,2);  // GREEN single colour block
bar(97,155,131,180);
bar(267,55,301,80);
setfillstyle(1,1); //BLUE  single colour block
bar(538,230,504,205);
bar(369,330,335,305);
setfillstyle(1,4); //RED single colour block
bar(335,30,369,55);
bar(471,155,505,180);
setfillstyle(1,14);//YELLOW single colour block
bar(267,355,301,330);
bar(131,230,165,205);
setfillstyle(1,15);  // white  circle in green single colour block
fillellipse(97+17,155+13,10,10);
fillellipse(267+17,55+13,10,10);
 //white circle in blue  single colour block
fillellipse(538-17,230-12,10,10);
fillellipse(369-17,330-12,10,10);
//white circle in  red single colour block
fillellipse(335+17,30+13,10,10);
fillellipse(471+17,155+13,10,10);
//white circle in yellow single colour block
fillellipse(267+17,355-12,10,10);
fillellipse(131+17,230-12,10,10);
for(i=0;i<14;i++)
line(63,5+25*(i+1),572,5+25*(i+1));//rows on ludo board
for(i=0;i<14;i++)
line(63+34*(i+1),5,63+34*(i+1),380);
getimage(97,180,267,205,hg);// taking image of green  home path
getimage(369,180,539,205,hb);// taking image of blue  home path
getimage(301,30,335,155,hr); // taking image of red  home path
getimage(301,230,335,355,hy);// taking image of yellow  home path
setfillstyle(1,2);         //green color starting area
bar(63,5,267,155);
rectangle(63,5,267,155);
outtextxy(130,15,aaa[1].nm);
setfillstyle(1,14);                      //yellow colour starting area
bar(63,230,267,380);
rectangle(63,230,267,380);
outtextxy(130,365,aaa[0].nm);
setfillstyle(1,4);                //red color starting area
bar(369,5,572,155);
rectangle(369,5,572,155);
outtextxy(436,15,aaa[2].nm);
setfillstyle(1,1);                           //blue color  starting area
bar(369,230,572,380);
rectangle(369,230,572,380);
outtextxy(436,365,aaa[3].nm);
setfillstyle(1,WHITE);
fillellipse(165,80,50,50);//green  big circles
fillellipse(165,305,50,50); //yellow          bigcircles
fillellipse(471,80,50,50);          //red  bigcircles
fillellipse(471,305,50,50);              //blue bigcircles
//outline of small green circles
fillellipse(180,95,10,10);
fillellipse(180,65,10,10);
fillellipse(150,95,10,10);
fillellipse(150,65,10,10);
//outline of small yellow circles
fillellipse(180,320,10,10);
fillellipse(150,290,10,10);
fillellipse(180,290,10,10);
fillellipse(150,320,10,10);
//outline of small red circles
fillellipse(486,95,10,10);
fillellipse(456,65,10,10);
fillellipse(486,65,10,10);
fillellipse(456,95,10,10);
//outline of small blue circles
fillellipse(486,320,10,10);
fillellipse(456,290,10,10);
fillellipse(486,290,10,10);
fillellipse(456,320,10,10);
//this section for home
bar(267,155,369,230);//for whiting the inner layer of the home
line(267,155,369,230);  //two diagonal lines which divide the rectangle into four parts
line(267,230,369,155);
rectangle(267,155,369,230);// rectangle for making boundary for home
//coloring the home with different colors (i.e red  green  blue  yellow)
setfillstyle(1,1);
floodfill(328,193,8);
setfillstyle(1,14);
floodfill(318,200,8);
  setfillstyle(1,4);
floodfill(318,180,8);
setfillstyle(1,2);
floodfill(308,193,8);
// copying the white part of the board from yellow
getimage(175,315,185,325,white);
setfillstyle(1,2);
fillellipse(180,95,5,5);//green small circles  inside big circle
getimage(175,90,185,100,store1);
outtextxy(178,92,"1");
fillellipse(180,65,5,5);//green   having green colour
outtextxy(178,62,"2");
fillellipse(150,65,5,5);
outtextxy(148,62,"3");
fillellipse(150,95,5,5);//green
outtextxy(147,92,"4");
setfillstyle(1,14);
fillellipse(180,320,5,5); //yellow small circles  inside big circles
getimage(175,315,185,325,store);
outtextxy(178,317,"1");
fillellipse(180,290,5,5); //yellow
outtextxy(178,287,"2");
fillellipse(150,290,5,5); //yellow
outtextxy(148,287,"3");
fillellipse(150,320,5,5); //yellow
outtextxy(147,317,"4");
setfillstyle(1,4);
fillellipse(486,95,5,5);          //red small circles inside big circles
getimage(481,90,491,100,store2);
outtextxy(484,92,"1");
fillellipse(486,65,5,5);          //red
outtextxy(484,62,"2");
fillellipse(456,65,5,5);          //red
outtextxy(454,62,"3");
fillellipse(456,95,5,5);          //red
outtextxy(453,92,"4");
setfillstyle(1,1);
fillellipse(486,320,5,5);              //blue small circles inside big circles
getimage(481,315,491,325,store3);
outtextxy(484,317,"1");
fillellipse(486,290,5,5);              //blue
outtextxy(484,287,"2");
fillellipse(456,290,5,5);              //blue
outtextxy(454,287,"3");
fillellipse(456,320,5,5);              //blue
outtextxy(453,317,"4");
setcolor(15);
while(exitt!='0')
{
 getch();
 outtextxy(10,410,"if you want to exit enter 0");
 exitt=getch();
 if(exitt=='0')//for termination of program
 {setfillstyle(0,0);
 bar(0,0,638,478);
 exit(0);
 }
 putimage(10,410,black2,0);   //blacken the message
rechance1:if(status[0]!=3){
  do{ //loop for occurence of num six in dice.
   c=0;
   check=0;
   outtextxy(300,460,"Yellow player turn");
   num=moving(dice,xy,yy,white,black,black2,&c,status);  //yellow player turn
   vanish(dice,xy,yy,white,0,status,sttx,stty);    //callig of vanish function
   vanish(dice,xg,yg,white,4,status,sttx,stty);
   vanish(dice,xr,yr,white,8,status,sttx,stty);
   vanish(dice,xb,yb,white,12,status,sttx,stty);
   paste(hg,hb,hr,hy);
   //condition for checking whether position is on the stoppage or not
   if(dice[c]!=0&&dice[c]!=8&&dice[c]!=13&&dice[c]!=21&&dice[c]!=26&&dice[c]!=34&&dice[c]!=39&&dice[c]!=47)
   {
  //condition for beating the other pieces if numbers concides
     for(a=4;a<8;a++)
     {
	 if(xy[dice[c]]==xg[dice[a]]&&yy[dice[c]]==yg[dice[a]])
	  {
	  status[a]=0;
	  check=1;
	  }
     }
     for(a=8;a<12;a++)
     {
	 if(xy[dice[c]]==xr[dice[a]]&&yy[dice[c]]==yr[dice[a]])
	  {
	  status[a]=0;
	  check=1;
	  }
     }
     for(a=12;a<16;a++)
     {
	 if(xy[dice[c]]==xb[dice[a]]&&yy[dice[c]]==yb[dice[a]])
	 {
	 status[a]=0;
	 check=1;
	 }
     }
   }
   display(dice,xy,yy,store,0,status,sttx,stty);
   display(dice,xg,yg,store1,4,status,sttx,stty);
   display(dice,xr,yr,store2,8,status,sttx,stty);
   display(dice,xb,yb,store3,12,status,sttx,stty);
if(check==1)
goto rechance1;//getting rechance bz it bits another player pieces
if(status[c]==2&&dice[c]==56)
{ dice[c]=57;
 setfillstyle(1,YELLOW);
 floodfill(hommyx[c],hommyy[c],WHITE);
 //putimage(hommyx[c],hommyy[c],store,0);
 sprintf(arr,"%d",c+1);
 outtextxy(hommyx[c]-2,hommyy[c]-3,arr);
 //winner block
 if(status[0]==2&&status[1]==2&&status[2]==2&&status[3]==2)
 {
  if(win==0)
  {outtextxy(135,245,"WINNER");
  status[0]=3;
  getch();
  delay(500);
  win+=1;
  }
  else{  if(win==1)
	 {outtextxy(120,245,"FIRST RUNNER UP");
	  status[0]=3;
	  getch();
	  delay(500);
	  win+=1;
	 }
	 else{
	       outtextxy(110,245,"SECOND RUNNER UP");
	       delay(500);
	       setfillstyle(0,BLACK);
	       bar(0,0,636,476);
	       settextstyle(5,HORIZ_DIR,9);
	       outtextxy(50,100,"THANK YOU");
	       getch();
	       delay(500);
	       exit(0);
	     }
      }
 }
//end of winner block
 goto rechance1;
}
putimage(300,460,black2,0);
}while(num==6);
}
rechance2: if(status[4]!=3){
  do{
     outtextxy(300,460,"Green player turn");
  c=4;
  check=0;
  num=moving(dice,xg,yg,white,black,black2,&c,status);
  vanish(dice,xy,yy,white,0,status,sttx,stty);
  vanish(dice,xg,yg,white,4,status,sttx,stty);
  vanish(dice,xr,yr,white,8,status,sttx,stty);
  vanish(dice,xb,yb,white,12,status,sttx,stty);
   paste(hg,hb,hr,hy);
 if(dice[c]!=0&&dice[c]!=8&&dice[c]!=13&&dice[c]!=21&&dice[c]!=26&&dice[c]!=34&&dice[c]!=39&&dice[c]!=47)
  {
  for(a=0;a<4;a++)
   {     if(xg[dice[c]]==xy[dice[a]]&&yg[dice[c]]==yy[dice[a]])
       {
       status[a]=0;
       check=1;
       }
   }
   for(a=8;a<12;a++)
   {     if(xg[dice[c]]==xr[dice[a]]&&yg[dice[c]]==yr[dice[a]])
       {
       status[a]=0;
       check=1;
       }
   }
   for(a=12;a<16;a++)
    {     if(xg[dice[c]]==xb[dice[a]]&&yg[dice[c]]==yb[dice[a]])
       {
       status[a]=0;
       check=1;
       }
    }
 }
 display(dice,xy,yy,store,0,status,sttx,stty);
 display(dice,xg,yg,store1,4,status,sttx,stty);
 display(dice,xr,yr,store2,8,status,sttx,stty);
 display(dice,xb,yb,store3,12,status,sttx,stty);
if(status[c]==2&&dice[c]==56)
{    dice[c]=57;
setfillstyle(1,GREEN);
 floodfill(hommyx[c],hommyy[c],WHITE);
 sprintf(arr,"%d",c-3);
 outtextxy(hommyx[c]-2,hommyy[c]-3,arr);
  //winner block
 if(status[4]==2&&status[5]==2&&status[6]==2&&status[7]==2)
 {
  if(win==0)
  {outtextxy(135,140,"WINNER");
  status[4]=3;
  getch();
  delay(500);
  win+=1;
  }
  else{  if(win==1)
	 {outtextxy(120,140,"FIRST RUNNER UP");
	  status[4]=3;
	  getch();
	  delay(500);
	  win+=1;
	 }
	 else{
	       outtextxy(110,140,"SECOND RUNNER UP");
	       delay(500);
	       setfillstyle(0,BLACK);
	       bar(0,0,636,476);
	       settextstyle(5,HORIZ_DIR,9);
	       outtextxy(50,100,"THANK YOU");
	       getch();
	       delay(500);
	       exit(0);
	     }
      }
 }
//end of winner block
 goto rechance2;
}
if(check==1)
goto rechance2;
putimage(300,460,black2,0);
}while(num==6);
}
rechance3:if(status[8]!=3){
 do{
   outtextxy(300,460,"Red player turn");
   check=0;
   c=8;
  num=moving(dice,xr,yr,white,black,black2,&c,status);
   vanish(dice,xy,yy,white,0,status,sttx,stty);
   vanish(dice,xg,yg,white,4,status,sttx,stty);
   vanish(dice,xr,yr,white,8,status,sttx,stty);
   vanish(dice,xb,yb,white,12,status,sttx,stty);
    paste(hg,hb,hr,hy);
   if(dice[c]!=0&&dice[c]!=8&&dice[c]!=13&&dice[c]!=21&&dice[c]!=26&&dice[c]!=34&&dice[c]!=39&&dice[c]!=47)
   {
     for(a=0;a<4;a++)
     {
	  if(xr[dice[c]]==xy[dice[a]]&&yr[dice[c]]==yy[dice[a]])
	  {
	  status[a]=0;
	  check=1;
	  }
     }
     for(a=4;a<8;a++)
     {
	  if(xr[dice[c]]==xg[dice[a]]&&yr[dice[c]]==yg[dice[a]])
	  {
	  status[a]=0;
	  check=1;
	  }
     }
     for(a=12;a<16;a++)
     {
	  if(xr[dice[c]]==xb[dice[a]]&&yr[dice[c]]==yb[dice[a]])
	  {
	  status[a]=0;
	  check=1;
	  }
     }
   }
   display(dice,xy,yy,store,0,status,sttx,stty);
   display(dice,xg,yg,store1,4,status,sttx,stty);
   display(dice,xr,yr,store2,8,status,sttx,stty);
   display(dice,xb,yb,store3,12,status,sttx,stty);
if(status[c]==2&&dice[c]==56)
{   dice[c]=57;
setfillstyle(1,RED);
 floodfill(hommyx[c],hommyy[c],WHITE);
// putimage(hommyx[c],hommyy[c],store2,0);
 sprintf(arr,"%d",c-7);
 outtextxy(hommyx[c]-2,hommyy[c]-3,arr);
  //winner block
 if(status[8]==2&&status[9]==2&&status[10]==2&&status[11]==2)
 {
  if(win==0)
  {outtextxy(440,140,"WINNER");
  status[8]=3;
  getch();
  delay(500);
  win+=1;
  }
  else{  if(win==1)
	 {outtextxy(420,140,"FIRST RUNNER UP");
	  status[8]=3;
	  getch();
	  delay(500);
	  win+=1;
	 }
	 else{
	       outtextxy(410,140,"SECOND RUNNER UP");
	       delay(500);
	       setfillstyle(0,BLACK);
	       bar(0,0,636,476);
	       settextstyle(5,HORIZ_DIR,9);
	       outtextxy(50,100,"THANK YOU");
	       getch();
	       delay(500);
	       exit(0);
	     }
      }
 }
//end of winner block
 goto rechance3;
}
if(check==1)
goto rechance3;
putimage(300,460,black2,0);
}while(num==6);
}
rechance4: if(status[12]!=3){
 do{
    outtextxy(300,460,"Blue player turn");
 check=0;
 c=12;
 num=moving(dice,xb,yb,white,black,black2,&c,status);
  vanish(dice,xy,yy,white,0,status,sttx,stty);
  vanish(dice,xg,yg,white,4,status,sttx,stty);
  vanish(dice,xr,yr,white,8,status,sttx,stty);
  vanish(dice,xb,yb,white,12,status,sttx,stty);
    paste(hg,hb,hr,hy);
 if(dice[c]!=0&&dice[c]!=8&&dice[c]!=13&&dice[c]!=21&&dice[c]!=26&&dice[c]!=34&&dice[c]!=39&&dice[c]!=47)
  {
 for(a=0;a<4;a++)
 {    if(xb[dice[c]]==xy[dice[a]]&&yb[dice[c]]==yy[dice[a]])
      {
      status[a]=0;
      check=1;
      }
  }
  for(a=4;a<8;a++)
 {	if(xb[dice[c]]==xg[dice[a]]&&yb[dice[c]]==yg[dice[a]])
	{
	status[a]=0;
	check=1;
	}
  }
 for(a=8;a<12;a++)
 {	if(xb[dice[c]]==xr[dice[a]]&&yb[dice[c]]==yr[dice[a]])
	{
	status[a]=0;
	check=1;
	}
  }
}
 display(dice,xy,yy,store,0,status,sttx,stty);
 display(dice,xg,yg,store1,4,status,sttx,stty);
 display(dice,xr,yr,store2,8,status,sttx,stty);
 display(dice,xb,yb,store3,12,status,sttx,stty);
if(status[c]==2&&dice[c]==56)
{         dice[c]=57;
setfillstyle(1,BLUE);
 floodfill(hommyx[c],hommyy[c],WHITE);
 sprintf(arr,"%d",c-11);
 outtextxy(hommyx[c]-2,hommyy[c]-3,arr);
  //winner block
 if(status[12]==2&&status[13]==2&&status[14]==2&&status[15]==2)
 {
  if(win==0)
  {outtextxy(440,245,"WINNER");
  status[12]=3;
  getch();
  delay(500);
  win+=1;
  }
  else{  if(win==1)
	 {outtextxy(420,245,"FIRST RUNNER UP");
	  status[12]=3;
	  getch();
	  delay(500);
	  win+=1;
	 }
	 else{
	       outtextxy(410,245,"SECOND RUNNER UP");
	       delay(500);
	       setfillstyle(0,BLACK);
	       bar(0,0,636,476);
	       settextstyle(5,HORIZ_DIR,9);
	       outtextxy(50,100,"THANK YOU");
	       getch();
	       delay(500);
	       exit(0);
	     }
      }
 }
//end of winner block
 goto rechance4;
}
if(check==1)
goto rechance4;
putimage(300,460,black2,0);
}while(num==6);
}
}
getch();
closegraph();
return 0;
}

int moving(int *dice,int *xy,int *yy,void *white,void *black,void *black2,int *c,int *status)
{int num,sumx,sumy,con=0;
 char pp,arr[10],arr2[10],choice;
  pp='0';// reinitialization of choice for yes or no
putimage(145,385,black,0);
outtextxy(10,390,"Random number is ");
getch();
setfillstyle(1,0);
while(!kbhit())
  {
  setcolor(15);
  bar3d(525,420,550,445,14,2);
  setcolor(RED);
  outtextxy(537,432,"3");
  outtextxy(554,425,"4");
  outtextxy(542,412,"1");
  delay(500);
  setcolor(15);
  bar(515,400,565,450);
  bar3d(575,420,600,445,14,2);
  setcolor(RED);
  outtextxy(587,432,"5");
  outtextxy(604,425,"2");
  outtextxy(592,412,"6");
  delay(500);
  bar(575,400,625,450);
  }
setcolor(WHITE);
num=rand()%7;
while(num==0)
num=rand()%7;
sprintf(arr,"%d",num); //converting the number into string for printing thr input number
outtextxy(150,390,arr);//printing the input text from user
getch();
if(num==6&&(status[*c]==0||status[*c+1]==0||status[*c+2]==0||status[*c+3]==0))
{ if(status[*c]==0)
  goto firstopen;
  do
  {
  outtextxy(10,410,"you want to open the piece ");
  outtextxy(10,430,"y: yes");
  outtextxy(10,450,"n: no");
  pp=getch();
  sprintf(arr2,"%c",pp); //converting the number into string for printing thr input number
  outtextxy(150,430,arr2);//printing the input text from user
  delay(500);
  putimage(10,410,black2,0);   //    for black the six no. choice
  putimage(10,430,black2,0);     //       same
  putimage(10,450,black2,0);       //     same
  }while(pp!='y'&&pp!='Y'&&pp!='n'&&pp!='N');
}
 if(pp=='y'||pp=='Y')
 { if(status[*c]==0)
    {
   firstopen:   status[*c]=1;
		dice[*c]=0;
    }
    else
    {
       if(status[*c+1]==0)
	{
	status[*c+1]=1;
	dice[*c+1]=0;
	}
       else
       {
	   if(status[*c+2]==0)
	   {
	   status[*c+2]=1;
	   dice[*c+2]=0;
	   }
	   else
	   {
	   status[*c+3]=1;
	   dice[*c+3]=0;
	   }
	}
    }
 return(num);
 }
loop:if((status[*c]==1||status[*c+1]==1||status[*c+2]==1||status[*c+3]==1))
{
 do{
 outtextxy(10,400,"enterpiece no. ");
 choice=getch();
 con=choice-49;
 putimage(10,400,black2,0);   //blacken the message
}while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
//condition follows loop when any one of the piece have a opening status "1" if all of them have either zero or two status then it goes to next move
if(status[*c+con]==0||status[*c+con]==2)
goto loop;
con=choice-49;
 sumx=xy[dice[*c+con]]-5;
 sumy=yy[dice[*c+con]]-5;
 putimage(sumx,sumy,white,0);
 if(dice[*c+con]+num<=56)
 dice[*c+con]=dice[*c+con]+num;
// sumx=xy[dice[c+con]]-5;
// sumy=yy[dice[c+con]]-5;
 if( dice[*c+con]==56)
 {
 status[*c+con]=2;
 }
*c+=con;
}//if
 delay(1000);
return(num);
}
//function for printing everytime eachpiece which is part of game
void display(int *dice,int*xy,int*yy,void *store,int c,int *status,int *sttx,int *stty)
{int sumx,sumy;
setcolor(0);
if(status[c]==1)    //when status is "1" then pieces is open and present inside the moving area
{
sumx=xy[dice[c+0]]-5;
sumy=yy[dice[c+0]]-5;
putimage(sumx,sumy,store,0);
outtextxy(xy[dice[c+0]]-2,yy[dice[c+0]]-3,"1");
}
if(status[c]==0)               //when status is "0" it means piece is present in starting area where pieces could not move
{
sumx=sttx[c+0]-5;
sumy=stty[c+0]-5;
putimage(sumx,sumy,store,0);
outtextxy(sttx[c+0]-2,stty[c+0]-3,"1");
}
if(status[c+1]==1)
{
sumx=xy[dice[c+1]]-5;
sumy=yy[dice[c+1]]-5;
putimage(sumx,sumy,store,0);
outtextxy(xy[dice[c+1]]-2,yy[dice[c+1]]-3,"2");
}
if(status[c+1]==0)
{
sumx=sttx[c+1]-5;
sumy=stty[c+1]-5;
putimage(sumx,sumy,store,0);
outtextxy(sttx[c+1]-2,stty[c+1]-3,"2");
}
if(status[c+2]==1)
{
sumx=xy[dice[c+2]]-5;
sumy=yy[dice[c+2]]-5;
putimage(sumx,sumy,store,0);
outtextxy(xy[dice[c+2]]-2,yy[dice[c+2]]-3,"3");
}
if(status[c+2]==0)
{
sumx=sttx[c+2]-5;
sumy=stty[c+2]-5;
putimage(sumx,sumy,store,0);
outtextxy(sttx[c+2]-2,stty[c+2]-3,"3");
}
if(status[c+3]==1)
{
sumx=xy[dice[c+3]]-5;
sumy=yy[dice[c+3]]-5;
putimage(sumx,sumy,store,0);
outtextxy(xy[dice[c+3]]-3,yy[dice[c+3]]-3,"4");
}
if(status[c+3]==0)
{
sumx=sttx[c+3]-5;
sumy=stty[c+3]-5;
putimage(sumx,sumy,store,0);
outtextxy(sttx[c+3]-3,stty[c+3]-3,"4");
}
setcolor(WHITE);
}
//To convert color image into the white image
void vanish(int*dice,int*xy,int*yy,void*white,int c,int *status,int *sttx,int *stty)
{
  int sumx,sumy,i,ab;

 for(i=0;i<4;i++)
 { if(status[c+i]!=2)
   { ab=dice[c+i];
    sumx=xy[ab]-5;
    sumy=yy[ab]-5;
    putimage(sumx,sumy,white,0);
    }
 }
    // remove the piece from starting area after the occurence of 6
 for(i=0;i<4;i++)
 {
  if(status[c+i]==1)
  {
  sumx=sttx[c+i]-5;
  sumy=stty[c+i]-5;
  putimage(sumx,sumy,white,0);
  }
 }
}

void paste(void *hg,void *hb,void *hr,void *hy)
{
putimage(97,180,hg,0);// pasting image of green  home path
putimage(369,180,hb,0);// pasting image of blue  home path
putimage(301,30,hr,0); // pasting image of red  home path
putimage(301,230,hy,0);// pasting image of yellow  home path
}