#include <iostream>


int main() {
    int x = 0; // ��������� �������� x
    int result;

    _asm {
        mov eax, x           // ������������ x � ������ eax
        m1 :
        inc eax              // ��������� x
            mov ebx, eax         // ������������ x � ������ ebx
            imul ebx, ebx        // ebx = x * x
            add ebx, 25          // ebx = x * x + 25
            mov edx, 0           // ��������� edx
            mov ecx, 8           // ecx = 8
            div ecx              // edx:eax = (x * x + 25) / 8
            mov result, eax      // ���������� ���������� � ����� result
            cmp result, 20       // ��������� ���������� � 20
            jge m2               // ���� ����� ��� ���� 20, ������� �� m2
            jmp m1               // ����������� �� ������� ����� m1
            m2 :
    }

    std::cout << "x<20: " << x << std::endl;


    return 0;
}