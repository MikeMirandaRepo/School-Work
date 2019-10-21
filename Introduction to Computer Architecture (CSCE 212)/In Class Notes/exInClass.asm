# in class example
.data
        string: .asciiz "deliver no evil" #length = 15, so 16 with the end string character
        length: .word 16
.text
        main:
                la $s0 string #s0 = string
                la $s1 length #s1 now contains the address of length 
                lw $s1 0($s1) #loads the value of length into s1 

                #Print out the original string
                or $a0 $0 $s0 #or loads something from a register
                ori $v0 $0  4 #ori loads an immediate value (a number, char, hexadecimal)
                syscall #prints out the original string
                jal newline #jumps and links to the newline function

                or $a0 $0 $s0
                or $a1 $0 $s1
                jal reverse

                addi $v0 $v0 1 #quick and dirty workaround for it hitting the 0 character at the end of the string
                or $a0 $0 $v0
                ori $v0 $0 4
                syscall
                jal newline

                ori $v0 $0 10
                syscall  #ends the program 

        newline:
                addi $sp $sp -4
                sw $a0 0($sp)
                addi $sp $sp -4
                sw $v0 0($sp)
           
	ori $a0 $0 0xA #A is the ASCII character for a new line
                ori $v0 $0 11
                syscall

                lw $v0 0($sp)
                addi $sp $sp 4
                lw $a0 0($sp)
                addi $sp $sp 4

                jr $ra

        ## Reverses a string
        # @param a0 (addr) of the string to reverse
        # @param a1 (unsigned int) The length of the string     
        # @return (addr) the reversed string
        reverse:
                # str = "deliver no evil" 
                # emp = malloc(sizeof(str))
                # for(int i=0;i<str.length;i++) {
                # emp[len -i -1] = str[i]; }
                or $t0 $0 $a0 #t0 = str
                or $t1 $0 $a1 #t1 = length
                #allocate space for the new string
                or $a0 $0 $a1
		ori $v0 $0 9
                syscall
                or $t2 $0 $v0 #t2 = malloc(...)

                or $t3 $0 $0 #t3 = i 

                #check if i >= str.length
                .globl reverse_loop
                reverse_loop:
                        sltu $t4 $t3 $t1 # if i >= str.length then t3 = 0, else  t3 = 1
                        beq $t4 $0 reverse_after_loop

                        add $t5 $t0 $t3 #adds i to the string address. t5 = addr(str[i]) 
                        lb $t5 0($t5) # t5 = str[i]

                        addiu $t6 $t1 -1
                        subu $t6 $t6 $t3 # t6 = length - i -1 
                        add $t6 $t2 $t6 # t6 = addr(emp[length - i -1])

                        sb $t5 0($t6) #store byte, stores 


                        addi $t3 $t3 1 #increase t3 (i) by 1 
                        j reverse_loop
                reverse_after_loop:
                        or $v0 $0 $t2   #return t2      
                jr $ra #actually return

