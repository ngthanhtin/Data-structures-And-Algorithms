/*EXAMPLE AND TEMPLATE IMPLEMENTATION*/
#include <iostream>
using namespace std;
#define MAX 26 // 26 alphabets
// node of a trie
struct node
{
    struct node *child[MAX];
    int countLeaf;
};

//new a node
struct node* newNode()
{
    node* Node = new node();
    Node->countLeaf = 0;

    for(int i = 0; i < MAX; i++)
    {
        Node->child[i] = NULL;
    }
    return Node;
}
//add word
void addWord(node* root, string s)
{
    int ch;
    node* temp = root;
    for(int i = 0; i<s.size();++i)
    {
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL)
        {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countLeaf++;
}
//find word
void findWord(node* root, string s)
{
    int ch;
    node* temp = root;
    for(int i = 0; i < s.size(); ++i)
    {
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL)
        {
            return false;
        }
        temp = temp->child[ch];
    }
    return temp->countLeaf > 0;
}
//
bool isEmpty(node* pNode)
{
    for(int i = 0; i< MAX;++i)
    {
        if(pNode->child[i] != NULL)
            return false;
    }
    return true;
}
//check leaf node
bool leafNode(node* pNode)
{
    return (pNode->countLeaf != 0);
}
//delete a word
bool removeWord(node* root, string s, int level, int len)
{
    if(!root)
        return false;
    int ch = s[level] - 'a';
    if(level == len)
    {
        if(root->countLeaf > 0)
        {
            root->countLeaf--;
            return true;
        }
        return false;
    }
    int flag = removeWord(root->child[ch], s, level+1,len);
    if(flag && !leafNode(root->child[ch]) && isEmpty(root->child[ch]))
    {
        delete root->child[ch];
        root->child[ch] = NULL;
    }
    return flag;
}