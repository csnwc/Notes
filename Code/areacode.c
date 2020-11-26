#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 3517

typedef struct{
    char *code;
    char *place;
} Entry;

int global_k = 0;

void ClearHashTable(Entry table[HASHSIZE]);
void BuildTable(Entry table[HASHSIZE], char *name);
int LookUp(Entry table[HASHSIZE], char *cd, int *k);

int main(void)
{

   Entry table[HASHSIZE];
   char fname[250];
   char str[250];
   int n;
   int i, j;

   printf("Enter file from which to build Hash table : ");
   fflush(stdout);
   scanf("%s", fname);

   ClearHashTable(table);
   BuildTable(table, fname);

   while(1){
      printf("Enter an Area-Code : ");
      fflush(stdout);
      scanf("%s", fname);
      n = 0;
      i = LookUp(table, fname, &n);
      if(i >= 0){
         printf("It's a \"%s\" Area Code (%d clashes)\n", table[i].place, n);
      }
      else{
         for(j=0; j<=9; j++){
            sprintf(str, "%s%d", fname, j);
            if((i = LookUp(table, str, &n)) > 0){
               printf("%s is a \"%s\" Area Code\n", str, table[i].place);
            }
         }
      }
   }

   return 0;


}

void ClearHashTable(Entry table[HASHSIZE])
{

   int i;

   for(i=0; i<HASHSIZE; i++){
      table[i].code = NULL;
      table[i].place = NULL;
   }

}

int DoubleHash(int i)
{

   return (HASHSIZE - 2 - (i%(HASHSIZE-2)));
   /*return (1);*/

}

int HashFunction(char *str)
{

   int i, j, k;

   k = strlen(str);
   j = 1;
   for(i=k-1; i>=0; i--){
      j *= (int)(str[i] - '0' + 1);
   }
   j = j % HASHSIZE;

   return j;

}

int LookUp(Entry table[HASHSIZE], char *cd, int *k)
{

   int i, j;
   int n = 0;

   i = HashFunction(cd);
   j = DoubleHash(i);

   while((table[i].code == NULL || strcmp(table[i].code, cd)) && n < HASHSIZE){
      i += j;
      i = i % HASHSIZE;
      n++;
   };

   *k += n;
   if(n < HASHSIZE) return i;
   else return -1;

}

void AddEntry(Entry table[HASHSIZE], char *cd, char *pl)
{

   int i, j;

   i = HashFunction(cd);
   j = DoubleHash(i);

   while(table[i].code != NULL){
      i += j;
      i = i % HASHSIZE;
   };
   printf("Putting (%s, %s) into %4d (Secondary = %d)\n", cd, pl, i, j);
   table[i].code  = (char *)strdup(cd);
   table[i].place = (char *)strdup(pl);
   if(table[i].code == NULL || table[i].place == NULL){
      printf("Failed to create space for entry ... \n");
      exit(2);
   }
   
}

void BuildTable(Entry table[HASHSIZE], char *name)
{

   FILE *fp;
   char *c;
   char cd[250];
   char str[500];
   int j;

   if(!(fp = fopen(name, "r"))){
      printf("Cannot read %s\n", name);
      exit(2);
   }

   do{
      c = fgets(str, 500, fp);
      j = sscanf(str, "%s", cd);
      *(strlen(str) + str - 1) = '\0';
      if(j == 1 && c != NULL){
         AddEntry(table, cd, str+strlen(cd)+1);
      }
   }while(j == 1 && c != NULL);

   fclose(fp);

}
