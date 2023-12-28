#include <stdio.h>


double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}


double multiplication(double num1, double num2) {
    return num1 * num2;
}

int main() {
    double num1, num2;
    char operator;

 
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    printf("Enter an operator (+, -, *): ");
    scanf(" %c", &operator);  

 
    double result;

    if (operator == '+') {
        result = addition(num1, num2);
    } 
    else if (operator == '-') {
        result = subtraction(num1, num2);
    } 
    else if (operator == '*') {
            result = multiplication(num1, num2);
    }
    else {
        printf("Invalid operator. Please enter +, -, or *.\n");
    }

    printf("Operator based Result: %lf\n", result);

    if (num1 > num2){
        result = subtraction(num1,num2);
        
    }
    else if ( num1 < num2){
        result = addition (num1,num2);
    }
    else {
        result = multiplication(num1 , num2);
    }
    printf("Condition based Result: %lf\n", result);

    return 0;
}
