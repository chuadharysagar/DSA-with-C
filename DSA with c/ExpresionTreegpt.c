#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);}
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        if (isalnum(symbol)) {
            struct Node* operandNode = createNode(symbol);
            stack[++top] = operandNode;
        } else if (isOperator(symbol)) {
            struct Node* rightOperand = stack[top--];
            struct Node* leftOperand = stack[top--];

            struct Node* operatorNode = createNode(symbol);
            operatorNode->left = leftOperand;
            operatorNode->right = rightOperand;
            stack[++top] = operatorNode;
        }}
    return stack[top];}
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data);
        inOrderTraversal(root->right);
    }}
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c ", root->data);
    }}
int main() {
    char postfixExpression[] = "ab+c*";
    struct Node* root = buildExpressionTree(postfixExpression);

    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");
    return 0;}

