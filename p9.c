#include <stdio.h>

int main() {
    int n, i, j;
    float weight[20], profit[20], ratio[20];
    float capacity, totalProfit = 0, temp;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights and profits:\n");
    for(i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    /* Sort items based on ratio in descending order */
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(weight[i] <= capacity) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);
    return 0;
}
