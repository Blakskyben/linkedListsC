#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};


struct LL {
    struct Node* head;
    int size;
};

struct LL* createLL()
{
    struct LL* ll; 
    ll = malloc (sizeof (struct LL));
    ll->size = 0;
    ll->head = NULL;
    return ll;
}

int add(struct LL* linkedList, int value)
{
    if(linkedList == NULL){
        printf("There is no Linked-List yet. Run the createLL function.");
        return -1;
    }

    if (linkedList->head == NULL)
    {
        linkedList->head = malloc (sizeof (struct Node));
        linkedList->head->value = value;
    } else {
        struct Node* node = linkedList->head;
        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = malloc (sizeof (struct Node)); 
        node->next->value = value;
    }
    linkedList->size = linkedList->size+1;
    return 0;

}

int showLL(struct LL* linkedList)
{
    printf("The linked list's size is: %d \n", linkedList->size);
    struct Node* node = linkedList->head;
    while(node != NULL){
        printf("%d \n", node->value);
        node = node->next;
    }
}

void change(int value, int newVal)
{

}

void removeVal(int value)
{

}


int main()
{
    struct LL* ll = createLL();
    add(ll,1022);
    add(ll,102);
    add(ll,110);
    add(ll,5);
    showLL(ll);
}