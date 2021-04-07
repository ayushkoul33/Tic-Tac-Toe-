//Multiplayer Tic-Tac-Toe Game by Ayush Koul
#include <stdio.h>
#include <stdlib.h>
char player2[20],player1[20];  //player user-names
char t;  // current move symbol(will change after every valid move)
char choic;  // symbol chosen by 1st player

void printmat(char arr[][3])//FUNCTION TO PRINT MATRIX
{
 for(int b=0;b<3;b++)
    {
      printf(" %c | %c | %c ",arr[b][0],arr[b][1],arr[b][2]);
      if(b!=2)
        printf("\n --|---|--\n");
    }
}

void win_name(int i)  //FUNCTION TO PRINT WINNER NAME
{
if(i==0 && choic=='0') // if a row of '0' is found & '0' was chosen by player 1,then player 1 is winner
    printf(" \'%s\'",&player1);
else if(i==0 && choic=='X')  // if a row of '0' is found & '0' was chosen by player 2,then player 2 is winner
    printf(" \'%s\'",&player2);
else if(i==1 && choic=='X')  // if a row of 'X' is found & 'X' was chosen by player 1,then player 1 is winner
    printf(" \'%s\'",&player1);
else                         // if row of 'X' is found & 'X' was chosen by player 2,then player 2 is winner
    printf(" \'%s\'",&player2);
}

int check(char arr[3][3],int i)//FUNCTION TO CHECK IF THERE IS A WIN SITUATION FOR ANY PLAYER
{
    //To check vertically & horizontally
   for(int k=0;k<3;k++)
    {
     if(arr[k][0]==arr[k][1] && (arr[k][2]==arr[k][1] && arr[k][0]=='0'))
     {printf("\tWINNER IS ");win_name(0);return 1;}
     else if(arr[k][0]==arr[k][1] && (arr[k][2]==arr[k][1] && arr[k][0]=='X'))
      {printf("\tWINNER IS ");win_name(1);return 1;}
     else if(arr[0][k]==arr[1][k] && (arr[2][k]==arr[1][k] && arr[0][k]=='0'))
      {printf("\tWINNER IS ");win_name(0);return 1;}
     else if(arr[0][k]==arr[1][k] && (arr[2][k]==arr[1][k] && arr[0][k]=='X'))
      {printf("\tWINNER IS ");win_name(1);return 1;}
    }
    // To check diagonally
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[1][1]=='0')
      {printf("\tWINNER IS ");win_name(0);return 1;}
    else if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[1][1]=='X')
      {printf("\tWINNER IS ");win_name(1);return 1;}
    else if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[1][1]=='0')
      {printf("\tWINNER IS ");win_name(0);return 1;}
    else if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[1][1]=='X')
      {printf("\tWINNER IS ");win_name(1);return 1;}

    // If all entries are filled, then match will obviously be a draw
   if(i==8)
    {
     printf("\t Oops!! This match is a draw");
     return 1;
    }
 return 0;
}

