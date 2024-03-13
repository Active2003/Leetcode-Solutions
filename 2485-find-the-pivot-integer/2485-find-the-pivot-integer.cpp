class Solution {
public:
    int pivotInteger(int n) {
        int num = (n*(n+1))/2;
        int sq = sqrt(num);
        if(sq*sq==num){
            return sq;
        }
        return -1;
    }
};