	.data

msg:	.asciiz "hello"
endl:	.asciiz "\n"


	.text
	.globl main

main:
	    addi $sp, $sp, -16
	    sw $t0, 12($sp)
	    sw $t1, 8($sp)
	    sw $t8, 4($sp)
	    sw $t9, 0($sp)

	    la $a0, msg
	    li $a1, 5
     	   
	    ori $t0, $a0, 0
            sll $t1, $a1, 2 
            add $t1, $t1, $a0 
            addi $t1, $t1, -4 
sa1c_LOOP:  
            lw $t8, 0($t0)
            lw $t9, 0($t1)
            sw $t8, 0($t1)
            sw $t9, 0($t0)
            addi $t0, $t0, 4
            addi $t1, $t1, -4

            bne $t1, $t0, sa1c_LOOP

	    la $a0, msg		#syscall to print message
	    li $v0, 4
	    syscall

	    la $a0, endl		#syscall to print endl
	    li $v0, 4
	    syscall

	    li $v0, 10		#syscall to exit program
	    syscall
           