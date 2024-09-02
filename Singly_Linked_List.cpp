#include<stdio.h>
#include<stdlib.h>
class list{
    struct node{
        int data;
        struct node * next;
    }*head;
    public:
    list() {
        head=NULL;
    }
    void InsertionBeg(int);
    int DeletionEnd();
    void Search(int);
    void Display();

};
int main() {
    list l1;
    int data,choice;
    while(1) {
        printf("\n1.Insert the node.\n2.Delete the node.\n3.Search the node.\n4.Print the linked list.\n5.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                l1.InsertionBeg(data);
                break;
            case 2:
                printf("Deleting the node");
                l1.DeletionEnd();
                break;
       
            case 3:
                int num;
                printf("Enter the data to be searched:");
                scanf("%d",&num);
                l1.Search(num);
                break;
            case 4:
                
                l1.Display();
                break;
            case 5:
                printf("Exiting the program.");
                return 0;
            default:
                printf("Wrong choice. Try again.");

        }
    }
}
void list::InsertionBeg(int data) {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    
    newnode->data=data;
    newnode->next=NULL;
    head=newnode;
}
int list::DeletionEnd() {
     struct node *temp;
        temp=head;
    if(head==NULL) {
        printf("List is empty.");
        return 0;
    }

       
     else if(temp->next==NULL) {
            free(temp);
            head=NULL;
        }

    else  {
   
        if(temp->next->next!=NULL) {
                temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        
        return 0;
    }
}
void list::Display()
{
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp -> next;
        }
        printf("NULL");
    }
}
void list::Search(int num) {
    int pos=0;
    struct node *temp;
    if(head==NULL) {
        printf("List is empty.");
    }
    else{
        temp=head;
        while(temp!=NULL) {
            if(num==temp->data) {
                printf("%d element is found at index %d.",num,pos);
            }
            else {
                temp=temp->next;
                pos++;
            }
        }
    }
}
