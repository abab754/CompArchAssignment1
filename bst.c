#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;

void printTree(node * root){
    if(root != NULL){
        printf("(");
        printTree(root->left);
        printf("%d", root->val);
        printTree(root->right);
        printf(")");
    }
    // printf("\n");
}

int search(node *root, int value)
{
    node *temp = root;
    if (root == NULL)
    {
        // printf("absent\n");
        return 0;
    }

    while (temp != NULL)
    {
        if (value == temp->val)
        {
            // printf("present\n");
            return 1;
            // return;
        }
        else if (value > temp->val)

        {
            if (temp->right == NULL)
            {
                // printf("absent\n");
                return 0;
            }
            temp = temp->right;
        }
        else if (value < temp->val)
        {
            if (temp->left == NULL)
            {
                // printf("present\n");
                return 0;
            }
            temp = temp->left;
        }
        else
        {
            break;
        }
    }
    // printf("absent\n");
    return 0;
    // return;
}

void insert(node **root, int value)
{
    node *newNode = malloc(sizeof(node));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    node *temp = *root, *prev;

    // printf("\ncreated the node with value of %d\n", newNode->val);
    if(search(temp, value) == 1){
        printf("not inserted");
        free(newNode);
        return;
    }
    // printf("%d is absent and will be inserted shortly\n", value);
    

    if (*root == NULL)
    {
        *root = newNode;
        printf("inserted");
        // printf("\nroots value is %d\n", newNode->val);

        return;
    }

    if (*root != NULL && temp->left == NULL && temp->right == NULL)
    {
        if (value < temp->val)
        {
            temp->left = newNode;
            printf("inserted");

            // printf("root: %d\n", (*root)->val);
            // printf("roots left value: %d\n", (*root)->left->val);
            // free(newNode);
            return;
        }
        if (value > temp->val)
        {
            temp->right = newNode;
            printf("inserted");

            // printf("temps value: %d\n", temp->val);
            // printf("temps right value: %d\n", temp->right->val);
            // free(newNode);
            return;
        }
    }

    if (temp->left == NULL && temp->right != NULL)
    {
        if (temp->val > value)
        {
            temp->left = newNode;
            printf("inserted");

            // printf("temps value: %d\n", temp->val);
            // printf("temps left value: %d\n", temp->left->val);
            // free(newNode);
            return;
        }
    }

    if (temp->left != NULL && temp->right == NULL)
    {
        if (temp->val < value)
        {
            temp->right = newNode;
            printf("inserted");

            // printf("temps value: %d\n", temp->val);
            // printf("temps right value: %d\n", temp->right->val);
            // free(newNode);
            return;
        }
    }

    while (temp != NULL)
    {
        prev = temp;

        if (value > temp->val)
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                printf("inserted");

                // printf("\ninserting, temps val: %d\n", temp->val);
                // printf("\ntemp's right value: %d\n", temp->right->val);
                return;
            }
            temp = temp->right;
        }
        else if (value < temp->val)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                printf("inserted");

                // printf("temps val: %d\n", temp->val);
                // printf("temp's left val: %d\n", temp->left->val);
                return;
            }
            temp = temp->left;
        }
        else
        {
            // free(newNode);
            // free(prev);
            // free(temp);
            return;
        }
    }


    if (prev->val < value)
    {

        prev->right = newNode;
    }
    else
    {
        prev->left = newNode;
    }

}

node* getMax(node * root){
    if(root == NULL){
        return root;
    }
    if(root->right != NULL){
        getMax(root->right);
    }
    return root;

}

// node * deleteNode(node *root, int value){
//     if(root == NULL){
//         return NULL;
//     }

//     if(root->val > value){
//         deleteNode(root->left, value);
//     }
//     if(root->val < value){
//         deleteNode(root->right, value);
//     }
// }

