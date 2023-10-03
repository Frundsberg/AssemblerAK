#include <iostream>


int main() {
    int x = 0; // Початкове значення x
    int result;

    _asm {
        mov eax, x           // Завантаження x в регістр eax
        m1 :
        inc eax              // Інкремент x
            mov ebx, eax         // Завантаження x в регістр ebx
            imul ebx, ebx        // ebx = x * x
            add ebx, 25          // ebx = x * x + 25
            mov edx, 0           // Обнулення edx
            mov ecx, 8           // ecx = 8
            div ecx              // edx:eax = (x * x + 25) / 8
            mov result, eax      // Збереження результату в змінну result
            cmp result, 20       // Порівняння результату з 20
            jge m2               // Якщо більше або рівне 20, перейти до m2
            jmp m1               // Повернутися до початку циклу m1
            m2 :
    }

    std::cout << "x<20: " << x << std::endl;


    return 0;
}