#include <stdio.h>
int main()
{
   bool a = true;
   a = false;

   a = 123;

   a = 3.14;

   a = 0;
   //   a = 1;

   printf("%d\n", sizeof(bool));
   //   printf("%d\n", a);
   return 0;
}
