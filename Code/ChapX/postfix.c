#include <stack.h>
#include <math.h>
#include <Realloc/specific.h>

#define MAXINPUT 1000

int main(void)
{
   char input[MAXINPUT];
   stack* s = stack_init();
   int d, g1, g2;
   while(fscanf(stdin, "%s", input) == 1){
      // If number: push
      if(sscanf(input, FORMATSTR, &d)==1){
         stack_push(s, d);
      }
      else{
         // Must be an operator ?
         assert(stack_pop(s, &g2));
         assert(stack_pop(s, &g1));
         switch(input[0]){
            case '+' :
               d = g1 + g2; break;
            case '-' :
               d = g1 - g2; break;
            case '*' :
               d = g1 * g2; break;
            case '/' :
               d = g1 / g2; break;
            case '^' :
               d = (int)pow(g1,g2); break;
            default:
               fprintf(stderr, "Can't understand ? %d\n", input[0]);
               exit(EXIT_FAILURE);
         }
         stack_push(s, d);
      }
   }
   assert(stack_pop(s, &d));
   printf("Answer = "); printf(FORMATSTR, d); printf("\n");
   if(stack_peek(s, &d) == true){
      fprintf(stderr, "Stack still had items on it (%d) ?\n", d);
      exit(EXIT_FAILURE);
   }
   stack_free(s);

}
