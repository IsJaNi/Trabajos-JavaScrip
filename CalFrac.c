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

// Función para sumar tres fracciones
Fraccion sumarTresFracciones(Fraccion f1, Fraccion f2, Fraccion f3) {
    Fraccion resultado;
    resultado.numerador = (f1.numerador * f2.denominador * f3.denominador) +
                          (f2.numerador * f1.denominador * f3.denominador) +
                          (f3.numerador * f1.denominador * f2.denominador);
    resultado.denominador = f1.denominador * f2.denominador * f3.denominador;
    simplificar(&resultado);
    return resultado;
}

// Función para dividir una fracción entre otra
Fraccion dividirFracciones(Fraccion f1, Fraccion f2) {
    Fraccion resultado;
    resultado.numerador = f1.numerador * f2.denominador;
    resultado.denominador = f1.denominador * f2.numerador;
    simplificar(&resultado);
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

    Fraccion suma = sumarTresFracciones(f1, f2, f3);
    Fraccion division = dividirFracciones(suma, divisor);

    printf("La suma de las tres fracciones es: %d/%d\n", suma.numerador, suma.denominador);
    printf("El resultado de dividir la suma por la fracción dada es: %d/%d\n", division.numerador, division.denominador);

    return 0;
}
