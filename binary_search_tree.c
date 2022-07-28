//ID: 011201125
#include<stdio.h>
#include<stdlib.h>
#define FAIL_VALUE -999999
#define SUCCESS_VALUE 999999

struct treeNode
{
    int item;
    struct treeNode *left; //points to left child
    struct treeNode *right; //points to right child
    //int count;
};

struct treeNode *root;

void initializeTree()
{
    root = 0;
}

struct treeNode *makeTreeNode(int item)
{
    struct treeNode *node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode *searchItem(struct treeNode *node, int item)
{
    if(node==0) return 0;

    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};

int insertItem(struct treeNode *node, int item)
{
    if(node == 0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return SUCCESS_VALUE;
    }

    if(node->item == item){
        //printf("%d",node->count++);
		printf("Already in the tree\n");
		return FAIL_VALUE; //already an item exists, so return NULL
	}

    if(item < node->item && node->left == 0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return SUCCESS_VALUE;
    }

    if(item > node->item && node->right == 0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return SUCCESS_VALUE;
    }

    if(item < node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}

int calcNodeHeight(struct treeNode *node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}

int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

//Task-1
int getSize(struct treeNode *node)
{
    //write your code here
    if(node == 0)
    {
         return 0;
    }
    else
    {
        int l = node->left;
        int r = node->right;
        return (getSize(l) + getSize(r) + 1);
    }
}

//Task-2
int NodeDepth(struct treeNode *node, int item) //to calcDepth we need to find each depth of a node
{
    //write your codes here
    if(node == 0)
    {
        return 0;  //empty tree
    }
    if(node->item == item)  //item found but equal
    {
        return 0;
    }
    if(item < node->item) //found in left subtree
    {
        return 1 + NodeDepth(node->left, item);
    }
    else if(item > node->item)  //found in right subtree
    {
        return 1 + NodeDepth(node->right, item);
    }
}

int calcDepth(int item) //return depth of an item in the tree
{
    return NodeDepth(root, item);  //recursively call NodeDepth() to calculate all the edges
}

//Task-3
int getMaxItem() //returns the maximum item in the tree
{
    //write your codes here
    if(root == 0)
        return FAIL_VALUE;

    struct treeNode *temp = root;
    while(temp->right != 0)
    {
        temp = temp->right;
    }
    return temp->item;
}

//Task-4
int deleteItem(struct treeNode *node, int item)
{
    //write your code here, return SUCCESS, FAIL
    int temp;
    struct treeNode *successor;

    if(node == 0)
        return 0; //FAIL_VALUE;              //Not found

    if(node->item == item)            //Found & node has one child
    {
        if(node->left == 0)          //leaf node-> for right child
        {
            temp = node->right;
            free(node);
            return temp;
        }
        else if(node->right == 0)    //leaf node-> for left child
        {
            free(node);
            return 0; //FAIL_VALUE;
        }
        else                         //if node has two child
        {
            successor = node->right;
            while(successor->left != 0)   //successor found
            {
                successor = successor->left;
            }
            node->item = successor->item;      //replace with successor
            node->right = deleteItem(node->right, successor->item);  //delete old item successor
            return node; //SUCCESS_VALUE;
        }
    }
    else if(node->item > item)
    {
        node->left = deleteItem(node->left, item);
        return node; //SUCCESS_VALUE;
    }
    else
    {
        node->right = deleteItem(node->right, item);
        return node; //SUCCESS_VALUE;
    }
}

//Task-5
void printPostOrder(struct treeNode *node)
{
    //write your codes here
    if(node == 0) return;

    printPostOrder(node->left);   //print left sub-tree

    printPostOrder(node->right);  //print right sub-tree

    printf("%d ", node->item);    //print the item
}

//Task-5(Incomplete)
void printLevelOrder(struct treeNode *node)
{
    //write your codes here
    if(node == 0) return;

    printInOrder(node->left);

    printf("%d ",node->item);

    printInOrder(node->right);
}

//Task-6
int deleteKSmallest(int k)
{
    //write your codes here
    if(root == 0)
        return FAIL_VALUE;

    struct treeNode *temp = root;
    while(temp->left != 0)
    {
        temp = temp->left;
    }
    deleteItem(root, temp->item);
}

//Task-7
int findSubTreeSum(struct treeNode *node)
{
    int sum = 0;
    int Lsum = 0;
    int Rsum = 0;

    if(node == 0)
    {
        return 0;
    }
    else
    {
        if(node->left != 0)
            Lsum = findSubTreeSum(node->left);
        if(node->right != 0)
            Rsum = findSubTreeSum(node->right);

        sum = node->item + Lsum + Rsum;
        return sum;
    }
}

//Task-8
int changeItem(struct treeNode *node, int oldItem, int newItem)
{
    //write your codes here
    node = deleteItem(node, oldItem);   //recursively call deleteItem() function to delete old item

    node = insertItem(node, newItem);   //recursively call insertItem() function to insert/replace the new item

    return node;
}

//Task-9(Incomplete)
int duplicateCount(struct treeNode *node,int item)
{
    struct treeNode *count;
    count = 0;
    if(insertItem(root, node->item==item)){
        count++;
     return count;
	}
}

void printInOrder(struct treeNode *node)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left);

