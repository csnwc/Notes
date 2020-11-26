Node *InList(Node *n, char *s)
{

   if(n == NULL) return NULL;
   if(strcmp(n->name, s) == 0) return n;
   return InList(n->next, s);

}
