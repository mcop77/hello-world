      .data

msg_fsu: .asciiz  "Florida State University retained its place in the Top 20 among national public universities in the latest U.S. News & World Report rankings, while improving in several key measures considered in the publication’s methodology.

 

FSU is No. 19 on the list, marking the second consecutive year that the university placed in the Top 20. The rankings appear in U.S. News & World Report’s “Best Colleges 2021” guidebook.

 

“Our continued recognition as one of the nation’s Top 20 public universities is a reflection of Florida State’s commitment to academic excellence and student success,” said President John Thrasher. “This is the result of hard work by our students, faculty and staff and support from the Florida Legislature and the Florida Board of Governors, who have been staunch champions of our goals and aspirations.” 

 

The university improved on 11 of 15 key factors used to compile the ranking score. Once again, the metrics shined a spotlight on Florida State’s continued emphasis on student success. \n\n"

 

msg_char: .asciiz "a"

msg_print0: .asciiz "Char "

msg_print1: .asciiz " appeared "

msg_print2: .asciiz " times\n"

 

      .text

      .globl main

main:

      li $v0,4

      la $a0,msg_fsu

      syscall

     

      li $s1, 'a'

      li $s7, 'z'

      addi $s7, $s7, 1

     

main_L1:  

      la $a0, msg_char

      sb $s1, 0($a0)

      la $a0, msg_fsu

      ori $a1, $s1, 0

      jal charfreq

      ori $s0, $v0, 0

 

      li $v0,4

      la $a0,msg_print0

      syscall

      li $v0,4

      la $a0,msg_char

      syscall

          

      li $v0,4

      la $a0,msg_print1

      syscall

     

      li  $v0, 1         

    ori $a0, $s0, 0

    syscall    

     

      li $v0, 4

      la $a0,msg_print2

      syscall

 

      addi $s1, $s1, 1

      slt $t0, $s1, $s7

      bne $t0, $0, main_L1

 

      li $v0,10 #exit

      syscall

 

charfreq: 
      beq $a1, $s1, count	# compare current char to char
      addi $a1, $a1, 1		# get next character
      beqz $a1, end		# if end of string end
      j charfreq		# loop


count:
      addi $v0, $v0, 1		# increase counter
      addi $a1, $a1, 1		# get next character in string
      j charfreq		# loop back to charfreq

end:
      jr $ra			# end charfreq
      

      






