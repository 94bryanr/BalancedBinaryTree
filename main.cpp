#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <iostream>

using std::max;
using std::vector;
using std::cout;
using std::endl;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int getHeight(Node* node){
    if(node == nullptr)
        return 0;
    else
        return max(getHeight(node->left), getHeight(node->right)) + 1;
}

bool isBalanced(Node* node){
    if(node == nullptr)
        return true;
    if(abs(getHeight(node->left) - getHeight(node->right)) > 1)
        return false;
    else
        return(isBalanced(node->left) && isBalanced(node->right));
}

int main(int argc, char* argv[]){
    vector<Node*> nodes;
    for(int i = 0; i < 10; i++){
        Node* newNode = new Node();
        newNode->data = i;
        nodes.push_back(newNode);
    }
    
    // Build a binary tree
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    
    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];
    
    nodes[2]->left = nodes[5];
    nodes[2]->right = nodes[6];
    
    cout << (isBalanced(nodes[0]) ? "True" : "False") << endl;
    
    for(int i = 0; i < nodes.size(); i++){
        delete nodes[i];
    }
}