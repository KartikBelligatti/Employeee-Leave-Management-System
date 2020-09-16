#include <stdio.h>
#include<stdlib.h> 
#include<string.h>
struct employee
{
char   name1[30],name2[30],dept[100],desg[100],empId[100];
 int lev;
};
 struct emp
{
  char nam1[30],nam2[30],dep[100],des[100],empI[100];
    int le;
};
 struct emp e[100];
struct employee emp[100];
int n,count=0,i=0,num,y,x=15;
int o=0;
 void applyleave();
void display();
void update();
void delete();
void search();
void red()
{
  printf("\033[0;31m");
}
void boldred()
{
  printf("\033[1;31m");
}
void green()
{
  printf("\033[0;32m");
}
void boldgreen()
{
  printf("\033[1;32m");
}
void yellow()
{
  printf("\033[0;33m");
}
void boldyellow()
{
  printf("\033[01;33m");
}
void blue()
{
  printf("\033[0;34m");
}
void boldblue()
{
  printf("\033[1;34m");
}
void magneta()
{
  printf("\033[0;35m");
}
void boldmagneta()
{
  printf("\033[1;35m");
}
void cyan()
{
  printf("\033[0;36m");
}
void boldcyan()
{
  printf("\033[1;36m");
}
void reset()
{
 printf("\033[0m");
}
void c()
{
int r=count;
printf(" %d\n",r);
}
 void main()
{

 system("color 2e");
boldgreen();
 printf("*****************************************************************************************\n");
 printf("*                                                                                       *\n");
 printf("*         >>>>>>>>        EMPLOYEE  LEAVE  MANGEMENT  SYSTEM        <<<<<<<<            *\n");
 printf("*                                                                                       *\n");
 printf("*****************************************************************************************\n");
reset();

while(1)
{
boldyellow();
 printf("_______________________________\n\n");
 printf("|  ENTER YOUR CHOICE          |\n");
 printf("_______________________________\n\n");
 printf("|  1.APPLY FOR LEAVE          |\n");
 printf("|  2.DISPLAY STATUS           |\n"); 
 printf("|  3.UPDATE YOUR STATUS       |\n");
 printf("|  4.DELETE YOUR APPLICATION  |\n"); 
 printf("|  5.SEARCH EMPLOYEE          |\n");
 printf("|  6.EXIT                     |\n");
 printf("|_______________________________\n");

  scanf("%d",&n);
 c();
switch(n)
{
case 1:applyleave();break;
case 2:display();break;
case 3:update();break;
case 4:delete();break;
case 5:search();break;
case 6:exit(0);break;
boldred();
default:printf("INVALID CHOICE\n");
reset();
}
}
 }      
void applyleave()
{
FILE *gt;
gt=fopen("l.d","a");
    boldcyan();   
    printf(" ___________________________________________________________________\n\n");
    printf("|                     ENTER YOUR LEAVE DETAILS                      |\n");
    printf(" ___________________________________________________________________\n");
    reset();
    magneta();
    printf("| SSN         :");         scanf("%s",emp[i].empId);
    printf("|\n");  
    int j;
  for(j=1;j<=i;j++)
{
   if(strcmp(emp[j-1].empId,emp[i].empId)==0)
    {  
    boldred(); 
    printf("|-->  ENTER THE VALID SSN  <--");      scanf("%s",emp[i].empId);  
    printf("|\n");
  j=0;
}  
   }
  magneta();
    printf("| FIRST NAME  :");       scanf("%s",emp[i].name1);   
    printf("|\n");                                                             
    printf("| LAST NAME   :");        scanf("%s",emp[i].name2);   
    printf("|\n");                                                             
    printf("| DEPARTMENT  :");        scanf("%s",emp[i].dept);      
    printf("|\n");                                                             
    printf("| DESIGNATION :");        scanf("%s",emp[i].desg);      
    printf("|\n");                                                             
    printf("| LEAVES      :");        scanf("%d",&emp[i].lev); 
    int k=1,l=15,r=0;
  for(k=1;k<=l;k++)
{
     if(emp[i].lev>l ||emp[i].lev<0)
    {  
   boldred();
    printf("|-->  ENTER THE ALLOWED LEAVES <--");       scanf("%d",&emp[i].lev);  
    printf("|\n");
 k=0;
}
 reset();
}   
fprintf(gt,"%s %s %s %s %s %d\n",emp[i].empId,emp[i].name1,emp[i].name2,emp[i].dept,emp[i].desg,emp[i].lev);
 magneta();
    printf("_____________________________________________________________________\n");
    count++;
    i++;

 fclose(gt);
}
void display()
 {
 FILE *gt;
gt=fopen("l.d","a+");
int s,l=15;
boldgreen();
     printf(" ________________________________________________________________________________________________________________\n\n");
     printf("|                           -------->>            EMPLOYEE DETAILS            <<----------                     |\n");
     printf(" ________________________________________________________________________________________________________________\n");
 reset();
 boldblue();
  printf("________________________________________________________________________________________________\n");
  printf("------------------------------------------------------------------------------------------------\n");
  printf("S.NO\tID\tFIRST NAME\tLAST NAME\tDEPARTMENT\tDESIGNATION\tLEAVES\tLEFT LEAVES\n");
  printf("_________________________________________________________________________________________________\n");
  printf("------------------------------------------------------------------------------------------------\n");



   while(fscanf(gt,"%s %s %s %s %s %d\n",emp[i].empId,emp[i].name1,emp[i].name2,emp[i].dept,emp[i].desg,&emp[i].lev)!=EOF)
{
  printf("%d\t%s\t%s\t\t%s\t\t%s\t\t%s\t\t%d\t%d\n",i+1,emp[i].empId,emp[i].name1,emp[i].name2,emp[i].dept,emp[i].desg,emp[i].lev,x-emp[i].lev);
  }
  fclose(gt);
 }
