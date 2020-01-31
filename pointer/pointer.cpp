#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int a_;
    int b_;
    a_ = *a + *b;
    b_ = *a - *b;
    if (b_ < 0)
        b_ = -b_;
    *a = a_;
    *b = b_;
    return;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}


