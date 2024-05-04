/*A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, deleting
keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/
Descending order. Also find how many maximum comparisons may require for finding any keyword.
Use Height balance tree and find the complexity for finding a keyword*/

#include <iostream>
using namespace std;
struct HBTNode {
int Key;
char Mean[10];
HBTNode *left;
HBTNode *right;
} *Root;
void create_HBT() {
int i;
int nodes;
int done;
struct HBTNode *Newnode, *current;
cout << "\n\n Enter the no of nodes to insert in HBT. : ";
cin >> nodes;
for (i = 0; i < nodes; i++) {
Newnode = new struct HBTNode;
cout << "\n\t Enter Keyword: ";
cin >> Newnode->Key;
cout << "\n\t Enter Meaning: ";
cin >> Newnode->Mean;
Newnode->left = NULL;
Newnode->right = NULL;
if (Root == NULL) {
Root = Newnode;
} else {
done = 0;
current = Root;
while (!done) {
if (Newnode->Key < current->Key) {
if (current->left == NULL) {
current->left = Newnode;
done = 1;
} else
current = current->left;
} else {
if (current->right == NULL) {
current->right = Newnode;
done = 1;
} else
current = current->right;
}
}
}
}
}
void display_HBT(struct HBTNode *root) {
if (root) {
cout << "\n\t" << root->Key << " - " << root->Mean;
display_HBT(root->left);
display_HBT(root->right);
}
}
void Sorted_List(struct HBTNode *root) {
if (root) {
Sorted_List(root->left);
cout << "\n\t" << root->Key << " - " << root->Mean;
Sorted_List(root->right);
}
}
void Find_Keyword(int key) {
int comp = 0;
int level = 0;
int done;
struct HBTNode *current;
done = 0;
current = Root;
while (current && !done)
 {
if (key < current->Key)
 {
current = current->left;
level++;
comp++;
} 
else if (key > current->Key) 
{
current = current->right;
level++;
comp++;
} 
else {
done = 1;
comp++;
cout << "\n\t Key : " << key;
cout << "\n\t Found at Level: " << level;
cout << "\n\t No. of Comparisons: " << comp;
}
}
if (!current) {
cout << "\n\t Key : " << key << " not found.";
}
}
int main() {
cout << "\n -------***A C++ Program to Implement Dictionary using Height-Balanced Tree.***------\n ";
cout << "\n 1. Store Keywords and Meanings in Height-Balanced Tree";
Root = NULL;
create_HBT();
cout << "\n 2. Display Keywords and Meanings in Height-Balanced Tree";
cout << "\n Keyword - Meaning";
display_HBT(Root);
cout << "\n 3. Display a Sorted List of Keywords and Meanings";
cout << "\n Keyword - Meaning";
Sorted_List(Root);
cout << "\n 4. Display Number of Comparisons required to find a keyword";
Find_Keyword(10);
return 0;
}
