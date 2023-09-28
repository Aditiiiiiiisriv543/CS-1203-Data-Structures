#include <stdio.h>
#include <stdlib.h>

#define BADVAL -9999

//Building block for a linked list node, consisting of information followed by the address of the next node.
struct node
    {
    int info;
    struct node *next;
    };

//Struct node* is a pointer to a node for linked lists, we have named it Nodeptr.
typedef struct node*NODEPTR;

//We have defined a queue now, with its characteristic front and rear pointers.
typedef struct queue{
    NODEPTR front, rear;
    } QUEUE;

//Function to create new node, takes value to insert into new end node, to be used in insert/enqueue.
NODEPTR createNode(int val){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof(struct node));
    p->info = val;
    p->next = NULL;
    return p;
    }
 
 //Function to delete first entry from queue, we shift the front pointer to the next node, removing first value from queue.
int delete(QUEUE *q){
    NODEPTR temp;
    int val;
    //Replaced *afront in class code with q->front, the front element in the queue (linked list).
    //Return NULL if empty queue.
    if (q->front == NULL) return BADVAL;
    else{
        //We assign temporary variable to the first value of queue to return to user the deleted value.
        temp = q->front;
        //We move the front pointer to the next entry, effectively deleting the first value.
        q->front = q->front->next;
        val = temp->info;
        free(temp);
        if (q->front == NULL)
            //Replace *arear in class code with q->rear, last element of queue.
            q->rear = NULL;
        return val;
        }
    }
  
//Function to insert new entry to end of queue, uses createnode.
void insert(QUEUE *q, int elm){
    NODEPTR temp;
    //Temp stores the new node created with user-given value "elm".
    temp = createNode(elm);
    if (q->front == NULL)
        {
        //Front and rear are at the same node if this is the first value in an otherwise empty queue.
        q->front = temp;
        q->rear = temp;
        }
    else
        {
        //Inserts new value (stored in temp), after existing rear, makes temp as the new rear of the queue as it the last value now.
        (q->rear)->next = temp;
        q->rear = temp;
        }
    }
    
//Prints out all elements of queue by inducing a for-loop and going through list with temp variable.
void printQueue(QUEUE *q){
    NODEPTR temp;
    if (q->front == NULL){
        printf("Queue empty\n");
        return;
        }
    printf("F ->");
    for (temp = q->front; temp!= NULL; temp = temp->next)
        printf("%d ", temp->info);
    printf("<- R\n");
    }
    
    
//Main function, initialise required to start, other functions include delete, insert, print.    
int main(){
    QUEUE q1;
    int elm, menu;
    while(1){
        printf("0. exit, 1. initialize, 2. delete, 3. insert, 4. print. Input Choice: ");
        scanf("%d", &menu);
        switch(menu){
            case 0: exit(0);
            case 1: q1.front =q1.rear = NULL;
            break;
            case 2: printf("Popped Value %d\n", delete(&q1));
            break;
            case 3: printf("Give element: ");
            scanf("%d", &elm);
            insert(&q1, elm);
            break;
            case 4: printQueue(&q1);
            break;
            default: printf("Wrong choice\n");
            }
        }
    }