    //print item
    printf("%d ",node->item);

    //print right sub-tree
    printInOrder(node->right);
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n*********************************************************************************************\n");
        printf("1. Insert item. 2. Delete item. 3. Search item. 4. Get height. 5. Print in order.\n");
        printf("6. Print level order. 7. Print post order.  8. Get depth. 9. Get max. 10. Get Size. \n");
        printf("11. delete K'th smallest . 12. Get subtree sum. 13. Change item. 14. Count Duplicate 15. Exit.");
        printf("\n*********************************************************************************************\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Give an item to insert: ");
            int item;
            scanf("%d", &item);

            int res=insertItem(root, item);
            if(res==SUCCESS_VALUE)
                printf("Insertion successful\n");
            else
                printf("Insertion failed\n");
        }
        else if(ch==2)
        {
            printf("Give an item to delete: ");
            int item;
            scanf("%d", &item);
            int res;
            //int res=deleteItem(root, item);
            if(res=deleteItem(root, item))
            {
                printf("Delete successful\n");
                printInOrder(root);
            }
            else
                printf("Delete unsuccessful\n");
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);

            int height = calcHeight(item);
            if(height==-1)
                printf("%d Not found\n", item);
            else
                printf("Height of %d = %d\n", item, height);
        }
        else if(ch==5)
        {
            printInOrder(root);

        }
        else if(ch==6)
        {
            printLevelOrder(root);

        }
        else if(ch==7)
        {
            printPostOrder(root);

        }
        else if(ch==8)
        {
            int item;
            scanf("%d", &item);

            int depth = calcDepth(item);
            printf("Depth is %d\n", depth);
        }
        else if(ch==9)
        {
           printf("%d ",getMaxItem());
        }
        else if(ch==10)
        {
           printf("%d", getSize(root));
        }
        else if(ch==11)
        {
            int res;
            if(res=deleteKSmallest(root))
            {
                printf("Delete Ksmallest successful\n");
                printInOrder(root);
            }
            else
                printf("Delete Ksmallest unsuccessful\n");
        }
        else if(ch==12)
        {
            printf("Give a node of a subtree: ");
            int item;
            scanf("%d", &item);

            struct treeNode *node = searchItem(root, item);
            printf("Sum of subtree %d\n",findSubTreeSum(node));
        }
        else if(ch==13)
        {
            printf("Give an old item to delete: ");
            int olditem;
            scanf("%d", &olditem);
            printf("Give new item to insert: ");
            int newitem;
            scanf("%d", &newitem);

            int res;
            if(res=changeItem(root, olditem, newitem))
            {
                printf("Changed successful\n");
                printInOrder(root);
            }
            else
                printf("Changed unsuccessful\n");
        }
        else if(ch==14)
        {
            int item;
            printf("Number of Duplicate nodes %d \n", duplicateCount(root,item));
        }
        else if(ch==15)
        {
            break;
        }
    }
}
