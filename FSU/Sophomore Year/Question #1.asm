main:
	li $t0, 0		# start counter

loop:
	andi $t1, $s0, 1	# get left bit of $s0
	add $s1, $s1, $t1	# $s1 is now the left bit
	sll $s1, $s1, 1		# shift to move $s1 bit left
	srl $s0, $s0, 1		# get next $s0 bit on right
	
	beq $t0, 6, end		# only loop 7 times
	addi $t0, $t0, 1	# if < 7 times keep looping
	j loop

end:
	jr $ra			# exit program