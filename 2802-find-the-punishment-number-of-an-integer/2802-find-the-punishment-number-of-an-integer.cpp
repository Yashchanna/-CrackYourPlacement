class Solution {
public:
    bool check(int num, int rem,int target){
        if(num==0){
            return rem==target;
        }

        bool isPossible = check(num/10,rem+num%10,target) ||
                        check(num/100,rem +num%100,target) ||
                        check(num/1000,rem +num%1000,target) ||
                        check(num/10000,rem+num%10000, target);
        
        return isPossible;
    }
    int punishmentNumber(int n) {
        int punishNum=0;
        for(int num=1;num<=n;num++){
            int sq=num*num;

            if(check(sq,0,num))
                punishNum+=sq;
        }
        return punishNum;
    }
};