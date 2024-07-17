#include <bits/stdc++.h> 
vector<pair<char,int>> duplicate_char(string s, int n){
    vector <int> freq(256,0);
    for(int i=0;i<n;i++){
        freq[s[i]]+=1;
    }
    vector <pair<char,int>> v;
    for(int i=0;i<256;i++){
        if(freq[i]>1){
            char ch=(char)i;
            v.push_back({ch,freq[i]});
        }
    }
    return v;
}
