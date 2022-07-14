#include<stdio.h>
#include<stdlib.h>
#define FAIL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};

struct listNode * list;

void initializeList()
{
    list = 0;  //initially set to NULL
}

void insertItem(int item) //insert at the beginning of the linked list
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = list ; //point to previous first node
	list = newNode ; //set list to point to newnode as this is now the first node
}

int deleteItem(int item)
{
	struct listNode *curr, *prev ;
	curr = list ; //start at the beginning
	while (curr != 0)
	{
		if (curr->item == item) break ;
		prev = curr;
		curr = curr->next ; //move to next node
	}
	if (curr == 0) return FAIL_VALUE ; //item not found to delete
	if (curr == list) //delete the first node
	{
		list = list->next ;
		free(curr) ;
	}
	else
	{
		prev->next = curr->next ;
		free(curr);
	}
	return SUCCESS_VALUE;

}

struct listNode * searchItem(int item)
{
	struct listNode * curr ;
	curr = list ; //start at the beginning
	while (curr != 0)
	{
		if (curr->item == item) return curr ;
		curr = curr->next ; //move to next node
	}
	return 0 ; // not found; 0 means invalid pointer in C, also called NULL value in C
}

void printList()
{
    struct listNode * curr;
    curr = list;
    while(curr!=0)
    {
        printf("%d->", curr->item);
        curr = curr->next;
    }
    printf("\n");
}

int getListSize()
{
	//write your codes here
	int count = 0;
	struct listNode *tmp;
	tmp = list;

	while(tmp != NULL){
        count++;
        tmp = tmp->next;
	}
	return count;
}

int insertLast(int item, int list)
{
    //write your codes here
    struct listNode *curr, *newNode;

    /*if(list == NULL)
    {
        insertItem(item);
        return 0;
    }*/

    curr = list;
    while(curr->next != 0){
        curr = curr->next;
    }
    newNode->item = item;
    newNode->next = NULL;
    curr->next = newNode;

    return SUCCESS_VALUE;
}

int insertBefore(int oldItem, int newItem)
{
	//write your codes here
	struct listNode *curr, *newNode;
    curr = list;

    while(curr != 0){
        if(curr->item == oldItem){
            break;
        }
        curr = curr->next;
    }
    //if (curr != 0) return FAIL_VALUE ;

    newNode->item = newItem;
    newNode->next = curr->next;
    curr->next = newNode;

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
    while(curr != 0){
        if(curr->item == olditem)
        {
            curr->next = curr->next->next;
            return SUCCESS_VALUE;
        }
        curr = curr->next;
    }
  }
}

int deleteLast()
{
    //write your codes here
    struct listNode *curr, *prev;

    if(list == 0){
        return 0;
    }
    else{
    curr = list;
    prev = list;
    while(curr->next != 0){
        prev = curr;
        curr = curr->next;
    }
    if(curr == list)
    {
        list = 0;
    }
    else
    {
        prev->next = 0;
    }
    free(curr);
    }
    return SUCCESS_VALUE;
}



int main(void)
{
    initializeList();
    while(1)
    {
        printf("\n*******************************************************************\n");
        printf("1. Insert new item. 2. Delete item. 3. Search item. 4.Insert Last.  \n");
        printf("5. Insert Before. 6. Delete After. 7. Delete Last. 8.Get List Size 9. Print. 10. exit.\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("give an item to insert: ");
            int item;
            scanf("%d", &item);
            insertItem(item);
            printf("inserted successfully\n");
        }
        else if(choice==2)
        {
            printf("give an item to delete: ");
            int item;
            scanf("%d", &item);
            int res=deleteItem(item);
            if(res==SUCCESS_VALUE)
                printf("deleted successfully\n");
            else
                printf("delete unsuccessful\n");
        }
        else if(choice==3)
        {
            int item;
            printf("give an item to search: ");
            scanf("%d", &item);
            struct listNode * res = searchItem(item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(choice==4)
        {
            printf("give an item to insert last: ");
            int item;
            scanf("%d", &item);

            struct listNode *res = insertLast(item,list);
            if(res==SUCCESS_VALUE)
                printf("inserted last successfully\n");
            else
                printf("inserted last unsuccessful\n");
            //insertLast(item);
            //printf("inserted last successful\n");
        }
        else if(choice==5)
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
        else if(choice==6)
        {
            printf("give an item to delete after: ");
            int olditem;
            scanf("%d", &olditem);

            int res=deleteAfter(olditem);
            if(res==SUCCESS_VALUE)
                printf("delete after successfully\n");
            else
                printf("delete after unsuccessful\n");

            printf("now the items are: \n");
            printList();
        }
         else if(choice==7)
        {
            deleteLast();
            printf("delete last successfully\n");
            printf("now the items are: \n");
            printList();
        }
        else if(choice==8)
        {
            printf("The size of the Linked List: %d\n",getListSize());
            /*struct listNode * res = getListSize(cnt);
            if(res == cnt)
            printf("The size of the Linked List: %d\n");*/
        }
        else if(choice==9)
        {
            printList();
        }
        else if(choice==10)
        {
            break;
        }
    }

}
