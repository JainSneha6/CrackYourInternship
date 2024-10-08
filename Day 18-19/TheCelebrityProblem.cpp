public:
  
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int candidate = 0;
        
        for (int i = 1; i < n; ++i) {
            if (mat[candidate][i] == 1) {
                candidate = i;
            }
        }
    
        for (int i = 0; i < n; ++i) {
            if (i != candidate) {
                if (mat[i][candidate] == 0 || mat[candidate][i] == 1) {
                    return -1;
                }
            }
        }
    
        return candidate;
    }
