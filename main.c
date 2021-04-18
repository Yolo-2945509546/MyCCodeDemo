#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef struct List{
    Node *head;
    Node *last;
    int size;
}List;

void CreateList(List *list);
void Initlist(List *list);
void show(List *list);
Node *search1(List *list);
Node *search2(List *list);

int main()
{
    List list;
    Initlist(&list);
    CreateList(&list);
    show(&list);
    search2(&list);
	show(&list);
    return 0;
}

void search2(List *list){
    int key;
    int i = 0;
    printf("请输入想要找到的链表倒数第  个节点: \b\b\b\b\b\b\b\b\b");
    scanf("%d", &key);
    if(key <= 0||list->size == 0){
        return;
    }
    Node *fast = list->head;
    Node *slow = list->head;
    while(fast->next != NULL&& i < key){
        fast = fast->next;
        ++i;
    }
    while(fast ->next){
        fast = fast->next;
        slow = slow->next;
    }
	slow->data = slow->next->data;
	slow->next = slow->next->next;
    return;
}

Node *search1(List *list){
    int key;
    printf("请输入想要找到的链表倒数第  个节点: \b\b\b\b\b\b\b\b\b");
    scanf("%d", &key);
    if(key <= 0||list->size == 0){
        return;
    }
    Node *p = list->head;
    int x = list->size - key + 1;
    for(int i = 0; i < x - 1; ++i){
        p = p->next;
    }
    return p->next;
}

void Initlist(List *list){
    Node *s = (Node *)malloc(sizeof(Node));
    list->head = list->last = s;
    list->head->next = NULL;
    list->size = 0;
}

void CreateList(List *list){
    int x;
    printf("请输入生成的链表节点个数：");
    scanf("%d", &x);
    for(int i = 0; i < x; ++i){
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = i + 1;
        p->next = NULL;
        list->last->next = p;
        list->last = p;
        list->size++;
    }
}

void show(List *list){
    Node *p = list->head->next;
    while(p){
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
