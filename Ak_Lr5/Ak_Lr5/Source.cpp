#include <iostream>

using namespace std;


int main()				// початок програми на  С++
{
	long	X = 3;			// змінна для аргументу
	long	REZ;			// змінна для результату

	_asm {; початок асемблерної вставки

	lea EBX, REZ; завантаження адреси результатів в регістр EBX
		mov EAX, 4; EAX = 4
		imul X; EAX = 4 * x
		add EAX, 5; EAX = 4 * x + 5
		mov EDI, EAX; пересилання знаменника  в регістр EDI
		mov EAX, 15; EAX = 15
		imul X; EAX = 15 * x
		imul X; EAX = 15 * x2
		sub EAX, 12; EAX = 15 * x2 – 12
		cdq; розширення операнда - ділимого в EAX - EDX
		div EDI; часне – EAX, залишок – EDX
		shr EDI, 1; ділення знаменника на 2
		cmp EDI, EDX; порівняння половини дільника з залишком
		adc EAX, 0; додавання до часного заєму від порівняння
		mov dword ptr[EBX], EAX; пересилання  результату в пам’ять


	}				// закінчення асемблерної вставки
	cout << REZ;
}


