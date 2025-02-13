.data

mensagem: .asciiz "\nAbuble :P"

.text
main:  	
	#imprime inteiro
	jal imprime_int

	# imprime mensagem
	li $v0, 4
	la $a0, mensagem
	syscall
	
	li $v0, 10
	syscall # feito!

imprime_int:	# imprime inteiro
	li $v0,1
	li $a0, 35
	syscall
	jr $ra
