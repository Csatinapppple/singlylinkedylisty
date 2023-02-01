#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *head = NULL;
//insert node
void insertNode(int data){
    Node *new = malloc(sizeof(Node));
    if(new == NULL){
        perror("ERROR ALLOCATING MEMORY");
        exit(EXIT_FAILURE);
    }
    *new = (Node){.data = data,.next = head};
    head = new;
}
//delete node by data
void deleteNodeByData(int data){//garbo
    Node *save;
    if(head->data==data){
        save = head->next;
        free(head);
        head=save;
        return;
    }
    //head->x->y->NULL  remove x,   head->next = x->next    free(x)
    Node *last=head,*loop=head;
    while(loop!=NULL){
        if(last!=loop){
            last = last->next; //only moves one before loop
        }
        if(loop->data==data){
            last=loop->next;
            free(loop);
            return;
        }
        loop=loop->next;
    }
}
//delete node by position
void deleteNodeByPosition(int pos){
    Node *save;
    if(pos==0&&head!=NULL){
        save = head;
        head = head->next;
        free(save);
        return;
    }
    Node *loop =head,*behind;
    while (pos>=0)
    {   // 0  1    2 
        //23->25->NULL
        if(loop==NULL){
            break;
        }
        if(pos==1){
            behind=loop;
        }
        if(pos==0){
            behind->next=loop->next;
            free(loop);
        }
        loop = loop->next;
        pos--;
    }
    
}
//print nodes
void printNodes(){
    Node *loop = head;
    int iter=0;
    while(loop!=NULL){
        printf("%d(index = %d)->",loop->data,iter);
        loop = loop->next;
        iter++;
    }
    putchar('\n');
}
//print choices
void printChoices(){
    puts("1. insert node");
    puts("2. delete node by data");
    puts("3. print nodes");
    puts("4. exit");
    puts("5. delete node by position");
}
int main(){
    int end = 0;
    while(end==0){
        int choice,data;
        printChoices();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                scanf("%d",&data);
                insertNode(data);
                break;
            case 2:
                printNodes();
                scanf("%d",&data);
                deleteNodeByData(data);
                break;
            case 3:
                printNodes();
                break;
            case 4:
                end=1;
                break;
            case 5:
                printNodes();
                scanf("%d",&data);
                deleteNodeByPosition(data);
                break;
        }
    }
    return 0;
}
