void PrintLevelOrder(Node *t)
{

   Queue q;
   Node *n;

   InitialiseQueue(&q);
   Insert(t, &q);
   while(!Empty(q)){

      n = Remove(&q);
      if(n != NULL){
         printf("%c\n", n->letter);
         Insert(n->left,  &q);
         Insert(n->right, &q);
      }
   }

}
