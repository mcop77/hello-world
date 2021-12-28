# Marshall Copeland -- 04/08/21
# part2.asm 
#	(40 points) Please implement a function called “appcos” that approximates cos(x) by1 -  x2/2! + x4/4! – 
#		x6/6! ...


# funtion main
#	function to calculate cosine
# Register use:
#	$a0	what x is in the equation
#	$a1	the number of terms in the approximation
#	$f0	copy of a0
#	$f1	final result
#	$f2	square loop result
#	$f3	temp factorial result
#	$f4	factorial copy of a0
#	$f5	loop counter
#	$f6	x factor
# 	$f7	checks if even
#	$f8	factorial result
#	$f9	appcosloop total counter, square loop and factorial loop counter
#	$f10 	counter
#	$f11    ++
#	$f13 	add 2
#	$v0	where the result is returned to



	.text
	.globl main
main:	

	li.s $f0, 4.0
	mfc1 $a0, $f0
	li $a1, 30
	jal appcos
	
	mtc1 $v0, $f12
	li $v0,2
	syscall
	
eixt:li $v0,10
	syscall
	

# TODO: implment your function here
appcos:
	addi $sp, $sp, -64		# save to stack
	sw $ra, 56($sp)		
	swc1 $f0, 52($sp)
	swc1 $f1, 48($sp)
	swc1 $f2, 44($sp)
	swc1 $f3, 40($sp)
	swc1 $f4, 36($sp)
	swc1 $f5, 32($sp)
	swc1 $f6, 28($sp)
	swc1 $f7, 24($sp)
	swc1 $f8, 20($sp)
	swc1 $f9, 16($sp)
	swc1 $f10, 8($sp)
	swc1 $f11, 4($sp)
	swc1 $f13, 0($sp)


					# f0 is where the copy of a0 is
	li.s $f1, 1.0			# result
	li.s $f2, 0.0			# another temp result
	add.s $f2, $f2, $f0		# f2 is a copy of a0
	li.s $f3, 0.0			# temp factorial result
	li.s $f4, 0.0			# factorial copy of a0
	
	li.s $f5, 0.0
	li.s $f6, 1.0			# x factor loaded with one
	li.s $f7, 0.0			# even checker
	li.s $f8, 0.0			# factorial result
	li.s $f9, 0.0			# appcosloop total counter, square loop and factorial loop counter
	li.s $f10, 0.0			# factorial result
	li.s $f11, 2.0			# hard coded x factor incrementer
	li.s $f13, 1.0			# hard coded ++ incrememnter


	li $v0, 1			# make sure enough terms
	li $t0, 0
	add $t0, $t0, $a1
	sw $t0, 60($fp)
	lwc1 $f4, 60($fp)
	cvt.s.w $f7, $f4
	li.s $f4, 0.0
	c.eq.s $f7, $f6
	bc1t appcosdone			# if there is only one term exit
	add.s $f6, $f6, $f6		# double f6 to get ready for equation

appcosloop:
	li.s $f9, 0.0			# clear f9
	add.s $f5, $f5, $f13		# increase the counter 
	add.s $f9, $f9, $f5		# copy f5 to f9 so it can be modified
	sll $f9, $f9, 31		# shift left to get leftmost bit
	srl $f9, $f9, 31		# shift right to only have one bit
	beq $f9, $f7, counteven		# if even go to even
	bne $f9, $f7, countodd		# if odd go to odd
	li $f9, 0.0			# clear f9 for other functions

	bne $f5, $a1, appcosloop	# continue looping until equal to a1

	li $v0, 0			# clear v0 after loop to get ready to return result
	mfc1 $v0, $f0			# add final result to v0


counteven:
	li.s $f9, 1.0 			# keeps square loop from over running
	jal squareloop			# run square loop
	add.s $f6, $f6, $f11		# add x factor by two for each iteration
		
	li.s $f3, 0.0			# clear f3
	add.s $f3, $f3, $f6		# copy of f6		
	li.s $f8, 0.0			# clear f8
	add.s $f8, $f8, $f6		# copy of f6
	
	jal factorialloop		# run factorial loop

	div.s $f2, $f2, $f8		# f2 is square result / factorial result

	sub.s $f1, $f1, $f2		# f1 is running total



countodd:
	li.s $f9, 1.0 			# keeps square loop from over running
	jal squareloop			# run square loop
	add.s $f6, $f6, $f11		# add x factor by two for each iteration

	li.s $f3, 0.0			# clear f3
	add.s $f3, $f3, $f6		# copy of f6		
	li.s $f8, 0.0			# clear f8
	add.s $f8, $f8, $f6		# copy of f6

	jal factorialloop		# run factorial loop

	div.s $f2, $f2, $f8		# f2 is square result / factorial result

	add.s $f1, $f1, $f2		# f1 is running total


squareloop:
	mul.s $f2, $f2, $f0		# multiply f0 by itself and stored in $f2
	add.s $f9, $f9, $f13		# increase counter
	bne $f9, $f6, squareloop	# keep looping until equal to f6
	li.s $f9, 0.0			# clear t4
		

factorialloop:
	sub.s $f3, $f3, $f13		# f3 is now f8 - count
	mul.s $f8, $f8, $f3		# f8 is the running total
	add.s $f9, $f9, $f13		# increase counter
	bne $f9, $f6, factorialloop	# continue until f7
	li.s $f0, 0.0			# clear f0
	li.s $f9, 0.0			# clear t4


appcosdone:
	sw $ra, 56($sp)		
	swc1 $f0, 52($sp)
	swc1 $f1, 48($sp)
	swc1 $f2, 44($sp)
	swc1 $f3, 40($sp)
	swc1 $f4, 26($sp)
	swc1 $f5, 32($sp)
	swc1 $f6, 28($sp)
	swc1 $f7, 24($sp)
	swc1 $f8, 20($sp)
	swc1 $f9, 16($sp)
	swc1 $f10, 8($sp)
	swc1 $f11, 4($sp)
	swc1 $f13, 0($sp)
	addi $sp, $sp, 60

	jr $ra	

	
	













