#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inc_insertion_sort(int list[], int first, int last, int gap, int* compareCount, int* moveCount) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        *compareCount += 1;

        for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
            list[j + gap] = list[j];
            *moveCount += 1;
            *compareCount += 1;
        }

        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n, float* avgCompareCount, float* avgMoveCount) {
    int i, gap;
    float compareCountTotal = 0, moveCountTotal = 0;

    printf("Original List\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n\n");

    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0)
            gap++;

        if (gap == 3) {
            printf("Shell Sort\n");
        }

        for (i = 0; i < gap; i++) {
            int compareCount = 0, moveCount = 0;

            inc_insertion_sort(list, i, n - 1, gap, &compareCount, &moveCount);

            // ���ĵ� ��� ���
            for (int j = 0; j < n; j++) {
                printf("%d ", list[j]);
            }
            printf("\n");

            // �κ� ����Ʈ �� ��� �� Ƚ���� ��� �̵� Ƚ���� ����
            compareCountTotal += compareCount / (float)gap;
            moveCountTotal += moveCount / (float)gap;
        }
    }

    // ��� �� Ƚ���� ��� �̵� Ƚ�� ���
    *avgCompareCount = compareCountTotal / 20.0;
    *avgMoveCount = moveCountTotal / 20.0;
}

int main() {
    srand(time(NULL)); // ���� ������ ���� �õ� ����

    int arr[20]; // 20���� ������ ������ �迭
    float avgCompareCount, avgMoveCount;

    // 0���� 99������ ������ �迭�� ����
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
    }

    // �� ���� ����
    shell_sort(arr, 20, &avgCompareCount, &avgMoveCount);

    // ��� �� Ƚ���� ��� �̵� Ƚ�� ���
    printf("\nAverage Move Count: %.2f\n", avgMoveCount);
    printf("Average Compare Count: %.2f\n", avgCompareCount);

    return 0;
}
