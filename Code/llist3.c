Node *DeleteNode(Node *start, char *s)
{

   Node *prev, *l;

   if(!strcmp(start->name, s)) /* 1st in list ? */
      return start->next;

   l = start;
   do{
      prev = l;
      l = l->next;
      if(strcmp(l->name, s) == 0){
         prev->next = l->next;
         return start;
      }
   }while(l != NULL);
   return start;
}
