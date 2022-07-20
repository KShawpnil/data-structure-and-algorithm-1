#include <stdio.h>
#define DELETED -99999
#define FAILED -99999
#define SUCCESS 99999
#define LARGE_POSITIVE 99999

int queue_size=-1;

int *queue;
int front = 0;
int rear = -1;
int itemCount = 0;

void createQueue(int size){
    queue_size=size;
    queue=(int*)malloc(size*sizeof(int));
}

int getFront() {
    if(!isQueueEmpty())
        return queue[front];
    else {
      printf("Could not retrieve data, Queue is empty.\n");
      return FAILED;
   }
}

int getRear() {
    if(!isQueueEmpty())
        return queue[rear];
    else {
      printf("Could not retrieve data, Queue is empty.\n");
      return FAILED;
   }
}


int isQueueEmpty() {
   return itemCount == 0;
}

int isQueueFull() {
   return itemCount == queue_size;
}

int enqueue(int data) {

   if(!isQueueFull()) {

      if(rear == queue_size-1) {
         rear = -1;
      }

      queue[++rear] = data;
      itemCount++;
      printf("Inserted %d in the queue.\n", data);
   }
    else {
      printf("Could not insert data, Queue is full.\n");
      return FAILED;
   }
}

int dequeue() {
    if(!isQueueEmpty()){
         int data = queue[front++];

        if(front == queue_size) {
          front = 0;
        }

        itemCount--;
        return data;
    }
    else {
      printf("Could not dequeue data, Queue is empty.\n");
      return FAILED;
   }


}

int getQueueItemCout(){
    return itemCount;
}

int getQueueCapacity(){
    return queue_size;
}

void printQueue(){
    if(isQueueEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        int i;
        printf("Queue elements are:  (rear)");
        for(i=rear;i>=front;i--){
            printf("%d ",queue[i]);
        }
        printf(" (front)");
    }
}

int findMin(){
    int min= LARGE_POSITIVE;

    while(!isQueueEmpty()){
        int curr=dequeue();
        if(curr<min){
            min=curr;
        }
    }

    return min;
}

int main() {
   // push items on to the Queue
   createQueue(5);

   while(1)
    {
        printf("\n\n*******************************************************************\n");
        printf("1. Enqueue item. 2. Dequeue item. 3. Get Front item. 4. Get Rear Item. 5.Is Empty?.  \n");
        printf("6. Is Full?. 7. Get Count. 8. get Capacity 9.Print  10.exit. 11.Find min\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("give an item to enqueue: ");
            int item;
            scanf("%d", &item);
            enqueue(item);
        }
        else if(choice==2)
        {
            int res=dequeue();
            if(res!=FAILED)
                printf("dequeued %d\n", res);
        }
         else if(choice==3)
        {
            int res=getFront();
            if(res!=FAILED)
                printf("front is %d\n", res);
        }
          else if(choice==4)
        {
            int res=getRear();
            if(res!=FAILED)
                printf("rear is %d\n", res);
        }
          else if(choice==5)
        {
            int res=isQueueEmpty();
            if(res)
                printf(" Yes\n");
            else
                printf("No\n");
        }
        else if(choice==6)
        {
            int res=isQueueFull();
            if(res)
                printf(" Yes\n");
            else
                printf("No\n");
        }
         else if(choice==7)
        {
            printf("Number of elements in Queue: %d\n", getQueueItemCout());
        }
         else if(choice==8)
        {
            printf("Queue Capacity: %d\n", getQueueCapacity());
        }
        else if(choice==9)
        {
            printQueue();
        }
        else if(choice==10)
        {
            break;
        }

         else if(choice==11)
        {
            printf(" \n The min element is : %d ", findMin());
        }

    }

   return 0;
}
