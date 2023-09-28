#include <iostream>

int main() {
    long X;           // ����� ��� ���������
    long step;        // ���� ��������� ���������
    long REZ[7];      // ����� ������ ��� ����������

    std::cout << "Enter X: ";
    std::cin >> X;

    std::cout << "Enter number of steps: ";
    std::cin >> step;

    for (int i = 0; i < 7; ++i) {
        long result;

        // ���������� ������� x^2 + 2x - 14
        _asm {
            mov EAX, X
            imul EAX, X        // EAX = X * X
            mov EDX, X
            add EDX, EDX       // EDX = 2 * X
            sub EAX, 14
            add EAX, EDX       // EAX = X^2 + 2X - 14

            // ���������� ��������-������� � EAX-EDX
            cdq                // ���������� EAX �� EDX:EAX
            mov EDI, EAX       // �����'���������� EAX � EDI
            shr EDI, 1         // EDI = EDI / 2 (�������� �������)
            cmp EDI, EDX       // ��������� �������� ������� � ��������
            adc EAX, 0         // ��������� �� ������ �� ���������

            
        }

        X += step; // ��������� ���������
    }
    // ��������� ����������
    for (int i = 0; i < 7; ++i) {
        std::cout << "REZ[" << i << "] = " << REZ[i] << std::endl;
    }

    return 0;
}

