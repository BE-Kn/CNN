#include <stdio.h>
#define MAXN 100

int main()
{
    int n;
    int id[MAXN], sec[MAXN], like[MAXN], reply[MAXN], save[MAXN], v[MAXN];

    // 1. Input
    printf("Enter number of records: ");
    scanf("%d", &n);
    printf("Enter id sec like reply save:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d", &id[i], &sec[i], &like[i], &reply[i], &save[i]);
        v[i] = sec[i] + like[i] + reply[i] + save[i] * 4;  // save weight=4, others=1
    }

    // 2. Classify
    int high = 0, mid = 0, low = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] >= 500)
            high++;
        else if (v[i] >= 100)
            mid++;
        else
            low++;
    }

    // 3. Find max and min
    int maxV = v[0], minV = v[0];
    int maxIdx = 0, minIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maxV)
        {
            maxV = v[i];
            maxIdx = i;
        }
        if (v[i] < minV)
        {
            minV = v[i];
            minIdx = i;
        }
    }

    // 4. Bubble sort (descending by v, ascending by id if tie)
    for (int i = 0; i < n - 1; i++)
    {
        int needSwap = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j] < v[j + 1] || (v[j] == v[j + 1] && id[j] > id[j + 1]))
            {
                int temp;

                temp = id[j];      id[j] = id[j + 1];      id[j + 1] = temp;
                temp = sec[j];     sec[j] = sec[j + 1];     sec[j + 1] = temp;
                temp = like[j];    like[j] = like[j + 1];   like[j + 1] = temp;
                temp = reply[j];   reply[j] = reply[j + 1]; reply[j + 1] = temp;
                temp = save[j];    save[j] = save[j + 1];   save[j + 1] = temp;
                temp = v[j];       v[j] = v[j + 1];         v[j + 1] = temp;

                needSwap = 1;
            }
        }
        if (!needSwap) break;
    }

    // 5. Output statistics
    printf("\n========== Statistics ==========\n");
    printf("high (v>=500): %d\n", high);
    printf("mid  (100<=v<500): %d\n", mid);
    printf("low  (v<100): %d\n", low);
    printf("Max score: id=%d, v=%d\n", id[maxIdx], maxV);
    printf("Min score: id=%d, v=%d\n", id[minIdx], minV);

    // 6. Output sorted results
    printf("\n========== Sorted Results (descending by score) ==========\n");
    printf("%-6s %-6s %-6s %-6s %-6s %-6s\n", "id", "sec", "like", "reply", "save", "v");
    for (int i = 0; i < n; i++)
    {
        printf("%-6d %-6d %-6d %-6d %-6d %-6d\n", id[i], sec[i], like[i], reply[i], save[i], v[i]);
    }

    printf("\nPress Enter to exit...");
    getchar();
    getchar();  // 第二个 getchar 吃掉缓冲区里的回车
    return 0;
}
