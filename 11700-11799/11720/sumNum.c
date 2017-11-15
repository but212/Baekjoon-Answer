#include <stdio.h>

inline int solve(char nums[], int cnt)
{
    int result = 0;
    for (int i = 0; i < cnt; i++)
        result += nums[i] - '0';
    
    return result;
}

int main(void)
{
    int cnt; scanf("%d", &cnt);
    char nums[101]; scanf("%s", &nums);
    
    printf("%d\n", solve(nums, cnt));
    return 0;
}
