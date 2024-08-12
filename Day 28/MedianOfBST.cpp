int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void findKth(Node* root, int &k, int &result) {
    if (root == NULL) {
        return;
    }

    findKth(root->left, k, result);

    k--;
    if (k == 0) {
        result = root->data;
        return;
    }

    findKth(root->right, k, result);
}

float findMedian(struct Node *root) {
    if (root == NULL) {
        return 0.0; 
    }

    int n = countNodes(root);

    if (n % 2 != 0) {
        int k = n / 2 + 1;
        int result;
        findKth(root, k, result);
        return (float)result;
    }
    
    else {
        int k1 = n / 2;
        int k2 = n / 2 + 1;
        int result1, result2;
        findKth(root, k1, result1);
        findKth(root, k2, result2);
        return (result1 + result2) / 2.0;
    }
}

