
# HW1 Driver
# 2018 Michael Miranda
# All of your functions should be placed between the comments below


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

