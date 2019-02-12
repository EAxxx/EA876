				;		Implementacao de funcao
				;		Cabecalho: int soma( int a, int b)
				
				;		Inicializa stack pointer
				MOV		SP, #0x100
				B		PROGRAMAPRINCIPAL
				
				;		Define funcao
SOMA
				LDR		LR, [SP], #-4 ; Tira o PC da pilha
				LDR		R0, [SP], #-4
				LDR		R1, [SP], #-4
				ADD		R2, R0, R1
				MOV		PC, LR ; Retorna PC ao PC
				
				
PROGRAMAPRINCIPAL
				;		Empilha operandos
				MOV		R0, #1
				STR		R0, [SP, #4]!
				
				MOV		R0, #2
				STR		R0, [SP, #4]!
				
				;		Inicio da chamada de funcao: empilha endereco de retorno
				STR		PC, [SP, #4]!
				
				B		SOMA
				
				
				
RETORNOSOMA
				;		Retorno
				STR		R2, [SP, #4]!
				
				
				
				
