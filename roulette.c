#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void figureWinnings(int betAmount, int number, int betChoice,int numberEntered,char oddorevenEntered,int dozenEntered); 
void showInstructions();
int getBetAmount ();
int spinWheel();
void makeBet();

int main() 
{ 
  //declare the four variables and initilize to zero and x
  int betChoice=0;
  int numberEntered=0;
  char oddorevenEntered='x';
  int dozenEntered=0;
  srand(time(0));

  showInstructions();
while (1)
  { makeBet(&betChoice,&numberEntered,&oddorevenEntered,&dozenEntered);//send the addresses of the variables
  //print values of the four variables

   if (betChoice ==0)
   {
     printf("Goodbye!");
     break;
   }

  int betAmount = getBetAmount(betChoice);

  int number=  spinWheel();
   printf("\nYour random number found by the wheel is %d\n ", number);

  figureWinnings( betAmount,  number,  betChoice, numberEntered, oddorevenEntered, dozenEntered); //INCOMPLETE
  }
  return 0;
}

void showInstructions() 

{
   printf("\nThese are the instructions to play this Roulette Game!\n");
     printf("\nMake sure to follow each one!\n");
  printf("\nThe roulette wheel has the numbers 0 – 36 on it. There are three diffrent ways you can place your bet.\n");
  printf("\n1) Bet on one number. Your payout is 36 times the bet.\n");
  printf("\n2) Bet on either an odd or an even number. Your payout is 2 times the bet\n");
  printf("\n3) Bet on a dozen (first 1-12, second 13-24, third 25-36) Your payout will be three times your bet.\n");
  printf("\nReminder: the number zero does not count for odd or even or dozen,but can count as a number bet.\n");
  printf("\nDo NOT use any decimal numbers!\n\n");
  printf("Choose 0 (zero) to quit");

  return;

}
void makeBet(int *betChoice, int *numberEntered, char *oddorevenEntered,int *dozenEntered) //CHANGE TO POINTERS
{
  //int betChoice;
  printf("\nWhat kind of bet would you like to place? ");
  scanf("%d", &*betChoice);

  while (*betChoice != 0 && *betChoice != 1 && *betChoice != 2 && *betChoice != 3) 
  {
      printf("You have entered an invalid bet choice. Please choose between bets 1-3");
      printf("\nWhat kind of bet would you like to place? ");
      scanf("%d", &*betChoice);
  }

  if (*betChoice == 1)
  {
    //int numberEntered;
    printf("Enter a whole number between 1-36: ");
    scanf("%d", &*numberEntered);
    while (*numberEntered < 1 || *numberEntered > 36)
      {
        printf("You have entered an invalid number. Please choose a number between 1-36.\n ");
        printf("\nEnter a number between 1-36: ");
        scanf("%d", &*numberEntered);
        break;
      }
  }
  else if (*betChoice == 2)
  {
    //char oddorevenEntered;
    printf("\nEnter an E for Even number, or O for odd number: ");
    scanf("\n%c", &*oddorevenEntered);
    while (*oddorevenEntered != 'E' && *oddorevenEntered != 'O' && *oddorevenEntered != 'e' && *oddorevenEntered != 'o') {
      printf("You have entered an invalid character. Please choose either an E for (even number) or an O for (odd number)");
      scanf("\n%c", &*oddorevenEntered);
      break;
    }


  }
  else if (*betChoice == 3)
  {
    //int dozenEntered;
    printf("Enter the dozen you would like to bet on");
    printf("\n1)First dozen: 1-12\n2)Second dozen: 13-24\n3)Third dozen: 25-36\n");
    scanf("%d", &*dozenEntered);
    while (*dozenEntered < 1 || *dozenEntered > 3)
    {
      printf("You have entered an invalid number. Please choose from the dozens between 1-3.\n ");
      printf("Enter the dozen you would like to bet on");
      printf("\n1) First dozen: 1-12\n2)Second dozen: 13-24\n3)Third dozen: 25-36\n");
      scanf("%d", &*dozenEntered);
    }
  }

}
int getBetAmount(int betChoice)
  {
  int betAmount =0;
  printf("How much would you like to bet?");
  scanf("%d", &betAmount);
    return betAmount;
  }
int spinWheel()
{
printf("\nPlease spin the wheel!\n");
int number;


  number = (rand()%37);



return number;
}

void figureWinnings(int betAmount, int number, int betChoice,int numberEntered,char oddorevenEntered,int dozenEntered) //INCOMPLETE
{
  printf("\nYour bet choice was %d\n", betChoice);
  printf("\nYour number entered was %d\n", numberEntered);
  printf("Your odd or even entered was \n%c\n", oddorevenEntered);
  printf("\nYour dozen entered was %d\n", dozenEntered);
  printf("\nYour bet amount was %d", betAmount);
  printf("\n Your random number was %d\n", number);

  if (betChoice == 1 && number == numberEntered)
  {
    int winningNumber = betAmount*36;
    printf("You have won %d!", winningNumber);
  }
  else if (betChoice == 1 && number != numberEntered)
  {
    printf("\nYou have won not won. You can re try!\n");
  }

  if (betChoice == 2 && ((number % 2 == 0 && (oddorevenEntered == 'E' || oddorevenEntered == 'e')) || (number % 2 != 0 && (oddorevenEntered == 'O' || oddorevenEntered == 'o'))))
  {
      int winningNumber = betAmount * 2;
      printf("\nYou have won %d!\n", winningNumber);
  }
  else if (betChoice == 2)
  {
      printf("You have not won. You can re try!\n");
  }
  if (betChoice == 3 && ((dozenEntered == 1 && number >= 1 && number <= 12) || (dozenEntered == 2 && number >= 13 && number <= 24) || (dozenEntered == 3 && number >= 25 && number <= 36)))
  {
      int winningNumber = betAmount * 3;
      printf("\nYou have won %d!\n", winningNumber);
  }
  else if (betChoice == 3)
  {
      printf("You have not won. You can re try!\n");
  }
}


//34 is the winning 


