#include<stdio.h>
#include<stdlib.h>
#define FAIL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
    struct listNode * prev;
};

struct listNode * list;

struct listNode * tail;

void initializeList()
{
    list = 0;  //initially set to NULL
    tail = 0;
}

void insertFirst(int item) //insert at the beginning
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->prev = 0;
	newNode->next = list;

	/*if(list!=0) //inserting the first item
    {
        list->prev = newNode;
    }
	list = newNode;*/
	if(list == 0)
    {
        tail = newNode;
    }
    else
    {
        list->prev = newNode;
    }list = newNode;
}


int insertBefore( int oldItem, int newItem)
{
    //write your codes here
    struct listNode *curr, *x, *y, *ZnewNode;
    ZnewNode = (struct listNode*) malloc (sizeof(struct listNode));

    curr = tail;
    while(curr != 0)
    {
        if(curr->item == oldItem)
        {
            break;
        }
        curr = curr->prev;
    }
    if(curr == 0)
    {
        return FAIL_VALUE;
    }
    x = curr;
    y = curr->prev;
    ZnewNode->item = newItem;
    ZnewNode->prev = y;
    ZnewNode->next = x;
    x->prev = ZnewNode;
    if(y == 0)
    {
        list = ZnewNode;
    }
    else
    {
        y->next = ZnewNode;
    }
   return SUCCESS_VALUE;
}

int deleteAfter(int olditem)
{
    //write your codes here
    struct listNode *curr;

    if (list == NULL) {
        return FAIL_VALUE;
    }
    else{
    curr = list;
    while(curr != 0)
    {
        if(curr->item == olditem)
        {
            curr->next = curr->next->next;
            return SUCCESS_VALUE;
        }
      curr = curr->next;
      curr->next->next->prev = curr->next->prev;
    }
  }
}


struct listNode * searchItem(int item)
{
	struct listNode * temp ;
	temp = list ; //start at the beginning
	while (temp != 0)
	{
		if (temp->item == item) return temp ;
		temp = temp->next ; //move to next node
	}
	return 0 ; // not found; 0 means invalid pointer in C, also called NULL value in C
}

void printListForward()
{
    struct listNode * temp;
    temp = list;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void printListBackward()
{
	//will print the list backward starting from the last position
	struct listNode * temp;
    temp = tail;
    while(temp!=0)
    {
        printf("%d->", temp->item);
        temp = temp->prev;
    }
    printf("\n");

}

int removeDuplicateItems(int list)
{
    struct listNode *curr, *temp, *dupli;
    int count = 0;
    /*if (list == 0)
    {
        return FAIL_VALUE;
    }*/
    if(list != 0)
    {
       curr = list;
       temp = 0;
       dupli = 0;
       while(curr != 0)
       {
           temp = curr->next;
          int duplicate = 0;
         while(temp != 0)
         {
             if(temp->item == curr->item)
             {
                 dupli = temp;
             }
             temp = temp->next;
             if(dupli != 0)
             {
                 if(dupli->prev != 0)
                 {
                     dupli->prev->next = temp;
                 }
                 if(temp != NULL)
                {
                     temp->prev = dupli->prev;
                }
                dupli->prev = 0;
                dupli->next = 0;
                free(dupli);
                dupli = 0;
             }
         }
         if(duplicate = 1)
            count++;
         curr = curr->next;
       }
    }
    return count;
}

int getListSize()
{
	struct listNode *curr;

	curr = list;
	int count = 0;

	while (curr != 0)
	{
		count++;
		if (curr->next == 0)
			return count;
		curr = curr->next;
	}
}

void swapItem(struct listNode *x, struct listNode *y)
{
    struct listNode *tp, *prev;

    if(x->next) x->next->prev = y;
	if(x->prev) x->prev->next = y;
	if(y->next) y->next->prev = x;
	if(y->prev) y->prev->next = x;

	tp = x->next;
	x->next = y->next;
	y->next = tp;

	tp = x->prev;
	x->prev = y->prev;
	y->prev = tp;
}

int MaxMinSwap()
{
	struct listNode *curr, *min, *max;
	curr = list;
	min = list;
	max = list;

	while (curr != 0)
    {
		if(curr->item > max->item)
			max = curr;

		if(curr->item < min->item)
			min = curr;
		curr = curr->next;
	}
	printf("max: %d, min: %d", max->item, min->item);

	swapItem(max, list);
	swapItem(min, tail);
	list = max;
    tail = min;
	return SUCCESS_VALUE;
}

int main(void)
{
    initializeList();
    while(1)
    {
		printf("\n*******************************************************************\n");
        printf("1. Insert new item. 2. Search item. 3. Print forward. \n");
        printf("4. Insert Before. 5. Delete After. 6. Print backward. \n");
        printf("7. Remove Duplicate Items. 8. Get the list size. 9.Maximum & Minimum. 10. exit.\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("give an item to insert: ");
            int item;
            scanf("%d", &item);
            insertFirst(item);
			printf("inserted successfully\n");
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==3)
        {
            printListForward();
        }
        else if(ch==4)
        {
            printf("give an old item to insert before: ");
            int oldItem;
            scanf("%d", &oldItem);
            printf("give the new item to insert before the old item: ");
            int newItem;
            scanf("%d", &newItem);

            struct listNode *res = insertBefore(oldItem,newItem);
            if(res==SUCCESS_VALUE)
                printf("inserted before successfully\n");
            else
                printf("inserted before unsuccessful\n");
        }
        else if(ch==5)
        {
            printf("give an old item to delete after: ");
            int olditem;
            scanf("%d", &olditem);

            struct listNode *res = deleteAfter(olditem);
            if(res==SUCCESS_VALUE)
                printf("delete after successfully\n");
            else
                printf("delete after unsuccessful\n");

            printf("now the new list is: ");
            printListForward();
        }
        else if(ch==6)
        {
            printListBackward();
        }
        else if(ch==7)
        {
            int count = removeDuplicateItems(list);
            printf("Remove duplicate items successfully\n");
            printf("the number of duplicate items found: ");
            printf("%d\n", count);

            printf("now the new list is: ");
            printListForward();
        }
        else if(ch==8)
        {
            printf("The size of the linked list is: %d", getListSize());
        }
        else if(ch==9)
        {
            MaxMinSwap();

            printf("\n now the new list is: ");
            printListForward();
        }
        else if(ch==10)
        {
            break;
        }
    }

}
