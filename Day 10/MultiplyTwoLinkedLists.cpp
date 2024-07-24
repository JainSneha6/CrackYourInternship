class solution {
    long long mod=1e9+7;
  private:
    long long convert(Node* temp){
        long long ans=0;
        while(temp){
            ans=(ans*10)%mod+temp->data;
            temp=temp->next;
        }
        return ans;
    }
    
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long ans1 = convert(first);
        long long ans2 = convert(second);
        return (ans1*ans2)%mod;
    }
};
