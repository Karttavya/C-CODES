#include <stdio.h>
#include <math.h>
int main() {
    printf("7%%5 = %d\n", 7 % 5);
    printf("-7%%5 = %d\n", -7 % 5);
    printf("-7%%-5 = %d\n", -7 % -5);
    printf("7%%-5 = %d\n", 7 % -5);
    return 0;
}
/*
PS D:\Projects\C in 7> cd "d:\Projects\C in 7\" ; if ($?) { gcc floor_division.c -o floor_division } ; if ($?) { .\floor_division }
7%5 = 2
-7%5 = -2
-7%-5 = -2
7%-5 = 2

PS D:\Projects\C in 7> python -u "d:\Projects\C in 7\floor_division.py"
7 % 5 = 2
-7 % 5 = 3
-7 % -5 = -2
7 % -5 = -3
*/