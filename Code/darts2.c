#include <stdio.h>
#define NUM_POSS_SCORES 62
void finishes(int n);

int main(void)
{
   int d1, d2, d3, n;
   int s[] = {1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
              17, 18, 19, 20, 2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22, 24,
              26, 28, 30, 32, 34, 36, 38, 40, 3,  6,  9, 12, 15, 18, 21, 24,
              27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 25, 50};
   char t[]="SSSSSSSSSSSSSSSSSSSSDDDDDDDDDDDDDDDDDDDDTTTTTTTTTTTTTTTTTTTTOB";
   int b[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,
            2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1};
   printf("Enter a score  : ");
   scanf("%d", &n); /* e.g 151 */
   for(d1=0; d1<NUM_POSS_SCORES; d1++)
      for(d2=0; d2<NUM_POSS_SCORES; d2++)
         for(d3=0; d3<NUM_POSS_SCORES; d3++)
            if(s[d1]+s[d2]+s[d3] == n && (t[d3] == 'D' || t[d3] == 'B'))
               printf("%c%d %c%d %c%d\n", t[d1], s[d1]/b[d1],
                      t[d2], s[d2]/b[d2], t[d3], s[d3]/b[d3]);
   return 0;
}

/* Results
T17 T20 D20
T17 B50 B50
T18 T19 D20
T19 T18 D20
T19 T20 D17
T20 T17 D20
T20 T19 D17
B50 T17 B50
*/
