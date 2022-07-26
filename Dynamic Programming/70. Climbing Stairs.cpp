class Solution
{
public:
    // Trick: the number of ways to get to a stair N is the Nth Fibonacci number.
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int one = 1; // Number of ways to get to step 0
        int two = 1; // Number of ways to get to step 1

        // Two represents that number of ways to get to the step i - 1
        // One represents that number of ways to get to the step i - 2

        for (int i = 2; i <= n; ++i)
        {
            two = one + two; // Number of ways to get to the ith step = number of ways to get to step i - 1 +
                             // number of ways to get to stop i - 2, as we may take either one or two steps
                             // from the starting point
            one = two - one; // As we move up, one moves up a stair and becomes two and two becomes one + two on moving up.
        }

        return two;
    }
};