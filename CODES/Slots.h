/*
initially player gets 200 coin
then the game asks the value he wants to play for(n)n = bet
if he get double winning=n+(n*0.2)*2
if he gets triple winning = n+n*0.5
if he gets quad winning=n+n*0.8
if he gets ace winning =n+n*2
if he gets jackpot winning =n*100

*/

/*
Colour codes:
RED:[0;31m
BOLD RED:[1;31m
BLUE:[0;34m
BOLD BLUE:[1;34m
GREEN:[0;32m
BOLD GREEN:[1;32m
YELLOW:[0;33m
BOLD YELLOW:[01;33m
MAGENTA:[0;35m
BOLD MAGENTA:[1;35m
CYAN:[0;36m
BOLD CYAN:[1;36m
*/

#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int chips;
int slots_fn();
void chip_calc(int bet, int cd,int ct,int cq,int cp,int cj);
void disp();
int slots_main()
{
  
  printf("\033[1;34m");

	printf("\n\n\t##########################################################\n");
  
	printf("\t#                                                        #\n");
  printf("\033[0;31m");
  printf("\t\033[1;34m#\033[0;31m    *******  *        ********  *********  ********     \033[1;34m#\n");
  printf("\t\033[1;34m#\033[0;31m    *        *        *      *      *      *            \033[1;34m#\n" );
  printf("\t\033[1;34m#\033[0;31m    *        *        *      *      *      *            \033[1;34m#\n" );
  printf("\t\033[1;34m#\033[0;31m    *******  *        *      *      *      ********     \033[1;34m#\n");
  printf("\t\033[1;34m#\033[0;31m          *  *        *      *      *             *     \033[1;34m#\n");
  printf("\t\033[1;34m#\033[0;31m          *  *        *      *      *             *     \033[1;34m#\n");
  printf("\t\033[1;34m#\033[0;31m    *******  *******  ********      *      ********     \033[1;34m#\n");
  printf("\033[1;34m");
	printf("\t#                                                        #\n");
  
  printf("\t##########################################################\n\n");
  printf("\033[0m");
	
  int i;
  
  char startcommand[10];
  int flag=0,sl=0;
	char start_command[5]={'S','t','a','r','t'};
  printf("To continue please type ");
  printf("\033[0;35m");
  printf("\"Start\" \033[0mand to return to the choice of games, enter \033[0;35m\"Exit\"\033[0m\n") ;
  printf("\033[0;35m");
  scanf("%s", startcommand);
  printf("\033[0m");
  
  sl=strlen(startcommand);
	for(i=0;i<4;i++)
  {
      if(start_command[i]!=startcommand[i])
      {
          flag=1;
          break;
      }
  }
  if(sl!=5)
  flag=1;
  if(flag!=0)
  {
    printf("\nGOODBYE!!!\n");
    return 0;
  }
  else
  {
  
  printf("\nYou have been awared ");
  printf("\033[1;34m");
  printf("10,000");
  printf("\033[0m");
  printf(" chips for starting a new game!\n\n");
  chips=10000;
  slots_fn();
  }
  
	return 0;
}
int slots_fn()
{
	int i,j,a,ifg=0,choice=1,rl=0;
  do
  {
  char ch[10],st[4]={'R','o','l','l',},ex[4]={'E','x','i','t',};
  printf("\nType ");
  printf("\033[0;32m");
   printf("\"Roll\"");
  printf("\033[0m");
  printf(", to Play and ");
  printf("\033[0;32m");
   printf("\"Exit\"");
  printf("\033[0m");
  printf(" to Exit the Slots game\n");
  printf("\033[0;35m");
   scanf("%s",ch);
  printf("\033[0m");
  int flag20=0;
  rl=strlen(ch);
  for(i=0;i<4;i++)
  {
      if(ch[i]!=st[i])
      {
          ifg=1;
          choice=0;
          break;
      }
  }
  if(rl!=4)
  ifg=1;
  if(ifg==1)
  {
    
    do
    {
      if(flag20!=0)
    {
      printf("\033[0;35m");
   scanf("%s",ch);
  printf("\033[0m");
    }
        if(strcmp(ch,"Exit")==0)
        {
        printf("\nGOODBYE!!!\n");
        
     return 0;
   }
   else if(strcmp(ch,"Roll")==0)
   {
     flag20=0;
     break;
   }
   else
    {
      printf("You have entered a wrong choice. Enter either ");
      printf("\033[0;32m");
   printf("\"Roll\"");
  printf("\033[0m");
  printf(", to Play and ");
  printf("\033[0;32m");
   printf("\"Exit\"");
  printf("\033[0m");
  printf(" to Exit the Slots game.\n");
		flag20++;
    }
    }while(flag20!=0);
  }
	
  if(flag20!=0)
  return 0;
  printf("\nEnter the amount you want to bet: ");
  
  int bet=0;
  do
  {
     printf("\033[1;35m");
     scanf("%d",&bet);
     printf("\033[0m");
     if(bet>chips){
     printf("\nEnter an amount less than your chips!!\n");
		 printf("Enter the amount you want to bet: ");}
  }while(bet>chips);
  
  chips-=bet;
	int arr[3][6];
  srand(time(NULL));
	printf("\n\n");
  for(i=0;i<3;i++)
  {
      for(j=0;j<6;j++)
      {
          do
          {
            arr[i][j]=0 + (rand()%10);
          }while(arr[i][j]<0 || arr[i][j]>6);
          
      }
  }
  disp(arr);
  
  //Winning mechanism
  int k,cd=0,ct=0,cq=0,cp=0,cj=0,count=0,chdl=0,x=0,size=6;
  int check[6];
  for(i=0;i<6;i++)
  check[i]=arr[1][i];
  for (i=0;i<size;i++) 
  {
    for (j=i+1;j<size;) 
    {
      if (check[j]==check[i]) 
      {
        for (k=j;k<size;k++) 
        {
          check[k]=check[k+1];
        }
        size--;
      } 
      else
        j++;
    }
  }
  int cl=0,temp=0;
  for(i=0;i<size;i++)
  {
    cl=0;
    temp=check[i];
    for(j=0;j<6;j++)
    {
      if(temp==arr[1][j])
      cl++;
    }
    if(cl==6)
    cj++;
    else if(cl==5)
    cp++;
    else if(cl==4)
    cq++;
    else if(cl==3)
    ct++;   
    else if(cl==2)
    cd++;
  }
  printf("\n");
  printf("\033[1;32m");
  printf("Doubles: %d\n",cd);
  printf("Triplets: %d\n",ct);
  printf("Quads: %d\n",cq);
  printf("Aces: %d\n",cp);
  printf("Jackpot: %d\n",cj);
  printf("\033[0m");
  chip_calc(bet,cd,ct,cq,cp,cj);
  printf("\033[1;34m");
  printf("\nAmount left: %d Chips",chips);
  printf("\033[0m");

  printf("\033[01;33m");
  printf("\n______________________________________________________________\n");
  printf("\033[0m");
    //end of winning mech
  }while(chips>0);
  return 0;
}
void chip_calc(int bet, int cd,int ct,int cq,int cp,int cj)
{
  int win=0;
  int temp=(cd*0*bet*0.2)+(ct*bet*0.3)+(cq*bet*0.8)+(cp*bet*2)+(cj*bet*50);
  if(temp==0)
	win=0;
	else
	win=temp+bet;
  chips+=win;
  printf("\033[1;34m");
  printf("\nYou won: %d Chips", win);
  printf("\033[0m");
}
void disp(int arr[3][6])
{
    int i,j;
    for(i=0;i<3;i++)
    {
				
        printf("\t\t");
        for(j=0;j<6;j++){
					if(i==1)
          {
						printf("\033[1;36m");
  					printf("%d ",arr[i][j]);
  					printf("\033[0m");
					}
          else if(i==0&&j==0)
          {
            printf("\033[1;31m");
  					printf("%d ",arr[i][j]);
  					printf("\033[0m");
          }
          else if(i==0&&j==5)
          {
            printf("\033[1;31m");
  					printf("%d ",arr[i][j]);
  					printf("\033[0m");
          }
          else if(i==2&&j==0)
          {
            printf("\033[1;31m");
  					printf("%d ",arr[i][j]);
  					printf("\033[0m");
          }
          else if(i==2&&j==5)
          {
            printf("\033[1;31m");
  					printf("%d ",arr[i][j]);
  					printf("\033[0m");
          }
					else
					printf("%d ",arr[i][j]);
				}
        printf("\n");
    	
    }
}
