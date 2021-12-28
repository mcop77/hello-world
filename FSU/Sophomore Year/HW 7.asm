# Zhenghao Zhang -- 04/10/09
# newton.asm – a simple program calculating the square root of a given 
#       is number n using singles. The value of the square root of n, 
#       denoted by x, approximated by x=(x+n/x)/2, until the the 
#       absolute value of the difference between new x and the previous 
#       x is smaller than a given threshold such as 1.0E-3.



# function main -- written by Zhenghao Zhang -- 04/10/09
#       calling the calsqrt function and display the results
# Register use:
#       $a0     syscall parameter
#       $v0     syscall parameter
#       $f0     exp and syscall return value
#       $f12    exp and syscall parameter

	.text
	.globl main
main:
	li.s $f0, 361.0
	mfc1 $a0, $f0
	jal calsqrt

done:	
	mtc1 $v0, $f12
	li $v0,2
	syscall

eixt:
	li $v0,10
	syscall



# function calsqrt -- written by Zhenghao Zhang -- 04/10/09
#       calculating the square root of a given number n using singles.
#       The value of the square root of n, denoted by x, approximated 
#       by x=(x+n/x)/2, until the the absolute value of the difference 
#       between new x and the previous x is smaller than a given 
#       threshold such as 1.0E-3.
# Register use:
#       $a0     parameter from calling routine
#       $v0     return value
#       $f0     storing the value of n as a single precision number
#       $f1     current value of x
#       $f2     next value of x
#       $f3     tempory vaiable     
#       $f20    storing constant 2 for dividing
#       $f21    storing constant 0.001 for exit comparision

calsqrt:
	addi $sp, $sp, -24
	swc1 $f0, 20($sp)
	swc1 $f1, 16($sp)
	swc1 $f2, 12($sp)
	swc1 $f3, 8($sp)
	swc1 $f20, 4($sp)
	swc1 $f21, 0($sp)
	
	mtc1 $a0, $f0        	# $f0 gets n
	li.s $f20, 2.0       	# $f20 storing constant 2 for dividing
	li.s $f21, 0.001    	# $f21 storing constant 0.001 for exit comparision
	div.s $f1, $f0, $f20 	# $f1 gets n/2
	
calsqrtloop:	
	div.s $f2, $f0, $f1  	# $f2 gets n/x
	add.s $f2, $f2, $f1  	# $f2 gets n/x + x
	div.s $f2, $f2, $f20 	# $f2 gets x'=(n/x + x)/2
	sub.s $f3, $f2, $f1	# $f3 gets x'-x
	abs.s $f3, $f3		# $f3 gets |x'-x|
	c.lt.s $f3, $f21	# set the flag if |x'-x| < 0.001
	bc1t calsqrtdone  
	mov.s $f1, $f2
	j calsqrtloop
	 	
calsqrtdone:	
	mfc1 $v0, $f2

	lwc1 $f0, 20($sp)
	lwc1 $f1, 16($sp)
	lwc1 $f2, 12($sp)
	lwc1 $f3, 8($sp)
	lwc1 $f20, 4($sp)
	lwc1 $f21, 0($sp)
	addi $sp, $sp, 24
	
	jr $ra	
	     
.data
msg_done: 
	.asciiz "done\n"
