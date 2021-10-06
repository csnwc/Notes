#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#define SUITS 4
#define PERSUIT 13
#define DECK (SUITS*PERSUIT)
#define SHUFFLE 3

typedef enum {hearts, diamonds, spades, clubs} suit;

struct card {
   suit st;
   int pips;
};
typedef struct card card;

void shuffle_deck(card d[DECK]);
void init_deck(card d[DECK]);
void print_deck(card d[DECK], int n);
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
   for(int i=0; i<n; i++){
      switch(d[i].pips){
         case 11:
            printf("Jack");
            break;
         case 12:
            printf("Queen");
            break;
         case 13:
            printf("King");
            break;
         default:
            printf("%2i", d[i].pips);
      }
      switch(d[i].st){
         case hearts :
            printf(" of Hearts\n");
            break;
         case diamonds :
            printf(" of Diamonds\n");
            break;
         case spades:
            printf(" of Spades\n");
            break;
         default :
            printf(" of Clubs\n");
      }
    }
    printf("\n");   
}

void test(void)
{
   int n = 0;
   card d[DECK];
   init_deck(d);
   // Direct assignment
   card c = {hearts, 10};
   // 1st element initialised correctly
   assert(d[9].pips == c.pips);
   assert(d[9].st == c.st);
   for(int i=0; i<1000; i++){
      shuffle_deck(d);
      // Happens 1 time in 52 ?
      if((d[0].st == c.st) && (d[0].pips == c.pips)){
         n++;
      }
   }
   // Is this a reasonable test ? 
   assert((n > 10) && (n < 30));
}
