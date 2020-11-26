void PrintList(Node *l)
{

   if(l == NULL) return;

   printf("Name : %s\n", l->name);
   PrintList(l ->next);

}
