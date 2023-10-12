


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char firstname[20];
    char lastname[20];
    char number[10];
    struct node *next;
};

struct node *start = NULL;

struct node *getnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}

void display()
{
    struct node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("**********************************************\n");
        printf("%s\n", temp->firstname);
        printf("%s\n", temp->lastname);
        printf("%s\n", temp->number);
        temp = temp->next;
    }
}

void insert()
{
    struct node *temp, *new_node;
    new_node = getnode();
    temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("ENTER FIRST NAME:\n");
    scanf("%s", new_node->firstname);
    printf("ENTER LAST NAME:\n");
    scanf("%s", new_node->lastname);
    printf("ENTER NUMBER:\n");
    scanf("%s", new_node->number);
    temp->next = new_node;
    new_node->next = NULL;
    printf("**********************************************\n");
    printf("%s\n", new_node->firstname);
    printf("%s\n", new_node->lastname);
    printf("%s\n", new_node->number);
}

struct node *create()
{
    struct node *temp, *new_node;
    if (start != NULL)
        insert();
    else
    {
        new_node = getnode();
        start = new_node;
        temp = start;
        printf("ENTER FIRST NAME:\n");
        scanf("%s", new_node->firstname);
        printf("ENTER LAST NAME:\n");
        scanf("%s", new_node->lastname);
        printf("ENTER NUMBER:\n");
        scanf("%s", new_node->number);
        new_node->next = NULL;
        printf("**********************************************\n");
        printf("%s\n", new_node->firstname);
        printf("%s\n", new_node->lastname);
        printf("%s\n", new_node->number);
    }
}

void search()
{
    struct node *temp;
    char f[10], l[10];
    temp = start;
    printf("ENTER CONTACT TO BE SEARCHED:\n");
    scanf("%s", f);
    scanf("%s", l);
    while (!(strcmp(temp->firstname, f) == 0 && strcmp(temp->lastname, l) == 0))
    {
        temp = temp->next;
    }
    printf("SEARCHED CONTACT IS:\n");
    printf("%s\n", temp->firstname);
    printf("%s\n", temp->lastname);
    printf("%s\n", temp->number);
}

void del()
{
    struct node *pretemp, *temp;
    char f[10], l[20];
    temp = start;
    pretemp = NULL;
    printf("ENTER NAME:");
    fflush(stdin);
    gets(f);
    fflush(stdin);
    gets(l);
    while (temp != NULL)
    {
        if (strcmp(temp->firstname, f) == 0 && strcmp(temp->lastname, l) == 0)
        {
            printf("DELETED CONTACT:\n");
            printf("%s\n", temp->firstname);
            printf("%s\n", temp->lastname);
            printf("%s\n", temp->number);
            if (temp == start)
            {
                start = temp->next;
                free(temp);
            }
            else
            {
                pretemp->next = temp->next;
                free(temp);
            }
            getchar();
            break;
        }
        pretemp = temp;
        temp = temp->next;
    }
    return;
}

int main()
{
    int op, choice;
    do
    {
        printf("-------WELCOME--------\n ");
        printf("1.CREATE CONTACT\n2.DISPLAY ALL CONTACT\n3.DELETE CONTACT\n4.SEARCH CONTACT\n5.exit\n");
        printf("\nENTER YOUR CHOICE:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            del();
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter valid choice\n");
            break;
        }
        printf("DO YOU WANT TO QUIT? 1 FOR NO AND 0 FOR YES:");
        scanf("%d", &op);
    } while (op != 0);
    return 0;
}

