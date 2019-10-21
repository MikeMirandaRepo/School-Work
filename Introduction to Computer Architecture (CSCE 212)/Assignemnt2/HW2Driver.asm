# HW2 Driver
# All of your functions should be placed between the comments below
.data
	str: .asciiz "A"
.text
  j main

  ## Prepends a number to a list
  #
  # @param $a1 The list.
  # @param $a0 The element to prepend
  #
  # @return the new list [$a0] + $a1
  #
  ######################################
  prepend:                             #
  addi $sp $sp  -4                     # Node(num : int):
    sw   $ra  0($sp)                   #
                                       #
    jal  Node                          #
    sw   $a0 0($v0)
    sw   $a1 4($v0)
                    
    lw   $ra  0($sp)                   #
    addi $sp $sp   4                   #
  jr $ra                              ##


  ## Gives the length of a linked list.
  #
  # @param $a0 The list.
  #
  # @return The length of the list.
  #
  ######################################
  .globl length                        #
  length:                              #
                                       # length_recurse(list, len):
addi $sp $sp -4		#saving used variables
   sw $t0 0($sp)
addi $sp $sp -4
   sw $t1 0($sp)
addi $sp $sp -4
   sw $t2 0($sp)


   or $t0 $0 $a0		#t0 is the list head   
   ori $t2 $0 0       #t2 (counter) is 0
   j loop_length
  

  loop_length:
  lw $t1 4($t0)		#t1 is the current.next

  beq $t1 $0 end_loop_length  #if the current.next is null then end loop
  addi $t2 $t2 1   #else, increments counter
  lw $t0 4($t0)    #increments current node placement
  j loop_length	   #jump back to loop


  end_loop_length:
   addi $t2 $t2 1	#increment a1 to account for first node
   or $v0 $0 $t2		#return value of length to v0
  lw $t2 0($sp)	        #returning prev values
    addi $sp $sp 4
  lw $t1 0($sp)	        #returning prev values
    addi $sp $sp 4
  lw $t0 0($sp)
    addi $sp $sp 4
  jr $ra


  ## Drops the first x elements from the list
  #
  # @param $a0 The list.
  # @param $a1 The number of elements to drop.
  #
  ######################################
  drop: 
addi $sp $sp -4		#saving used variables
   sw $t0 0($sp)
addi $sp $sp -4
   sw $t2 0($sp)


   or $t0 $0 $a0		#t0 is the list head   
   ori $t2 $0 1      #t2 (counter) is 0
   j drop_loop
  

  drop_loop:
    beq $t2 $a1 end_drop_loop	#if the current.next is null then end loop
  addi $t2 $t2 1   #else, increments counter
  lw $t0 4($t0)    #increments current node placement
  j drop_loop	   #jump back to loop   


  end_drop_loop:
      or $v0 $0 $t0		#return changed list to v0
  lw $t2 0($sp)	        #returning prev values
    addi $sp $sp 4
  lw $t0 0($sp)
    addi $sp $sp 4

  jr $ra                              ##


  ## Inserts an element into a given list at a given index (other
  # than the head).
  #
  #   This function cannot replace the head of the list, i.e. it
  # does not consider 0 a valid index.
  #
  # @param ($a0 : Node) The list to insert into.
  # @param ($a1 : Node) The node to insert.
  # @param ($a2 : num+) The index at which to insert.
  #
  ######################################
  .globl insert                        #
  insert:   
addi $sp $sp -4		#saving used variables
   sw $t0 0($sp)
addi $sp $sp -4
   sw $t1($sp)
addi $sp $sp -4
   sw $t2 0($sp)


   or $t0 $0 $a0		#t0 is the list head   
   ori $t2 $0 1      #t2 (counter) is 0
   j insert_loop
  

  insert_loop:
  lw $t1 4($t0)
  beq $t2 $a2 end_insert_loop  #if the current.next is null then end loop
  addi $t2 $t2 1   #else, increments counter
  lw $t0 4($t0)    #increments current node placement
  j insert_loop	   #jump back to loop   


  end_insert_loop:
  #sw $t0 0($a1)
  #sw $a1 0($t1)   I honestly have no idea about what to do here


  lw $t2 0($sp)	        #returning prev values
    addi $sp $sp 4
