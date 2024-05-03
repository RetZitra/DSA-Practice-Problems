class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1=version1.size();
        int n2=version2.size();
        int i=0,j=0;
        while(i<n1 || j<n2){
            string temp1="";
            string temp2="";
            //taking each revision string
            while(i<n1 && version1[i]!='.'){
                temp1+=version1[i];
                i++;
            }
            while(j<n2 && version2[j]!='.'){
                temp2+=version2[j];
                j++;
            }
            int a=0;
            int b=0;
            //if revision string is not 0 means that current revision is specified in a version convert it to integer
            //and then compare
            //if current rivision is not present in any version initially take it as 0
            if(temp1!=""){
                a=stoi(temp1);
            }
            if(temp2!=""){
                b=stoi(temp2);
            }
            if(a>b){
                return 1;
            }
            else if(a<b){
                return -1;
            }
            i++;
            j++;
        }
        //after comparing parallaly all revision in two version and finds none of them greater then two version is same
        return 0;
    }
};