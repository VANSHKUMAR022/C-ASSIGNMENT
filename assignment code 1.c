#include <stdio.h>

// Structure to store product information
typedef struct Product {
  char name[50];
  float price;
  float discount;
} Product;

int main() {
  // Get number of products
  int n;
  printf("Enter the number of products: ");
  scanf("%d", &n);

  // Get Mr. Ravi's desired discount range
  float min_discount, max_discount;
  printf("Enter the minimum discount (exclusive): ");
  scanf("%f", &min_discount);
  printf("Enter the maximum discount (exclusive): ");
  scanf("%f", &max_discount);

  // Read product information
  Product products[n];
  for (int i = 0; i < n; i++) {
    printf("Enter product %d details:\n", i + 1);
    printf("Name: ");
    scanf("%s", products[i].name);
    printf("Price: ");
    scanf("%f", &products[i].price);
    printf("Discount: ");
    scanf("%f", &products[i].discount);
  }

  // Find and list suitable products
  printf("Products within %f%% and %f%% discount range:\n", min_discount, max_discount);
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (products[i].discount > min_discount && products[i].discount < max_discount) {
      printf("- %s (%.2f%% off)\n", products[i].name, products[i].discount * 100);
      found = 1;
    }
  }

  if (!found) {
    printf("No products found within your specified discount range.\n");
  }

  return 0;
}