// FUNCTION TO START & PLAY GAME
void start()
 {
 int u; // Input of position for making valid entry by a player
 int n=1; //For checking the current turn is of which player
 char arr[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
 printf("\n\n\n %s will play first",player1);
 printf("\n\n %s please choose a symbol('X' or '0'):",player1);
 scanf("%s",&t);
 choic=t;
 system("cls");
 printf("\nOk,then %s will use %c ",player1,t);
 fflush(stdin);
 printf("and %s will use ",player2);
 if(t=='X')
   printf("0\n\n\n\n");
 else
   printf("X\n\n\n\n");

 printf("          START\n\n");
 printmat(arr);
  for(int i=0;i<9;i++) // As there can be maximum 9 valid moves in a TIC TAC TOE (3*3 Matrix)
  {
   if(n%2==0)
     { printf("\n\n %s play ur move ",player2);}
   else
     { printf("\n\n %s play ur move ",player1);}
  scanf("%d",&u);  // u is the position in matrix to be filled (if it is not already filled)
 switch(u)
 {
  case 1:if(arr[2][0]=='0' || arr[2][0]=='X'){printf("  Invalid Input\n");i--;continue;}arr[2][0]=t;break;
  case 2:if(arr[2][1]=='0' || arr[2][1]=='X'){printf("  Invalid Input\n");i--;continue;}arr[2][1]=t;break;
  case 3:if(arr[2][2]=='0' || arr[2][2]=='X'){printf("  Invalid Input\n");i--;continue;}arr[2][2]=t;break;
  case 4:if(arr[1][0]=='0' || arr[1][0]=='X'){printf("  Invalid Input\n");i--;continue;}arr[1][0]=t;break;
  case 5:if(arr[1][1]=='0' || arr[1][1]=='X'){printf("  Invalid Input\n");i--;continue;}arr[1][1]=t;break;
  case 6:if(arr[1][2]=='0' || arr[1][2]=='X'){printf("  Invalid Input\n");i--;continue;}arr[1][2]=t;break;
  case 7:if(arr[0][0]=='0' || arr[0][0]=='X'){printf("  Invalid Input\n");i--;continue;}arr[0][0]=t;break;
  case 8:if(arr[0][1]=='0' || arr[0][1]=='X'){printf("  Invalid Input\n");i--;continue;}arr[0][1]=t;break;
  case 9:if(arr[0][2]=='0' || arr[0][2]=='X'){printf("  Invalid Input\n");i--;continue;}arr[0][2]=t;break;
  default:i--;continue;
 }
  printf("\n");
  printmat(arr);
 n++;

  if(check(arr,i))
  {
    return; // GAME ENDS
  }
 if(t=='0')t='X';   // change t to 'X' if it was initially '0' or vice-versa for next turn
 else t='0';
  }
}


// Main Function
int main()
{
    int c,d,t=1;
    char j;
    while(t==1)
        {printf("             WELCOME TO MY WORLD");
	printf("\n\n\n");
	printf("     Press 's' to START\n\n");
	printf("     Press 'i' for INSTRUCTIONS\n\n");
	printf("     Press 'e' for EXIT\n\n");
	scanf("%c",&j);

        switch(j)
	{
	 case 's':
         printf("  LOADING........");
	 for(c=1;c<=32767;c++)
	 { for(d=1;d<=32767;d++){}
	 }
         system("cls");
	 printf("\nLet's Go!!!\n\n\n");
	 int i=1;
     printf("\n\nEnter Name of Player 1:");
     scanf("%s",player1);
     printf("\nEnter Name of Player 2:");
     scanf("%s",player2);
	 while(i)
     {
     start();
	 printf("\n\t\tPress 0 to exit or 1 to continue ");
     scanf("%d",&i);
     }
     printf("\n\tTHANKS FROM AYUSH\n");
     exit(0);  //EXIT GAME

         case 'i':
         system("cls");
	 printf("          \tHow To Play:\n\n\n");
	 printf(" This a multi player game, in which your numeric keys of your keyboard acts as respective positions on 3*3 matrix as shown below-> \n\n\n7 |8 |9\n--|--|--\n4 |5 |6\n--|--|--\n1 |2 |3\n\t the above numbers represent respective positions on TIC-TAC-TOE Matrix\n\n");
	 printf(" 1.  Have the first player go first: Though traditionally, the first player goes with X, the first player can decide \n ");
         printf("  whether he wants to go with X or O. These symbols will be placed on the table, in the attempt to have three of them in a row.");
         printf("  \n If you're going first, then the best move you can make is to move into the center.");
	 printf(" This will maximize your chances of winning,\n since you'll be able to");
	 printf(" create a row of three Xs or Os in more combinations this way than if you chose a different square.\n\n\n");
	 printf(" 2.  Have the second player go second: After the first player goes, then the second player ");
	 printf(" should put down his symbol,\n which will be different from the symbol of the first player.");
         printf("  The second player can either try to block the first player\nfrom creating a row of three,or focus on creating his");
	 printf(" or her own row of three. Ideally, the player can do both.\n\n\n");
         printf(" 3.  The first player to draw three of his or her symbols in a row, whether it is horizontal,");
         printf(" vertical, or diagonal, has won tic-tac-toe");
         printf("\n\n\n                      ALL THE BEST ;)\n\n  ");
         printf("\n\nPress 1 to Go Back ");
       scanf("%d",&t);
       system("cls");
    break;

	 case 'e':
         system("cls");
         printf("\n\n\tTry it once, u will love it\n\tBTW THANKS FROM AYUSH\n\n");
	 exit(0);break;
	 default:printf("\nInvalid input, please enter valid input:-\n\n");break;

         }
	system("cls");
     }
 return 0;
}
