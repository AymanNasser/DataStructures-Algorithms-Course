class Solution {
public:
    bool isPerfectSquare(int num) {
        
        if(num < 2)
            return true;
        
        long i = 2;
        long long product = 0;
        while(product <= num){
            
            product = i*i;
            if(product == num)
                return true;
            i++;
        }
        
        return false;
        
    }
};
