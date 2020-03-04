; Exemplo de soma com pilha

; Inicializa pilha na posicao 0x100
		MOV		SP, #0x100
		
; Carrega operandos para pilha		
		MOV		R0, #1
		STR		R0, [SP, #4]!
		
		MOV		R0, #2
		STR		R0, [SP, #4]!

; Desempilha operandos, executa operacao, empilha resultado
		LDR		R0, [SP], #-4
		LDR		R1, [SP], #-4
		ADD		R2, R0, R1
		STR		R2, [SP, #4]!

; Desempilha resultado para mostrar em R0
		LDR		R0, [SP], #-4
