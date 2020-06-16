#include <stdio.h>

int main() {
 int a = 2;
 int *b = &a;
 printf("%p\n",b);
 printf("%d\n",*b);
 return 0;
}
