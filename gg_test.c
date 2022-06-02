// #include<windows.h>
// #include<stdio.h>
// //
// struct playerprop{
//     char name[10];
//     int colour;
//     int pos[2];
//     long long int money;
//     //TODO Properties
// }players[4];

// int main()
// {
//     // players[0].name=;
//     // for(int i=0;i<256;i++){
//     //     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
//     //     printf("%d-This text is for Testing...\n",i);
//     // }
//     /*
//     Red - 71
//     Green - 39
//     Blue - 23
//     Purple - 86
//     Cyan - 55
//     NORMAL - 7
//     */
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),71); // Red
//     printf(" G ");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
//     printf("-RED\n");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),39); // Green
//     printf(" J ");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
//     printf("-Green\n");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),23); // Blue
//     printf(" P ");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
//     printf("-Blue\n");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),86); // Purple
//     printf(" M ");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
//     printf("-Purple\n");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),55); // Cyan
//     printf(" R ");
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
//     printf("-Cyan\nThis text is for Testing...\n");
//     printf("LOLEFOFL");
//     return 0;
// }

// gcc gg_test.c -o gg





// #define clear() printf("\033[H\033[J")
// #define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
// struct player{
//     char *name;
//     char *colour;
//     int pos[2];
//     long long int money;
// }A,B,C,D;
// #include<stdio.h>
// #include<string.h>
// char rep(char str[]) {
//     // printf("----%s\n",str);
//     for(int i=0;i<strlen(str);i++) {
//         for(int j=i+1;str[j]!='\0';j++) {
//             if(str[i]==str[j]) {
//                 for(int k=j;str[k]!='\0';k++) {
//                     str[k]=str[k+1];
//                 }
//             }
//         }
//     }
// }


//getch,getche,getchar,putc,putchar,puts
// #define P(buff,txt) printf("%s---->%d\n",txt,buff);
// #include<stdio.h>
// int main(){
    // int s1[10]={1,21,32,43,54,65,76,87,98,109},s2=22,s3=33,s4=44;
    // int *a,*b=&s2,*c,*d;
    // a=s1;
    // c=&s3;
    // d=&s4;
    // P(*a,"*a")
    // P(*a++,"*a++")
    // P(*a,"*a")
    // P(++*a,"++*a")
    // P(*a,"*a")
    // P((*a)++,"(*a)++")
    // P(*a,"*a")
    // P(++(*a),"++(*a)")
    // P(*a,"*a")
    // P(*(++a),"*(++a)")
    // P(*a,"*a")
    // a=a+8;
    // P(*a,"*a")
    // for(int i=0;i<10;i++) {P(s1[i],"")}
    // char a[10],b[10],c,d,e;
    // gets(a);
    // printf("%s\n",a);
    // c = getch();
    // printf("%c\n",c);
    // c = getche();
    // printf("%c\n",c);
    // d = getchar();
    // printf("%c\n",d);
    // putchar(d);printf("\n");
    // puts(a);
    // int a[5];
    // for(int i=0;i<5;i++) {
    //     scanf("%d",&a[i]);
    // }
    // for(int i=0;i<5;i++) {printf("-%d",a[i]);}
    // char *a[4];
    // char (*b)[4];
    // printf("%d\n%d",sizeof(a),sizeof(b));

    //Binary Search
    // int n=5;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     a[i]=100+i;
    //     printf("%d\n",a[i]);
    // }
    // int se=102;
    // int lb=0,flag=0,pos;
    // int ub = n-1;
    // int mid = (lb+ub)/2;
    
    // while(lb<ub){
    //     if(a[mid]>se){
    //         ub=mid-1;
    //     }else if(a[mid]<se){
    //         lb=mid+1;
    //     }else{
    //         pos=mid;
    //         flag =1;
    //         break;
    //     }
    // }
    // if(flag){
    //     printf("%d",pos);
    // }
// }
// #include<stdio.h>
// int main() {
//     int n;
//     scanf("%d",&n);
//     int pas[n][n];
//     for(int i=0;i<n;i++) {
//         for (int j=0;j<n;j++) {
//             if (j==0) {
//                 pas[i][j]=1;
//             } else {pas[i][j]=0;}
//         }
//     }

//     for(int i=1;i<n;i++) {
//         for(int j=1;j<n;j++) {
//             pas[i][j]=pas[i-1][j]+pas[i-1][j-1];
//         }
//     }
//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//             if(pas[i][j]!=0){printf("%d ",pas[i][j]);}
//             if(j==n-1) {printf("\n");}
//         }
//     }
// //
// }


#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

// #define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
// int main() {
//     char card_lines[100];
//     int line=1,cursor_offset=0;
//     FILE* card_disp;
//     int crd_no=4;
//     card_disp=fopen("Cards.txt","r");
//     while(!feof(card_disp)) {
//             fgets(card_lines,100,card_disp);
//         if(line >(crd_no-1)*16 && line<=((crd_no)*16)+1){
//             gotoxy(95,20+(cursor_offset++));
//             printf(card_lines);
//         } if(line == crd_no*16) break;
//         line++;
//     }printf("\n");
//     fclose(card_disp);
// }
// typedef struct practice {
//     int a;
//     int b;
//     int d[20];
//     char c;
//     struct practice *next;
// }p;
// int main() {
//     printf("%d", sizeof(p));
// }


#include<stdio.h>
#include<stdlib.h>
typedef struct _llnode{
    int data;
    int priority;
    struct _llnode *next;
}LLnode;

void display(LLnode *A){
    if(A==NULL){
        printf("No Elements");
        return;
    }
    while(A!=NULL){
        printf("%d %d",A->data,A->priority);
        A=A->next;
    }
}
void insert(LLnode *A,int data, int priority){
    LLnode *temp = (LLnode*)malloc(sizeof(LLnode));
    temp->priority = priority;
    temp->data = data;
    while(A->next!=NULL){
        if(A->next->priority<priority)break;
        A=A->next;
    }
    temp->next=A->next;
    A->next=temp;
}
LLnode * dequeue(LLnode *A,int data, int priority){
    LLnode *temp = (LLnode*)malloc(sizeof(LLnode));    
    while(A->next!=NULL){
        if(A->next->priority==priority && A->next->data==data){
            temp=A->next;
            A->next=temp->next;
            return temp;
        }
        A=A->next;
    }
}
int main(){
    int n, data, priority;
    LLnode *head;
    while(1){
        scanf("%d",&n);
        switch(n){
            case 1:
                scanf("%d %d",&data,&priority);
                insert(head,data,priority);
                break;
            case 2:
                scanf("%d %d",&data,&priority);
                dequeue(head,data,priority);
                break;
            case 3: display(head); break;
            case 4: return 0;
        }
    }
    return 0;
}