class Solution {
  private:
    void dfs(Node* root, int k, map<int,int>& m, int& count, int& sum){
        if(root==NULL){
            return;
        }
        sum+=root->data;
        if(m.find(sum-k)!=m.end()){
            count+=m[sum-k];
        }
        m[sum]++;
        dfs(root->left,k,m,count,sum);
        dfs(root->right,k,m,count,sum);
        m[sum]--;
        sum-=root->data;
        
    }
  public:
    int sumK(Node *root, int k) {
        int count = 0;
        map <int,int> m;
        m[0]=1;
        int sum=0;
        dfs(root,k,m,count,sum);
        return count;
    }
};
