#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;

    printf("Enter the number of values: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid value : %d\n", n);
        return 1;
    }

    double *values = malloc(n * sizeof *values);

    if (!values)
    {
        printf("Error while allocating values.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("value No %d: ", i + 1);
        scanf("%lf", &values[i]);
    }

    double sum;
    for (int i = 0; i < n; i++)
    {
        sum += values[i];
    }
    
    printf("Sum : %.2lf\n", sum);
    printf("Avg : %.2lf\n", (sum / n));

    free(values);
    
    return 0;
}