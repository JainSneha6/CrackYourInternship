vector<vector<string> > Anagrams(vector<string>& string_list) {
        map <string,vector<string>> m;
        vector<vector<string>> res;
        for(int i=0;i<string_list.size();i++){
            string str=string_list[i];
            sort(str.begin(),str.end());
            m[str].push_back(string_list[i]);
        }
        for(auto it:m){
            res.push_back(it.second);
        }
        return res;
    }
