#include <stdio.h>
#include <stdlib.h>

void randname(char *str);
int check_str(char *str);
int cons(char *str);
int isvowel(char c);
int isin(char *str, char c);

int main(void)
{

  char str[10];
  int j;

  j=0;
  do{
     randname(str);
     if(check_str(str)){
       printf("%s\n", str);
       j++;
     }
  }while(j<100);

  return 0;

}

void randname(char *str)
{

  int i;
  int l;

  l = rand()%2 + 3;
  for(i=0; i<l; i++){
     str[i] = rand()%26 + 'a';
  }
  str[i] = '\0';
  

}

int check_str(char *str)
{

   int a, b;

   /* 1 */
   if(cons(str) > 2) return 0;

   /* 2 */
   a = isvowel(str[0]);
   b = isvowel(str[1]);
   if(a==b) return 0;

   /* 3 */
   if((a=isin(str, 'q')) != -1 && str[a+1] != 'u') return 0;
   
   return 1;

}

int isin(char *str, char c)
{

   int i=0;

   while(*str){
      if(*str == c) return i;
      str++;i++;
   }

   return -1;

}

int cons(char *str)
{

   int cnt = 0, bc = 0;

   while(*str){
      if(isvowel(*str)){
         if(cnt > bc) bc = cnt;
      }
      else{
         cnt++;
      }
      str++;
   }

   return bc;
}

int isvowel(char c)
{

   if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c == 'y') return 1;
   return 0;

}
