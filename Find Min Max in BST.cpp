/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */
int minVal(Node* root){
	// Write your code here.
	if(root==NULL) return -1;
	if(root->left) return minVal(root->left);
	else return root->data;	
}

/* int maxVal(Node* root){
	if(root==NULL) return -1;
	if(root->right) return maxVal(root->right);
	else return root->data;
}
*/
