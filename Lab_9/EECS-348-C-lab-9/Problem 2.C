#include <stdio.h>

void printCombinations(int score, int touchdowns, int fieldGoals, int safeties) {
    if (score == 0) {
        printf("%d TD + %d FG + %d Safety\n", touchdowns, fieldGoals, safeties);
    }
}

void findCombinations(int score, int touchdowns, int fieldGoals, int safeties) {
    if (score < 0) {
        return;
    }

    if (score == 0) {
        printCombinations(0,touchdowns, fieldGoals, safeties);
        return;
    }

    // Try all possible combinations
    findCombinations(score - 6, touchdowns + 1, fieldGoals, safeties);
    findCombinations(score - 3, touchdowns, fieldGoals + 1, safeties);
    findCombinations(score - 2, touchdowns, fieldGoals, safeties + 1);
    findCombinations(score - 8, touchdowns + 1, fieldGoals, safeties);
    findCombinations(score - 7, touchdowns + 1, fieldGoals, safeties);
}

int main() {
    int score;

    printf("Enter 0 or 1 to STOP\n");

    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        findCombinations(score, 0, 0, 0);
    }

    return 0;
}

