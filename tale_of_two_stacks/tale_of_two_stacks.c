#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 10000000

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int num){
    queue[++rear] = num;
}

void dequeue(){
    front++;
}

void display(){
    printf("%d\n",queue[front+1]);
}


int main() {

    int n,i=0, choose,num;
    scanf("%d",&n);
    while(i<n){
        scanf("%d",&choose);
        switch(choose){

            case 1:
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
        }
        i++;
    }


    return 0;
}
