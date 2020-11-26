void DeleteElement(Node l[], int n, int *size)
{
   int i;
   for(i=n+1; i<*size; i++)
      l[i-1] = l[i];
   *size = *size - 1;
}
