#include <iostream>

using namespace std;


int main()				// ������� �������� ��  �++
{
	long	X = 3;			// ����� ��� ���������
	long	REZ;			// ����� ��� ����������

	_asm {; ������� ���������� �������

	lea EBX, REZ; ������������ ������ ���������� � ������ EBX
		mov EAX, 4; EAX = 4
		imul X; EAX = 4 * x
		add EAX, 5; EAX = 4 * x + 5
		mov EDI, EAX; ����������� ����������  � ������ EDI
		mov EAX, 15; EAX = 15
		imul X; EAX = 15 * x
		imul X; EAX = 15 * x2
		sub EAX, 12; EAX = 15 * x2 � 12
		cdq; ���������� �������� - ������� � EAX - EDX
		div EDI; ����� � EAX, ������� � EDX
		shr EDI, 1; ������ ���������� �� 2
		cmp EDI, EDX; ��������� �������� ������� � ��������
		adc EAX, 0; ��������� �� ������� ���� �� ���������
		mov dword ptr[EBX], EAX; �����������  ���������� � ������


	}				// ��������� ���������� �������
	cout << REZ;
}