lw $t1($sp)
    addi $sp $sp 4
  lw $t0 0($sp)
    addi $sp $sp 4

                           
  jr $ra                            

  ## Reverses a list (destructively!)
  #
  # @param $a0 The list.
  #
  # @return the pointer to the first (formerly last) element.
  #
  ######################################
  reverse:                             #
  jr $ra                              ##

  #------------------ DON'T MODIFY BELOW ---------------------------

  ## Entry point.
  #
  ######################################
  .globl main                          #
  main:                                #
                                       #
    # Create 10 nodes in reverse       #
    # reverse order                    #
    ori  $a0  $0  10                   # Build the list [1..10]
    jal  Node_num                      # .
                                       # .
    ori  $a0  $0   9                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   8                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   7                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   6                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   5                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   4                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   3                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   2                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
                                       # .
    ori  $a0  $0   1                   # .
    or   $a1  $0 $v0                   # .
    jal  prepend                       # .
    or   $s0  $0 $v0                   # [list := $s0] = [1..10]
                                       #
    addi $a0  $0  -1                   # [node := $s1] = new Node(-1)
    jal  Node_num                      # .
    or   $s1  $0 $v0                   # .
                                       #
    or   $a0  $0 $s0                   # print(length(list))
    jal  length                        # .
    or   $a0  $0 $v0                   # .
    ori  $v0  $0   1                   # .
    syscall                            # .
    ori  $t9  $0  10                   # .
    jal chr                            # .
                                       #
    or   $a0  $0 $s0                   # insert(list, node, 2)
    or   $a1  $0 $s1                   # .
    ori  $a2  $0   1                   # .
    jal  insert                        # .
                                       #
    or   $a0  $0 $s0                   # print(drop(list.next, 2))
    ori  $a1  $0   2                   # .
    jal  drop                          # .
    or   $a0  $0 $v0                   # .
    jal  print_list                    # .
    ori  $t9  $0 10                    # .
    jal  chr                           # .
                                       #
    or   $a0  $0 $s0                   # Print the original list (before drop)
    jal print_list                     # .
    ori  $t9  $0 10                    # .
    jal  chr                           # .
                                       #
    or   $a0  $0 $s0                   # print(reverse(list))
    jal reverse                        # .
    jal print_list                     # .
    or   $a0 $0 $v0                    # .
    ori  $t9  $0 10                    # .
    jal  chr                           # .
                                       #
  ori  $v0 $0  10                      #
  syscall                             ##


  ## Prints a list.
  #
  # @param ($a0 : Node) The list to print.
  #
  ######################################
  .globl print_list                    #
  print_list:                          #
    addi $sp $sp  -4                   # print_list(list):
    sw   $ra  0($sp)                   #
                                       #
    ori  $t9  $0  91                   # print('[')
    jal  chr                           # .
    jal  print_list_recurse            # print_list_recurse(list)
    ori  $t9  $0  93                   # print(']')
    jal  chr                           # .
    lw   $ra  0($sp)                   #
    addi $sp $sp   4                   #
  jr $ra                              ##


  ## The inner recursive portion of printing a list.
  #
  # @param ($a0 : Node) The list to print.
  #
  ######################################
  .globl print_list_recurse            #
  print_list_recurse:                  #
    addi $sp $sp  -4                   # print_list_recurse(list):
    sw   $ra 0 ($sp)                   #
                                       # [val := $t0, next := $t1]
    lw   $t0  0($a0)                   # val  = list.val
    lw   $t1  4($a0)                   # next = list.next
                                       #
    or   $a0  $0 $t0                   # print(val)
    ori  $v0  $0   1                   # .
    syscall                            # .
                                       #
    bne $t1 $0 print_list__w_tail      # if next is NULL:
      j    print_recurse__end          #   return
    print_list__w_tail:                # else:
      ori  $t9  $0 44                  #   print(", ")
      jal  chr                         #   .
      ori  $t9  $0 32                  #   .
      jal  chr                         #   .
      or   $a0  $0 $t1                 #   print_list(next)
      jal  print_list_recurse          #   .
                                       #
  print_recurse__end:                  #
    lw   $ra 0 ($sp)                   #
    addi $sp $sp   4                   #
  jr $ra                              ##


  ## Constructs a (guaranteed) empty Node object.
  #
  #   A Node contains an int and a ptr, so we ask for 2 words (8
  # bytes) and zero them out.
  #
  # @return A pointer to an empty Node.
  #
  ######################################
  .globl Node                          #
  Node:                                #
    addi $sp $sp  -4                   # Node():
    sw   $a0  0($sp)                   #
                                       #
    ori  $a0  $0   8                   # Get the bytes
    ori  $v0  $0   9                   #
    syscall                            #
                                       #
    sw    $0  0($v0)                   # Zero them
    sw    $0  4($v0)                   #
                                       #
    lw   $a0  0($sp)                   #
    addi $sp $sp   4                   #
  jr $ra                              ##


  ## Constructs a Node with the given value.
  #
  # @param $a0 The value to store
  #
  # @return A pointer to a Node containing the value, and null for
  #         its `next' pointer.
  #
  ######################################
  .globl Node_num                      #
  Node_num:                            #
    addi $sp $sp  -4                   # Node(num : int):
    sw   $ra  0($sp)                   #
                                       #
    jal  Node                          #
    sw   $a0 0($v0)                    #
                                       #
    lw   $ra  0($sp)                   #
    addi $sp $sp   4                   #
  jr $ra                              ##


  ## Print a character
  #
  #   This function takes its argument in $t9 in order to preserve as
  # many `useful' registers for the callee as possible.
  #
  # @param $t9 The ASCII code of the character to print.
  #
  ######################################
  .globl chr                           #
  chr:                                 #
    addi $sp $sp  -4                   # chr($t9=char):
    sw   $a0  0($sp)                   #
    addi $sp $sp  -4                   #
    sw   $v0  0($sp)                   #
                                       #
    or   $a0  $0 $t9                   #
    ori  $v0  $0  11                   #
    syscall                            #
                                       #
    lw   $v0  0($sp)                   #
    addi $sp $sp  4                    #
    lw   $a0  0($sp)                   #
    addi $sp $sp  4                    #
  jr $ra                              ##
