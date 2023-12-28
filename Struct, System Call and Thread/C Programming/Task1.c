#include <stdio.h>
struct Paratha {
    int price;
    int quantity;
};
struct Vegetable {
    int price;
    int quantity;
};
struct MineralWater {
    int price;
    int quantity;
};
int main() {    
    struct Paratha paratha;
    struct Vegetable vegetable;
    struct MineralWater mineralWater;


    printf("Quantity Of Paratha: ");
    scanf("%d", &paratha.quantity);
    printf("Unit price: ");
    scanf("%d", &paratha.price);

    printf("Quantity of Vegetables: ");
    scanf("%d", &vegetable.quantity);
    printf("Unit price: ");
    scanf("%d", &vegetable.price);

    printf("Quantity of Mineral Water: ");
    scanf("%d", &mineralWater.quantity);
    printf("Unit price: ");
    scanf("%d", &mineralWater.price);
 
    int number_of_order;
    printf("Number of People: ");
    scanf("%d", &number_of_order);


    float individual;
    int total;
    
    total = (paratha.quantity * paratha.price) + (vegetable.quantity * vegetable.price) + (mineralWater.quantity * mineralWater.price);
    individual = total / number_of_order;

    printf("Individual people will pay: %.2f tk", individual);

    return 0;
}


