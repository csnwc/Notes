Node *InList(Node *n, char *s)
{


   do{
      if(strcmp(n->name, s) == 0)
         return n;
      n = n->next;
   }while(n != NULL);
   return NULL;

}

When the following is run:
   printf("%p\n", InList(start, "Jack"));
   printf("%p\n", InList(start, "Bob"));
   printf("%p\n", InList(start, "Joe"));
The following is returned:
20d58
20cf8
0
