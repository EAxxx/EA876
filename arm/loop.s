;Exemplo de codigo com laco
		MOV		R0, #10
		MOV		R1, #0
START
		ADD		R1, R1, #1
		ADD		R0, R0, #-1
		CMP		R0, #0
		BNE		START
		
		END
