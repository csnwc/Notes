Node *InTree(char l, Node *t)
{

   Node *p;

   if(t == NULL) return NULL;

   if(t->letter == l) return t;

   if((p = InTree(l, t->left)) != NULL) return p;

   if((p = InTree(l, t->right)) != NULL) return p;

   return NULL;

}
