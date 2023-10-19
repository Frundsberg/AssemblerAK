#include <iostream>

int main()
{
    double x = 2.0; // Значення x
    double a = 3.5; // Коефіцієнт перед x^2
    double b = 7.2; // Коефіцієнт перед x
    double c = 24.0; // Константа

    double Y;

    __asm
    {
        finit; Очищення регістрів FPU
        fld x; Завантаження значення x на вершину стека FPU
        fmul x; Множення x на саме себе(x ^ 2)
        fmul a; ПМноження x ^ 2 на 3.5 (3.5x ^ 2)
        fld x; Завантаження x в стек
        fmul b; Множення x на 7.2 (7.2x)
        fadd; Додавання 3.5x ^ 2 та 7.2x
        fadd c; Додавання результату до константи 24
        fstp Y; Збереження результату в Y
    }

    std::cout << "Y: " << Y << std::endl;

    return 0;
}
  