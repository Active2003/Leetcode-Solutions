class Solution {
public:
    double binaryExp(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            n = -1 * n;
            x = 1.0 / x;
        }
        double result = 1;
        while (n) {
            if (n % 2 == 1) {
                result = result * x;
                n -= 1;
            }
            x = x * x;
            n = n / 2;
        }
        return result;
    }

    double myPow(double x, int n) {
        return binaryExp(x, (long long) n);
    }
};