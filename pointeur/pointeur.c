#include <stdio.h>

void address (int *k){
 printf("%p\n",k);
 printf("%d\n",*k);

}

int main() {
 int a = 2;
 address(&a);
 return 0;
}
