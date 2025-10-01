#include <stdio.h>
int main() {
   int age;
   char name[100];
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is %s and your age is %d\n", name, age);
    return 0;
}