void delete (node **root, int value)
{
    node *temp = *root, *prev;
    if (temp == NULL)
    {
        return;
    }
    if (temp->val == value)
    {
        if(temp->left != NULL && temp->right != NULL){
            node* leftPtr, *rightPtr;
            leftPtr = (*root)->left;
            rightPtr = (*root)->right;

            *root = getMax(temp->left);
            (*root)->right = rightPtr;
            (*root)->left = leftPtr;
            printf("deleted");

            return;
        }
        if (temp->left == NULL && temp->right == NULL)
        {
            // printf("We have deleted %d", value);
            *root = NULL;
            printf("We have deleted %d\n", value);
            free(temp);
            return;
        }
        if (temp->right == NULL && temp->left != NULL)
        {
            if (temp->left->right == NULL)
            {
                *root = temp->left;
                printf("new root's val: %d\ndeleted val: %d\n", (*root)->val, value);
                free(temp);
                return;
            }
            // if(temp->left->right != NULL){
            //     temp = temp->left->right;
            // }
        }
        if (temp->left == NULL && temp->right != NULL)
        {
            if (temp->right->left == NULL)
            {
                *root = temp->right;
                printf("new root's val: %d\ndeleted val: %d\n", (*root)->val, value);
                free(temp);
                return;
            }
            // if(temp->right->left!= NULL){
            //     temp = temp->right->left;
            // }
        }
    }
    node *p;
    while (temp != NULL)
    {
        p = prev;
        prev = temp;

        if (value == temp->val)
        {
            if (temp->right == NULL && temp->left == NULL)
            {
                temp = NULL;
                // printf("We deleted a value with no children.");
                // printf("root's val: %d\nValue %d is deleted\n", (*root)->val, value);
                // printf("root's left val: %d\n", (*root)->left->val);

                return;
            }
            if (temp->left != NULL && temp->right == NULL)
            {
                p->left = temp->left;
                temp = NULL;
                // printf("We deleted node with no right. root's val: %d\nValue %d is deleted\n", (*root)->val, value);
                // printf("root's left val: %d\nRoot's right val: %d\n", (*root)->left->val, (*root)->right->val);
                free(prev);
                return;
            }
            if (temp->right != NULL && temp->left == NULL)
            {
                if ((temp = p->left))
                {
                    // printf("p's val: %d", p->val);

                    p->left = temp->right;
                    temp = NULL;
                    // printf("We deleted node with no left. root's val: %d\nValue %d is deleted\n", (*root)->val, value);
                    // printf("root's left val: %d\nRoot's right val: %d\n",(*root)->left->val, (*root)->right->val);
                    free(prev);
                    return;
                }
                if ((temp = p->right))
                {
                    // printf("p's val: %d", p->val);
                    p->right = temp->right;
                    temp = NULL;

                    // printf("We deleted node with no left. root's val: %d\nValue %d is deleted\n", (*root)->val, value);
                    // printf("root's left val: %d\nRoot's right val: %d\n",(*root)->left->val, (*root)->right->val);
                    free(prev);
                    return;
                }
                // p->right = temp->right;
                // temp = NULL;
                // printf("We deleted node with no left. root's val: %d\nValue %d is deleted\n",(*root)->val, value);
                // printf("root's left val: %d\nRoot's right val: %d\n",(*root)->left->val, (*root)->right->val);
                // free(prev);
                // return;
            }
        }
        else if (value > temp->val)
        {
            if (temp->right == NULL)
            {
                printf("absent\n");
                return;
            }
            temp = temp->right;
        }
        else if (value < temp->val)
        {
            if (temp->left == NULL)
            {
                printf("present\n");
                return;
            }
            temp = temp->left;
        }
        else
        {
            break;
        }
    }
    // printf("absent\n");
    // return 0;
    return;
}

void free_tree(node *root)
{
    // post-order like FatalError hinted at
    if (root != NULL)
    {
        free_tree(root->right);
        // free(root->val); //if data was heap allocated, need to free it
        free_tree(root->left);
        free(root);
    }
}

int main()
{
    node *root = NULL;
    int i;
    char c;

    fflush(stdout);
    while (1)
    {
        if (scanf("%c %i", &c, &i) == EOF)
        {
            break;
        }

        if(tolower(c) == 'i')
        {
            insert(&root, i);
        }
        else if(tolower(c) == 'p')
        {
            printTree(root);
            printf("\n");
            continue;
        }
        else if(tolower(c) == 's')
        {
            if(search(root, i)== 0){
                printf("absent");
            }
            else{
                printf("present");
            }
        }
        // else if(tolower(c) == 'd'){
        //     delete(&root, i);
        // }
        else{
            continue;
        }
        // printTree(root);
        printf("\n");
    }
    printf("\n");

    free_tree(root);
    // // free(root);
    return EXIT_SUCCESS;
}

