#include<stdio.h>
#include<stdlib.h>

char arr[]={'1','2','3','4','5','6','7','8','9'};
int p1, p2;

void printBox();
void takeInput(int pNo);
int system();
int check();

int main(){
    printBox();
    int count=0, i;
    for(i=0; i<9; i++){
        takeInput(i%2);
        printBox();
        if(check()==1){
            printf("Hurrah! Player %d is the Winner \n", (i%2)+1);
            exit(1);
        }
        
    }
    printf("--Game Over--");

    return 0;
}

void printBox(){
    //To print the box
    system("cls");
    printf("      |      |      \n");
    printf("  %c   |  %c   |  %c   \n",arr[0],arr[1],arr[2]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("  %c   |  %c   |  %c   \n",arr[3],arr[4],arr[5]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("  %c   |  %c   |  %c   \n",arr[6],arr[7],arr[8]);
    printf("      |      |      \n");
}

void takeInput(int pNo){
    if(pNo==0){
        printf("\nPlayer1: ");
        scanf("%d", &p1);
        if(p1>9 || p1<1){
            printf("Please enter a valid position.");
            takeInput(pNo);
        }
        arr[p1-1]='X';
    }
    if(pNo==1){
        printf("\nPlayer2: ");
        scanf("%d", &p2);
        if(p2>9 || p2<1){
            printf("Please enter a valid position.");
            takeInput(pNo);
        }
        arr[p2-1]='O';
    }
}

int check(){
    if(arr[0]==arr[1] && arr[1]==arr[2]) return 1;
    if(arr[3]==arr[4] && arr[4]==arr[5]) return 1;
    if(arr[6]==arr[7] && arr[7]==arr[8]) return 1;
    if(arr[0]==arr[3] && arr[3]==arr[6]) return 1;
    if(arr[1]==arr[4] && arr[4]==arr[7]) return 1;
    if(arr[2]==arr[5] && arr[5]==arr[8]) return 1;
    if(arr[0]==arr[4] && arr[4]==arr[8]) return 1;
    if(arr[2]==arr[4] && arr[4]==arr[6]) return 1;
    else return -1;
}