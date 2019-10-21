
# HW1 Driver
# 2018 Daniel Pade
# All of your functions should be placed between the comments below

.data
  pangram: .asciiz "Cozy lummox gives smart squid who asks for job pen"
  less: .asciiz "ASCII arranges characters roughly alphabetically."
  more: .asciiz "ascii arranges characters roughly alphabetically."

  # Explanatory text
  test_suite_1: .asciiz "Testing `length', `suffix', and `memchr':"
  test_suite_2: .asciiz "Testing `length', `suffix', `memchr', and `strncmp':"

.text
  j main

  #------------------ PUT YOUR CODE HERE ---------------------------
.globl length
length:

   addi $sp $sp -4		#saving used variables
   sw $t0 0($sp)
   addi $sp $sp -4
   sw $t1 0($sp)
   addi $sp $sp -4
   sw $t2 0($sp) 


   or $t0 $0 $a0     #load a0 into temporary0
   ori $t2 $0 0      #counter is 0
   j loop_length
  

  loop_length: 
  lb $t1 0($t0)    #the byte of the string
  beq $t1 $0 end_loop_length  #if the byte is null then end

  addi $t2 $t2 1   #increments counter
  addi $t0 $t0 1   #increments byte placement
  j loop_length	   #jump back to loop


  end_loop_length:
   or $v0 $0 $t2    #return 50 back in v0

  lw $t2 0($sp)		#returning prev values
    addi $sp $sp 4
  lw $t1 0($sp)
    addi $sp $sp 4
  lw $t0 0($sp)
    addi $sp $sp 4
  jr $ra


.globl suffix
suffix:
   add $v0 $a0 $a1   
   jr $ra

.globl memchr
memchr: 

  or $t0 $0 $a0		#the str is loaded into t0
  ori $t1 $0 0		#counter is 0
  j loop_memchr

  loop_memchr:
  lb $t0 ($a0)
  beq $t0 $a1 wasFound	#if the char is equal to the given char, jump to wasFound
  beq $t1 $a2 wasNOTfound	#if the counter is equal to the given n, the number was not found
  addi $a0 $a0 1		#go to next byte of the string (next char)
  addi $t1 $t1 1		#add 1 to the counter
  j loop_memchr		#jump back to start of loop_memchar

  wasFound: 
  or $v0 $0 $t1		#return the index of c
  jr $ra

  wasNOTfound:
  ori $v0 $0 0		#return -1
  sub $v0 $v0 1
  jr $ra


