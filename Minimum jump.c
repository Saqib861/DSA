#include <stdio.h>
#include <limits.h>

int minJumps(int arr[], int n) {
    int maxReach = arr[0]; // Maximum reachable index from the current index
    int steps = 0;          // Number of jumps made so far
    int i = 1;               

    if (n == 1) {
        return 0; 
    }
    if (arr[0] == 0) {
        return -1; 
    }

    while (i < n) {

        if (i == n - 1) {
            return steps;
        }


        maxReach = (i + arr[i] > maxReach) ? (i + arr[i]) : maxReach;
        if (i >= maxReach) { 
            if (arr[i] == 0) {
                return -1; // Reached a dead end
            }
            steps++; // Need another jump to reach further
            maxReach = i + arr[i]; // Update maxReach for the next jump
        }

        i++;
    }

    return -1; // Couldn't reach the end
}

int main() {
    int arr[] = {2, 3, 1, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int jumps = minJumps(arr, n);

    if (jumps == -1) {
        printf("Couldn't reach the end\n");
    } else {
        printf("Minimum number of jumps to reach the end: %d\n", jumps);
    }

    return 0;
}
