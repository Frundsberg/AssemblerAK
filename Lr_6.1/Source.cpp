#include <iostream>

int main() {
    long X;           // Змінна для аргументу
    long step;        // Крок збільшення аргументу
    long REZ[7];      // Масив змінних для результату

    std::cout << "Enter X: ";
    std::cin >> X;

    std::cout << "Enter number of steps: ";
    std::cin >> step;

    for (int i = 0; i < 7; ++i) {
        long result;

        // Обчислення рівняння x^2 + 2x - 14
        _asm {
            mov EAX, X
            imul EAX, X        // EAX = X * X
            mov EDX, X
            add EDX, EDX       // EDX = 2 * X
            sub EAX, 14
            add EAX, EDX       // EAX = X^2 + 2X - 14

            // Розширення операнда-ділимого в EAX-EDX
            cdq                // Розширення EAX до EDX:EAX
            mov EDI, EAX       // Запам'ятовування EAX в EDI
            shr EDI, 1         // EDI = EDI / 2 (половина дільника)
            cmp EDI, EDX       // Порівняння половини дільника з залишком
            adc EAX, 0         // Додавання до частки від порівняння

            
        }

        X += step; // Збільшення аргументу
    }
    // Виведення результатів
    for (int i = 0; i < 7; ++i) {
        std::cout << "REZ[" << i << "] = " << REZ[i] << std::endl;
    }

    return 0;
}

