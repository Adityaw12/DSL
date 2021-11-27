//ADITYA WAGH 65

#include <stdio.h>

void insert(void);
void delete (void);
void display(void);
int queue[100], n, choice, i;
int front = -1;
int rear = -1;
int main()
{
    printf("Enter the Size of Queue less than 100: ");
    scanf("%d", &n);
    do
    {
        printf("Enter Your Choice \n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exit");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);
}
void insert()
{
    int num;
    if (rear >= n - 1)
        printf("Queue is Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        // rear=0;
        printf("enter the element to insert\n");
        scanf("%d", &num);
        rear = rear + 1;
        queue[rear] = num;
    }
}
void delete ()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Underflow \n");
        // return ;
    }
    else
    {
        printf("Element deleted from is : %d\n", queue[front]);
        front = front + 1;
    }
}
void display()
{
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}