/****************************************
  > File Name: link_stu.c
  > Author:       guqiang
  > Mail:         544104926@qq.com
  > Created Time: 2014年11月11日 星期二 19时00分29秒
  > Function:
*****************************************/

#include <stdio.h>
#include <malloc.h>

typedef struct node Node;
typedef Node * Link;

struct node
{
    int num;

    Link next;
};

void create_link(Link *head)
{
    (*head) = (Link)malloc(sizeof(Node));
    (*head)->next = *head;
    (*head)->num = -100;
}

void insert_head_node(Link *head, Link *newnode)
{
    (*newnode)->next = (*head)->next;
    (*head)->next = *newnode;
}

void insert_tail_node(Link *head, Link *newnode)
{
        Link temp = *head;

        while(temp->next != *head)
        {
            temp = temp->next;
        }

        temp->next = *newnode;
        (*newnode)->next = *head;
}

void insert_mid_node(Link *head, Link *newnode, int num)
{
        Link temp = *head;

        while(temp->num != num)
        {
            temp = temp->next;
        }

        (*newnode)->next = temp->next;
        temp->next = (*newnode);
    
}

void delete_node(Link *head, int num)
{
    Link temp = (*head)->next;
    Link p = temp;

        while(temp->num != num)
        {
            p = temp;
            temp = temp->next;
        }

        p->next = temp->next;
        free(temp);
        temp = NULL;
}

void display_link(Link *head)
{
    Link temp = (*head)->next;

    while(temp != *head)
    {
        printf("%d\n",temp->num);
        temp = temp->next;
    }
}

int reverse_link(Link *head)
{
    if((*head)->next->next == *head || (*head)->next == *head)
    {
        return 2;
    }

    Link ptr = (*head)->next;
    Link str = ptr->next;
    Link temp = str->next;

    while(temp != *head)
    {
        str->next = ptr;
        ptr = str;
        str = temp;
        temp = temp->next;
    }

    str->next = ptr;
    (*head)->next->next = *head;
    (*head)->next = str;

    return 0;
}

int main()
{
    Link head;
    int i;

    create_link(&head);

    for(i = 0; i < 10; i++)
    {
        Link temp = (Link)malloc(sizeof(Node));

        if(temp != NULL)
        {
            temp->num = i + 1;

            insert_head_node(&head,&temp);
        }
    }

    display_link(&head);
    reverse_link(&head);
    display_link(&head);

    return 0;
}
