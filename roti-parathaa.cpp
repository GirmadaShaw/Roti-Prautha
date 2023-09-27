/*
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting.
The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function.
The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the
first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete
prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more
in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as
he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done.
Please write a program to help him out.

Input:
The first line tells the number of test cases. Each test case consist of 2 lines.
In the first line of the test case we have P the number of prata ordered. In the next line the first integer
denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Output:
Print an integer which tells the number of minutes needed to get the order done.
12
36
1

*/

#include <iostream>

int isPossible(int ranks[], int cooks, int P, int minTime)
{
    int parathaaCount = 0, timeTillNow = 0, j;

    for (int i = 0; i < cooks; i++)
    {
        j = 1;
        timeTillNow += (j * ranks[i]);
        while (timeTillNow <= minTime)
        {
            parathaaCount++;
            j++;
            timeTillNow += (j * ranks[i]);
        }
        timeTillNow = 0;
    }

    return (parathaaCount >= P);
}

// Time-Complexity: O(  cooks * minTime * (4 * P * (P + 1)) )  , Space-Complexity: O(1)
int SolutionByLinearSearch(int ranks[], int cooks, int P)
{
    for (int i = 1; i < 4 * P * (P + 1); i++)
    {
        if (isPossible(ranks, cooks, P, i))
        {
            return i;
        }
    }
    return -1;
}

// Time-Complexity:  O( cooks * minTime * log (4 * P * (P + 1)) )   ,  Space-Complexity: O(1)
int SolutionByBinarySearch(int ranks[], int cooks, int P)
{
    int start = 0, end = 4 * P * (P + 1), mid = start + ((end - start) / 2), ans = -1;

    while (start <= end)
    {
        if (isPossible(ranks, cooks, P, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return ans;
}

int main()
{
    // int ranks[] = {1,2,3,4} ;
    // int P = 10 ;

    int ranks[] = {1};
    int P = 8;

    // int ranks[] = {1,1,1,1,1,1,1,1} ;
    // int P = 8 ;

    int cooks = sizeof(ranks) / sizeof(ranks[0]);

    std ::cout << "Minimum time is: " << SolutionByLinearSearch(ranks, cooks, P) << "\n";
    std ::cout << "Minimum time is: " << SolutionByBinarySearch(ranks, cooks, P);
}
