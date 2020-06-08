/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/
    bool checkBST(Node* root ,const int &min_value=-1000000, const int &max_value=1000000) {
        if(root == NULL){
            return true;
        }
        if( root -> data >= max_value || root -> data <= min_value ){
            return false;
        }
        if(!checkBST(root ->right , root ->data , max_value)){
            return false;
        }
        if(!checkBST(root ->left , min_value , root -> data)){
            return false;
        }
        return true;
    }