.globl strncmp
 strncmp:
  #or $t0 $0 $a0
  #or $t1 $0 $a1
  ori $t2 $0 0
  j loop_strcmp

  loop_strcmp:
  lb $t0 ($a0) 				#load a char of str0
  lb $t1 ($a1)  			#load a char of str1
  bne $t0 $t1 doNotEqual		#if the two char of the strings are not equal than jump to isNotEqual
  beq $t2 $a2 strIsEqual		#if the string does not encounter different strings, jump to strIsEqual
  addi $t2 $t2 1			#add 1 to the counter
  addi $a0 $a0 1			#add 1 to the str0 (next char)
  addi $a1 $a1 1			#add 1 to the str1
  j loop_strcmp				#jump back to the loop_strcmp

  doNotEqual:
  slt $t3 $t0 $t1			#set t3 to 0 if t0 is greater than and 1 is less than
  beq $t3 0 greaterThan			#jump to greaterThan to return a positive int
  beq $t3 1 lessThan			#jump to lessThan to return a negative int

	greaterThan:
 	ori $v0 $0 1
	jr $ra				#return 1

	lessThan:
	ori $v0 $0 0
	sub $v0 $v0 1
	jr $ra				#return -1


  strIsEqual:
  ori $v0 $0 0
  jr $ra				#return 0 (equal)

  #------------------ DON'T MODIFY BELOW ---------------------------

  .globl main
  main:
    la   $s0 pangram
    la   $s1 less
    la   $s2 more

    la   $a0 test_suite_1
    ori  $v0 $0 4
    syscall
    jal  endl

    # Find the length of `pangram'                        -> print 50
    jal  tab

    or   $a0 $0 $s0
    jal  length
    or   $s3 $0 $v0  # We need the length for memchr

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal  endl


    # Search for `n' in all of pangram                    -> print 49
    jal  tab

    or   $a0 $0 $s0
    ori  $a1 $0 0x6E
    or   $a2 $0 $s3
    jal  memchr

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal  endl

    # Search for `n' in the last half of pangram          -> print 24
    jal  tab

    srl  $s3 $s3 1

    or   $a0 $0 $s0
    or   $a1 $0 $s3
    jal  suffix

    or   $a0 $0 $v0
    ori  $a1 $0 0x6E
    or   $a2 $0 $s3
    jal  memchr

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal  endl

    # Search for `n' in the first half of pangram         -> print -1
    jal  tab

    or   $a0 $0 $s0
    ori  $a1 $0 0x6E
    or   $a2 $0 $s3
    jal  memchr

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal  endl

    jal  endl

    la   $a0 test_suite_2
    ori  $v0 $0 4
    syscall
    jal  endl

    # Verify less < more                                  -> print -1
    jal  tab

    or   $a0 $0 $s1
    jal  length

    or   $s3 $0 $v0  # Store the length of the strings for later

    or   $a0 $0 $s1
    or   $a1 $0 $s2
    or   $a2 $0 $s3
    jal  strncmp

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal  endl

    # Verify more > less                                   -> print 1
    jal  tab
    jal  space

    or   $a0 $0 $s2
    or   $a1 $0 $s1
    or   $a2 $0 $s3
    jal  strncmp

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal endl

    # Find the first occurrence of ' ' in less
    or   $a0 $0 $s1
    ori  $a1 $0 0x20
    or   $a2 $0 $s3
    jal  memchr

    addi $s4 $v0 1  # Save the index of ' ' (+1)

    # Get the suffixes of less & more, along with the length
    or   $a0 $0 $s1
    or   $a1 $0 $s4
    jal  suffix

    or   $s1 $0 $v0

    or   $a0 $0 $s2
    or   $a1 $0 $s4
    jal  suffix

    or   $s2 $0 $v0

    or   $a0 $0 $s1
    jal  length

    or   $s3 $0 $v0

    # Verify the suffixes are equal                        -> print 0
    jal  tab
    jal  space

    or   $a0 $0 $s1
    or   $a1 $0 $s2
    or   $a2 $0 $s3
    jal  strncmp

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall
    jal endl

    # Verify smaller strings are less than larger strings -> print -1
    jal tab

    addi $s4 $s3 -1

    add  $s5 $s1 $s4
    sb   $0 0($s5)

    or   $a0 $0 $s1
    or   $a1 $0 $s2
    or   $a2 $0 $s3
    jal  strncmp

    or   $a0 $0 $v0
    ori  $v0 $0 1
    syscall

  ori $v0 $0 10
  syscall

  ## Print a newline.
  # This can be called freely without concern of lost registers.
  .globl endl
  endl:
    addi $sp $sp -4
    sw   $a0 0($sp)
    addi $sp $sp -4
    sw   $v0 0($sp)

    ori $a0 $0 0xA
    ori $v0 $0 11
    syscall

    lw   $v0 0($sp)
    addi $sp $sp 4
    lw   $a0 0($sp)
    addi $sp $sp 4
  jr $ra

  ## Print a tab
  # This can be called freely without concern of lost registers.
  .globl tab
  tab:
    addi $sp $sp -4
    sw   $a0 0($sp)
    addi $sp $sp -4
    sw   $v0 0($sp)

    ori $a0 $0 0x9
    ori $v0 $0 11
    syscall

    lw   $v0 0($sp)
    addi $sp $sp 4
    lw   $a0 0($sp)
    addi $sp $sp 4
  jr $ra

  ## Print a space
  # This can be called freely without concern of lost registers.
  .globl space
  space:
    addi $sp $sp -4
    sw   $a0 0($sp)
    addi $sp $sp -4
    sw   $v0 0($sp)

    ori $a0 $0 0x20
    ori $v0 $0 11
    syscall

    lw   $v0 0($sp)
    addi $sp $sp 4
    lw   $a0 0($sp)
    addi $sp $sp 4
  jr $ra

