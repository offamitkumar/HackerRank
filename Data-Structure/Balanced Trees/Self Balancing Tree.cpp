/* Node is defined as :
   typedef struct node
   {
   int val;
   struct node* left;
   struct node* right;
   int ht;
   } node; */

int height(node*root) {
    if (root==nullptr) {
        return -1;
    } else {
        return max(height(root->left) , height(root->right))+1;
    }
}
node* rotateRight(node* root) {
    node* templ = root->left; 
    node* templr = root->left->right;
    templ->right = root; 
    root->left = templr; 
    root->ht = height(root); 
    templ->ht = height(templ);
    return templ; 
}
node* rotateLeft(node*root) {
    node* templ = root->right; 
    node* templr = root->right->left;
    templ->left = root; 
    root->right = templr; 
    root->ht = height(root); 
    templ->ht = height(templ);
    return templ; 
}
node* insert(node * root,int val) {
    if (root==nullptr) {
        root = new node(); 
        root->left = nullptr; 
        root->right = nullptr;
        root->val = val; 
        root->ht = height(root); 
        return root; 
    }
    if (root->val < val) {
        root->right = insert(root->right , val);
    } else if (root->val > val) {
        root->left = insert(root->left , val);
    }
    int BF = height(root->left) - height (root->right); 
    if (BF>1) {
        // check diagram from question  
        int child_bf = height(root->left->left) - height(root->left->right); 
        if ( child_bf > 0) {
            // rr
            root = rotateRight(root); 
        } else {
            // lr
            root->left = rotateLeft(root->left);  // L
            root = rotateRight(root); //  R
        }
    } else if (BF < -1) {
        int child_bf = height(root->right->left) - height(root->right->right); 
        if ( child_bf > 0) {
            // rl
            root->right = rotateRight(root->right); 
            root = rotateLeft(root); 
        } else {
            // ll
            root = rotateLeft(root);
        }
    } else {
        root -> ht = height(root);
    }
    return root;
}
