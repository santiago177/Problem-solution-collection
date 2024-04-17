class Solution {

    private int gcd(int a, int b) {
        int remainder;
        while (b != 0) {
            remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    private int gFunction(int x, int n) {
        return (x * x - 1) % n;
    }

    private int pollard(int n) {
        int x = 2;
        int y = 2;
        int d = 1;
        while (d == 1) {
            System.out.println("pollard");
            x = gFunction(x, n);
            y = gFunction(gFunction(y, n), n);
            d = gcd(Math.abs(x - y), n);
        }
        if (d == n)
            return 1;
        return d;
    }

    public int solution(int N) {
        return pollard(N);
    }
}