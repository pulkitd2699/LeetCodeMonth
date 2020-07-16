// Implement pow(x, n), which calculates x raised to the power n (xn).

class Solution {
public:
    double myPow(double x, int n) {
        return power(x,n);
    }
private:
    double power(double x, int y){
        double temp;
        if(y==0) return 1;
        temp = power(x,y/2);
        if(y%2==0) return temp*temp;
        else{
            if(y>0) return x*temp*temp;
            else return (temp*temp)/x;
        }
    }
};