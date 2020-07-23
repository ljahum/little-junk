#include<stdlib.h>
#include<stdio.h>


/*void flower_code() //最简单的一般跳转
{
	__asm
	{
		jz label;
		jnz label;
		__emit 0e8h;
	label:
		mov ax, 8;
		xor ax, 7;
	}
}*/

/*	//call充当跳转
	__asm // call == jmp+push xxx + esp-=4
	{

		jmp jmp1;
	ebp_ex:
		add esp, 4;

		mov eax, [a];
		add eax, 1;
		mov[a], eax;

		jmp GO;
	jmp1:
		call ebp_ex;
		__emit 0e8h;
	GO:
	}
*/

int main()
{
	
	system("pause");
	/*char s[10];
	sscanf_s("%s", s,10);*/
	int a=1;
	__asm //栈传参
	{
		push 0x1;
		add dword ptr ss : [esp], 0x1;
		pop eax;
		mov[a], eax;
	}
	__asm //最简单的一种
	{

		jmp jmp1;
	ebp_ex:
		add esp, 4;
		mov eax, [a];
		add eax, 1;
		mov[a], eax;
		jmp GO;
	jmp1:
		jz label;
		jnz label;
		__emit 0e8h;
	label:
		mov ax, 8;
		xor ax, 7;
		//pash label
		//sub ebp, 0x4;
		call ebp_ex;
		__emit 0e8h;
	GO:
	}

	printf("%d", a);
	for (int i = 1; i < 4; i++)
	{
		int b = i;
		__asm{
			add[b], 0x1;
		}
		printf("%d", i);
	}
	system("pause");
	return 0;
}