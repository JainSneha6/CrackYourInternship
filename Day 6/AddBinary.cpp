class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        int n = a.length(), m = b.length();
        int i=n-1,j=m-1;
        string res="";
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            carry=sum/2;
            sum%=2;
            res=char(sum+'0')+res;
        }
        return res;
    }
};
