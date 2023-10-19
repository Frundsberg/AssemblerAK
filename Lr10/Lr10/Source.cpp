#include <iostream>

int main()
{
    double x = 2.0; // �������� x
    double a = 3.5; // ���������� ����� x^2
    double b = 7.2; // ���������� ����� x
    double c = 24.0; // ���������

    double Y;

    __asm
    {
        finit; �������� ������� FPU
        fld x; ������������ �������� x �� ������� ����� FPU
        fmul x; �������� x �� ���� ����(x ^ 2)
        fmul a; ��������� x ^ 2 �� 3.5 (3.5x ^ 2)
        fld x; ������������ x � ����
        fmul b; �������� x �� 7.2 (7.2x)
        fadd; ��������� 3.5x ^ 2 �� 7.2x
        fadd c; ��������� ���������� �� ��������� 24
        fstp Y; ���������� ���������� � Y
    }

    std::cout << "Y: " << Y << std::endl;

    return 0;
}
  