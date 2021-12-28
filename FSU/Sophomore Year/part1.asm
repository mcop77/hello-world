# Marshall Copeland -- 04/08/21
# part1.asm 
#	1. (60 points) Please implement two functions, where one calls the other, following the MIPS 		#		calling conventions:
# 	A. (20 points) A function called “sameparity” which takes in $a0 and $a1 two integers and returns 1 	#		in $v0 if they are both even or both odd.
#	B. (40 points) A function called “count” which takes two inputs:
#		$a0: the starting address of an array of integers 
#		$a1: the length of the array
#		“count” should scan every neighboring two elements in the array, call “sameparity” to find if #		they are of the same parity, and return in $v0 the total number of neighboring pairs that 	#		have the same parity. 
#		For example, if the array is 41, 28, 3, 65, 9, “count” should return 2, because there are two #		neighboring pairs, (3, 65) and (65,9), that have the same parity.


# funtion main
#	calling count function which calls same parity within it
# Register use:
#	$a0	where the starting address of the array is stored
#	$a1	the length of the array
#	$v0	where the sameparity count is returned, and the total count of sameparity
#	$s0	copy of a0 saved in the stack
#	$s1 	copy of a1 saved in the stack
#	$s3	count register originally saved to the stack
# 	$sp	stack pointer
# 	$ra	return address also saved to the stack


	.data
A: .word  41, 28, 3, 65, 9, 8, 10, 12, 11, 10
	
	.text
	.globl main
main:	
	la $a0, A		# main function provided
	li $a1, 10
	jal count
	
	ori $a0, $v0, 0
	li $v0, 1
	syscall
	
	li $v0,10 #exit
	syscall

# TODO: implment your function here
sameparity:
	sll $a0, $a0, 31 	# shift left until only 1 bit
	sll $a1, $a1, 31	# shift left until only 1 bit
	xor $a0, $a0, $a1	# if xor returns 0, they are the same
	beq $a0, $0, return	# goes to return 1
	li $v0, 0		# if xor returns 1, they are not the same
	jr $ra

return:
	li $v0, 1		# load v0 with 1
	jr $ra
	
# TODO: implment your function here
count:
	addi $sp, $sp, -20	# add space to the stack
	sw $ra, 16($sp)		# save ra to the stack
	sw $s0, 12($sp)		# save s0 to the stack (copy of a0)
	sw $s1, 8($sp)		# save s1 to the stack (copy of a1)
	sw $s2, 4($sp)		# save s2 to the stack (loop counter)
	sw $s3, 0($sp)		# save s3 to the stack (same parity counter)

	add $s0, $0, $a0	# array address stored in s0
	add $s1, $0, $a1	# array length stored in s1
	
	li $s2, 1		# initialize s2 to 1
	li $s3, 0		# initialize s3 to 0
	
	lw $a0, 0($s0)		# load first value to a0
	lw $a1, 4($s0)		# load second value to a1
	

countloop:
	jal sameparity		# call sameparity 
	add $s3, $s3, $v0	# add sameparity result to the count
	li $v0, 0		# clear v0

	addi $s0, $s0, 4	# move to next array index

	lw $a0, 0($s0)		# load first value to a0
	lw $a1, 4($s0)		# load second value to a1

	addi $s2, $s2, 1	# counts how many times loop runs

	bne $s1, $s2, countloop	# if array length != to loop count, repeat


countdone:
	li $v0, 0		# reset v0 to 0
	add $v0, $v0, $s3	# add the count to v0

	lw $ra, 16($sp)		# load ra from the stack
	lw $s0, 12($sp)		# load s0 from the stack (copy of a0)
	lw $s1, 8($sp)		# load s1 from the stack (copy of a1)
	lw $s2, 4($sp)		# load s2 from the stack (loop counter)
	lw $s3, 0($sp)		# load s3 from the stack (same parity counter)
	addi $sp, $sp, -20	# load space from the stack

	jr $ra







