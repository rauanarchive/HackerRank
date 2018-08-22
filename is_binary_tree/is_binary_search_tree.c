/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/

	bool checkBST(Node* root) {

        return check_balance(root);

	}

    bool check_balance(Node* root)
{
    static Node *prev = NULL;// kind of global variable

    // traverse the tree in inorder fashion and keep track of prev node
    if (root!= NULL)
    {
        if (!check_balance(root->left))
          return 0;
        //here after check_balance(root->left) prev keeps root-left
        // Allows only distinct valued nodes
        if (prev != NULL && root->data <= prev->data)
          return 0;

        prev = root;

        return check_balance(root->right);
    }

    return 1;
}


// tree traversal (process of visiting trees)
// binary search tree: each value in left subtree is less than each value
// in the right subtree
