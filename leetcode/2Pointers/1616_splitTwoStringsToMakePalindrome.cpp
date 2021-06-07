// didnt get the solution on own
// discuss solution 
// for better understanding : https://www.youtube.com/watch?v=VCF8_5dELaU&ab_channel=NareshGupta
class Solution {
public:
    bool help(string a,string b){
        int n=b.size(),i=0,j=n-1;
        while(i<j && a[i]==b[j]) i++,j--;
        if(i>=j) return true;
        int tmpi=i,tmpj=j;
        while(i<j && b[i]==b[j]) i++,j--;
        if(i>=j) return true;
        i=tmpi,j=tmpj;
        while(i<j && a[i]==a[j]) i++,j--;
        return i>=j;
    }

    bool checkPalindromeFormation(string a, string b)
    {
        return help(a,b)||help(b,a);
    }
};
