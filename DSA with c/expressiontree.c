#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node for an expression tree
struct TreeNode {
    char data; // Operand or operator
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(char value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to build an expression tree from a postfix expression
struct TreeNode* buildExpressionTree(char postfix[]) {
    struct TreeNode* stack[100]; // Assuming expression is not too large
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char symbol = postfix[i];

        // If the symbol is an operand, push a new node onto the stack
        if (!isOperator(symbol)) {
            stack[++top] = createNode(symbol);
        } else {
            // If the symbol is an operator, pop two nodes from the stack
            struct TreeNode* operand2 = stack[top--];
            struct TreeNode* operand1 = stack[top--];

            // Create a new node with the operator and push it onto the stack
            struct TreeNode* operatorNode = createNode(symbol);
            operatorNode->left = operand1;
            operatorNode->right = operand2;
            stack[++top] = operatorNode;
        }
    }

    // The final expression tree is on the top of the stack
    return stack[top];
}

// Function to perform an in-order traversal of the expression tree
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%c ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Example postfix expression: "ab+c*d-"
    char postfixExpression[] = "ab+c*d-";

    // Build the expression tree from the postfix expression
    struct TreeNode* expressionTree = buildExpressionTree(postfixExpression);

    // Display the in-order traversal of the expression tree
    printf("In-order traversal of the expression tree: ");
    inOrderTraversal(expressionTree);
    printf("\n");

    return 0;
}

