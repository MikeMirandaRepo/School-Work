# Example to reverse a string

# Fixes are described in comments like the below:
### FIX:
###   ...

.data

  string: .asciiz "deliver no evil" # length = 15
  ### Change 16 -> 15
  ###   In class I used 16 because we need to hold the null char
  ###  ('\0') to signify the end. However, if we account for that here
  ###  then  the last null byte in the original string will become the
  ###  first byte  of the reversed string.

.text

main:
  la  $s0 string  # s0 = string


  # Print out the original string
  or  $a0 $0 $s0
  ori $v0 $0   4
  syscall
  jal newline

  or   $a0 $0 $v0
  ori  $v0 $0   4

  before_print:
 	 syscall
  	 jal newline

  ori $v0 $0 10
syscall


newline:
  addi $sp $sp -4
  sw   $a0 0($sp)

    addi $sp $sp -4
    sw   $v0 0($sp)

      ori  $a0 $0 0xA
      ori  $v0 $0  11
      syscall

    lw   $v0 0($sp)
    addi $sp $sp  4

  lw   $a0 0($sp)
  addi $sp $sp  4
jr $ra

