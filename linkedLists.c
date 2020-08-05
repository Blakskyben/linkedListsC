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

void change(struct LL * linkedList, int value, int newVal)
{ 
    struct Node* node = linkedList->head;
    for (int i = 0; i < linkedList->size; i++)
    {
        if (node->value == value)
        {
            node->value = newVal;
        } 
        node = node->next;
    } 
}

void removeVal(struct LL * linkedList, int index)
{
    struct Node* node2;
    struct Node* node1 = linkedList->head;
    int counter=0;
    int counter1=0;
    while (counter < linkedList->size)
    {
        showLL(linkedList);
        if (counter1==index - 1)
        {
            node2=node1->next;
            node1->next=node1->next->next;
            free(node2);
            linkedList->size--;
            break;

        }
        node1=node1->next;
        counter1++;
        counter++;
    }   
}


int main()
{
    struct LL* ll = createLL();
    add(ll,1045722);
    add(ll, 110);
    add(ll, 110);
    add(ll,102);
    add(ll,13);
    add(ll, 110);
    add(ll, 110);
    //change(ll, 110, 11100);
    //showLL(ll);
    removeVal(ll, 3);
    showLL(ll);
}