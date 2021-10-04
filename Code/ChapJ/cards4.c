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
   suit s[SUITS] = {hearts, diamonds, spades, clubs};
   for(int i=0; i<DECK; i++){
      // Number 1 .. 13
      d[i].pips = (i%PERSUIT) + 1;
      d[i].st = s[i/PERSUIT];
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
   // Note the +1 below : zero pips not used, but makes easier coding ?
   char pipnames[PERSUIT+1][SMALLSTR] = {"Zero", "One", "Two", "Three",
                                         "Four", "Five", "Six", "Seven",
                                         "Eight", "Nine", "Ten", "Jack", 
                                         "Queen", "King"};
   char suitnames[SUITS][SMALLSTR] = {"Hearts", "Diamonds", "Spades", "Clubs"};
   sprintf(s, "%s of %s", pipnames[c.pips], suitnames[c.st]);
}

#define FIRSTCARD "One of Hearts"
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
