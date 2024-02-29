#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Fraccion;

// Función para calcular el máximo común divisor
int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Función para simplificar una fracción
void simplificar(Fraccion *f) {
    int divisor = mcd(f->numerador, f->denominador);
    f->numerador /= divisor;
    f->denominador /= divisor;
}

// Función para sumar tres fracciones y devolver el resultado como un número decimal (float)
float sumarTresFracciones(Fraccion f1, Fraccion f2, Fraccion f3) {
    float resultado;
    resultado = (float)(f1.numerador * f2.denominador * f3.denominador) +
                (float)(f2.numerador * f1.denominador * f3.denominador) +
                (float)(f3.numerador * f1.denominador * f2.denominador);
    resultado /= (float)(f1.denominador * f2.denominador * f3.denominador);
    return resultado;
}

// Función para dividir una fracción entre otra y devolver el resultado como un número decimal (float)
float dividirFracciones(Fraccion f1, Fraccion f2) {
    float resultado;
    resultado = (float)f1.numerador * (float)f2.denominador;
    resultado /= (float)f1.denominador * (float)f2.numerador;
    return resultado;
}

int main() {
    Fraccion f1, f2, f3, divisor;

    printf("Ingrese la primera fracción (numerador/denominador): ");
    scanf("%d/%d", &f1.numerador, &f1.denominador);

    printf("Ingrese la segunda fracción (numerador/denominador): ");
    scanf("%d/%d", &f2.numerador, &f2.denominador);

    printf("Ingrese la tercera fracción (numerador/denominador): ");
    scanf("%d/%d", &f3.numerador, &f3.denominador);

    printf("Ingrese la fracción para la división (numerador/denominador): ");
    scanf("%d/%d", &divisor.numerador, &divisor.denominador);

    float suma = sumarTresFracciones(f1, f2, f3);
    float division = dividirFracciones((Fraccion){suma, 1}, divisor);

    printf("La suma de las tres fracciones es: %.2f\n", suma);
    printf("El resultado de dividir la suma por la fracción dada es: %.2f\n", division);

    return 0;
}
