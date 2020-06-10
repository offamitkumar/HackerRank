/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root, int min_value =-10000000 , int max_value = 10000000) {
		if(root==nullptr){
            return true;
        }
        if(root->data <= min_value || root -> data >= max_value){
            return false;
        }
        if(!checkBST(root->right , root->data, max_value)){
            return false;
        }
        if(!checkBST(root->left, min_value , root->data)){
            return false;
        }
        return true;
	}
