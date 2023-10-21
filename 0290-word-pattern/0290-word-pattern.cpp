class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> m;
        int a=0 , k=0;
        string x;
        s=s+" ";
       
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')  x=x+s[i];
            else{
                a++;
                if(m.find(x)==m.end()){
                    for(auto it:m){
                        if(it.second==pattern[k])  return false;
                    }
                    m[x]=pattern[k++];
                }
                else{
                    if(m[x]!=pattern[k++])  return false;
                }         
                x="";              
            }  
        }   
        return a!=pattern.size()? false : true;
        
    }
};