#include <stdio.h>
#include <stdlib.h>

#define BADVAL -9999

//CLass code for binary search tree and associated functions taken here.
struct node {
    int key;
    struct node *left, *right;
};

//Class code: Regular binary search tree functions.
struct node *createNode(int k) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

void displayNode(struct node *temp) {
    if (temp == NULL)
        printf("Node does not exist\n");
    else
        printf("%p %d\n", (void *)temp, temp->key);
}

struct node *search(struct node *anode, int k) {
    struct node *temp;
    if (anode == NULL)
        return NULL;
    temp = anode;
    while (temp != NULL) {
        if (temp->key == k) {
            return temp;
        }
        if (k < temp->key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return NULL;
}

struct node *insert(struct node *anode, int k) {
    struct node *temp, *parent;
    int direction;
    if (anode == NULL) {
        anode = createNode(k);
        return anode;
    }
    temp = anode;
    while (temp != NULL) {
        if (temp->key == k) {
            printf("Node with value %d already exists\n", k);
            return temp;
        }
        parent = temp;
        if (k < temp->key) {
            temp = temp->left;
            direction = 0;
        } else {
            temp = temp->right;
            direction = 1;
        }
    }
    temp = createNode(k);
    if (direction == 0)
        parent->left = temp;
    else
        parent->right = temp;
    return temp;
}


// Stack code from class modified to become stack containing pointers that point at binary search tree nodes.
struct NODE {
    //struct node, ie, nodes from binary search tree will occupy the data cell of the linked list.
    struct node *info;
    //struct NODE, ie, nodes from linked list defined by us.
    struct NODE *next;
};

typedef struct NODE *NODEPTR;

//Create new node in the stack.
NODEPTR creation(struct node *elm) {
    NODEPTR temp = (NODEPTR)malloc(sizeof(struct NODE));
    //Elm is address to binary search tree node, info is a pointer to it.
    temp->info = elm;
    temp->next = NULL;
    return temp;
}

//Regular stack functions like checking for empty, push and pop. This push and pop feature will help us with inorder traversal.
int isEmpty(NODEPTR p) {
    if (p == NULL)
        return 1;
    else
        return 0;
}


struct node* pop(NODEPTR *ap) {
    NODEPTR temp;
    struct node *val;
    if (isEmpty(*ap))
        return BADVAL;
    else {
        temp = *ap;
        (*ap) = (*ap)->next;
        val = temp->info;
        free(temp);
        return val;
    }
}

void push(NODEPTR *ap, struct node *elm) {
    NODEPTR temp;
    temp = creation(elm);
    if (*ap == NULL)
        *ap = temp;
    else {
        temp->next = *ap;
        *ap = temp;
    }
}

//Unneeded, helpful during building the code and testing for accuracy.
void printStack(NODEPTR p) {
    NODEPTR temp;
    if (isEmpty(p)) {
        printf("Stack empty\n");
        return;
    }
    for (temp = p; temp != NULL; temp = temp->next)
        printf("%p\n", (void *)temp->info);
}

/*INORDER TRAVERSAL WITHOUT RECURSION! Uses a while loop to locate lower leftmost node, print, locate nearest central node, print, locate right node and then restart the journey for the leftmost lowest node within that sub-branch.*/
void inorder(struct node *root) {
    struct node* current = root;
    NODEPTR stack = NULL;
    //Actual loop conditions defined inside, "while (1)"" is just an infinite loop used to evoke an overarching loop of multiple actions, here, finding leftmost node and then finding central node and right child. 
    while (1){
        //Reaching node with no further left child.
        while (current != NULL) {
            //Stores currently visited value of binary tree into stack.
            push(&stack, current);
            //Moves onwards towards leftmost node.
            current = current->left;
        }
        //Break "While (1)"" loop after all elements of stack are popped out.
        if (isEmpty(stack)) {
            break;
        }
        //Pop elements of stack in last-in-first-out order.
        current = pop(&stack);
        printf("%d ", current->key);
        //Traversing right child of popped elements.
        current = current->right;
    }
}


int main() {
    struct node *root = NULL, *temp;
    int elm, menu;
    while (1) {
        printf("0. exit, 1. initialize, 2. search, 3. insert, 4. inorder. Input Choice: ");
        scanf("%d", &menu);
        switch (menu) {
            case 0:
                exit(0);
            case 1:
                root = NULL;
                break;
            case 2:
                printf("Give element to search: ");
                scanf("%d", &elm);
                temp = search(root, elm);
                displayNode(temp);
                break;
            case 3:
                printf("Give element to insert: ");
                scanf("%d", &elm);
                if (root == NULL)
                    temp = root = insert(root, elm);
                else
                    temp = insert(root, elm);
                displayNode(temp);
                break;
            case 4: inorder(root);
                printf("\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
