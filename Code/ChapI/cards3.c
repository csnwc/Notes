#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SUITS 4
#define PERSUIT 13
#define DECK (SUITS*PERSUIT)
#define SHUFFLE 3
#define BIGSTR 50

typedef enum {hearts, diamonds, spades, clubs} suit;

struct card {
   suit st;
   int pips;
};
typedef struct card card;

void shuffle_deck(card d[DECK]);
void init_deck(card d[DECK]);
void print_deck(card d[DECK], int n);
void print_card(char s[], card c);
void test(void);

int main(void)
{
   card d[DECK];

   test();
   init_deck(d);
   print_deck(d, 7);
   shuffle_deck(d);
   print_deck(d, 7);
   return 0;
}

void init_deck(card d[DECK])
{
   for(int i=0; i<DECK; i++){
      // Number 1 .. 13
      d[i].pips = (i%PERSUIT) + 1;
      switch (i/PERSUIT) {
         case hearts: d[i].st = hearts; break;
         case diamonds: d[i].st = diamonds; break;
         case spades: d[i].st = spades; break;
         case clubs: d[i].st = clubs; break;
         // Force an abort ?
         default : assert(false);
      }
   }
}

void shuffle_deck(card d[DECK])
{
  for(int i=0; i<SHUFFLE*DECK; i++){
     int n1 = rand()%DECK;
     int n2 = rand()%DECK;
     card c = d[n1]; d[n1] = d[n2]; d[n2] = c;
  } 
}

void print_deck(card d[DECK], int n)
{
   char str[BIGSTR];
   for(int i=0; i<n; i++){
      print_card(str, d[i]);
      printf("%s\n", str);
   }
   printf("\n");
}

#define SMALLSTR 20
void print_card(char s[], card c)
{
   
   char pipstr[SMALLSTR];
   char suitstr[SMALLSTR];
   switch(c.pips){
      case 11:
         strcpy(pipstr, "Jack");
         break;
      case 12:
         strcpy(pipstr, "Queen");
         break;
      case 13:
         strcpy(pipstr, "King");
         break;
      default:
         sprintf(pipstr, "%2i", c.pips);
   }
   switch(c.st){
      case hearts :
         strcpy(suitstr, "Hearts");
         break;
      case diamonds :
         strcpy(suitstr, "Diamonds");
         break;
      case spades:
         strcpy(suitstr, "Spades");
         break;
      default :
         strcpy(suitstr, "Clubs");
   }
   sprintf(s, "%s of %s", pipstr, suitstr);
}

#define FIRSTCARD " 1 of Hearts"
void test(void)
{
   int n = 0;
   char str[BIGSTR];
   card d[DECK];
   init_deck(d);
   // Direct assignment
   print_card(str, d[0]);
   // 1st element initialised correctly
   assert(strcmp(str, FIRSTCARD)==0);
   for(int i=0; i<1000; i++){
      shuffle_deck(d);
      print_card(str, d[0]);
      // Happens 1 time in 52 ?
      if(strcmp(str, FIRSTCARD)==0){
         n++;
      }
   }
   // Is this a reasonable test ? 
   assert((n > 10) && (n < 30));
}