void delete()
{

int n;
char j[100],k[100];
boldmagneta();
printf("_____________________________________________\n\n");
printf("        -------->>   DELETE    <<---------      \n");
printf("_____________________________________________\n");

boldyellow();
printf("             ENTER YOUR ID TO DELETE          \n");
printf("---------------------------------------------\n");

scanf("%s",k);
int i=0,j1=0;
for(i=0;i<count;i++)
{
 if(strcmp(k,emp[i].empId)==0)
 { 
 j1=1;
    boldblue();
               printf("-->> DELETED EMPLOYEE DETAILS ARE <<--\n");
   
               red();
             
               printf("------------------------------------\n");
               printf("| EMPLOYEE ID   :%s \n",emp[i].empId);
               printf("| FIRST NAME    :%s \n",emp[i].name1);
               printf("| SECOND NAME   :%s \n",emp[i].name2);
               printf("| DEPARTMENT    :%s \n",emp[i].dept);
               printf("| DESIGNATION   :%s \n",emp[i].desg);
               printf("| LEAVES        :%d \n",emp[i].lev);
               printf("-------------------------------------\n");
   emp[i]=emp[i+1];              
count--;

}
}
if(j1==0)
{
boldred();
               printf("-----------------------------------\n");
               printf("| !!!!!! --->   INVALID ID NUMBER |\n");
               printf("-----------------------------------\n");
}
}





void update()
{
 int j,c;
char l[100];
boldcyan();
 printf("_________________________________________\n\n");
 printf("       >>>>>      UPDATE     <<<<<<       \n");
 printf("_________________________________________\n");

yellow();
 printf("-----------------------------------------\n\n");
 printf("           ENTER YOUR ID NUMBER          \n");
 printf("-----------------------------------------\n");

 scanf("%s",l);
int n=0;
for(i=0;i<count;i++)
{
 if(strcmp(l,emp[i].empId)==0)
 {
   n=1;
for(i=i;i<count;i++)
{
boldblue();
 printf("___________________________________________\n\n");
 printf("       -------->>    EDIT    <<---------    \n");
 printf("___________________________________________\n");

boldyellow();
 printf("-------------------------------------------\n");
 printf("      <<<TO EDIT YOUR DETAILS PRESS >>>    \n");
 printf("-------------------------------------------\n");

 while(1)
{
boldgreen();
 printf("---------------------\n");
 printf("| 1-> FIRST NAME    |\n");
 printf("| 2-> LAST NAME     |\n");
 printf("| 3-> DEPARTMENT    |\n");
 printf("| 4-> DESIGNATION   |\n");
 printf("| 5-> LEAVES        |\n");
 printf("| 6-> SUBMIT        |\n");
 printf("---------------------\n");

 scanf("%d",&c);
 switch(c)
{
 
 
 magneta();
case 1:  printf("FIRST NAME  :\n");          scanf("%s",emp[i].name1);break;
case 2:  printf("SECOND NAME :\n");          scanf("%s",emp[i].name2);break;
case 3:  printf("DEPATMENT   :\n");          scanf("%s",emp[i].dept);break;
case 4:  printf("DESIGNATION :\n");          scanf("%s",emp[i].desg);break;
case 5:  printf("YOUR LEFT LEAVES ARE : %d\n",x-emp[i].lev);
         printf("LEAVES      :\n");          scanf("%d",&o);
     int k=1,l=15;
 
  while(o<0 || o>15-emp[i].lev)
{
         printf("|-->  ENTER THE ALLOWED LEAVES  <--");       scanf("%d",&o);
}
emp[i].lev=emp[i].lev+o;
break;
case 6:return;
}
}
}
}
}
if(n==0)
{
 boldred();
  printf("---------------------------------------------\n");
  printf("------>      ENTER THE VALID SSN      <-------\n");
  printf("----------------------------------------------\n");
}


}
void search()
{ 
 FILE *gt;
 gt=fopen("l.d","a+");
boldblue();
    int i=0,p;
    char z[10],id[100];
    cyan();
     printf("________________________________________\n\n");
     printf("     ------->>   SEARCH   <<--------      \n");
     printf("________________________________________\n");
    
boldmagneta();
     printf("----------------------------------------\n\n");
     printf("          ENTER YOUR ID TO SEARCH       \n");
     scanf("%s",id);
     printf("----------------------------------------\n");
   

while(fscanf(gt,"%s %s %s %s %s %d\n",emp[i].empId,emp[i].name1,emp[i].name2,emp[i].dept,emp[i].desg,&emp[i].lev)!=EOF)
{ 


 if(strcmp(id,emp[i].empId)==0)
{
 p=1;
cyan();


               printf("----------------------\n");
               printf("| EMPLOYEE ID   :%s \n",emp[i].empId);
               printf("| FIRST NAME    :%s \n",emp[i].name1);
               printf("| SECOND NAME   :%s \n",emp[i].name2);
               printf("| DEPARTMENT    :%s \n",emp[i].dept);
               printf("| DESIGNATION   :%s \n",emp[i].desg);
               printf("| LEAVES        :%d \n",emp[i].lev);
               printf("| LEFT LEAVES   :%d \n",15-emp[i].lev);
               printf("---------------------\n");
               return;
}
}

if(p==0)
{
boldred();
               printf("-----------------------------------\n");
               printf("| !!!!!! --->   INVALID ID NUMBER |\n");
               printf("-----------------------------------\n");
}
fclose(gt);
}

