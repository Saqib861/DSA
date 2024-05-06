#include <stdio.h>
#include <math.h>

int is_t_prime(int num) {
  if (num <= 1) {
    return 0; // 1 or less has only 1 divisor
  }
  int i;
  int count = 0;
  for ( i = 1; i <= sqrt(num); ++i) {
    if (num % i == 0) {
      count++;
      if (count > 2) {
        return 0; // More than 2 divisors
      }
      if (i * i != num) {
        count++; // If not perfect square, count divisor for other root
      }
    }
  }
  return count == 2; // Exactly two divisors found
}

int main() {
  int n,i;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the integers:\n");
  for ( i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  printf("T-primes:\n");
  for ( i = 0; i < n; ++i) {
    if (is_t_prime(arr[i])) {
      printf("%d ", arr[i]);
    }
  }
  printf("\n");

  return 0;
}
