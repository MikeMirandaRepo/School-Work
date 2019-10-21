# 2018 Daniel Pade
# Example to reverse a string

# Fixes are described in comments like the below:
### FIX:
###   ...

.data

  string: .asciiz "deliver no evil" # length = 15
  length: .word                  15
  ### Change 16 -> 15
  ###   In class I used 16 because we need to hold the null char
  ###  ('\0') to signify the end. However, if we account for that here
  ###  then  the last null byte in the original string will become the
  ###  first byte  of the reversed string.

.text

main:
  la  $s0 string  # s0 = string
  la  $s1 length
  lw  $s1 0($s1)  # s1 = string.length

  # Print out the original string
  or  $a0 $0 $s0
  ori $v0 $0   4
  syscall
  jal newline

  or  $a0 $0 $s0
  or  $a1 $0 $s1
  jal reverse

  ### Remove addi instruction
  ###   The addi was a `quickfix' so we could verify the result is
  ###   correct
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


## Reverses a string.
#
# @param a0 (addr) The string to reverse
# @param a1 (uint) The length of the string
#
# @return (addr) The reversed string.
#
reverse:
  # str = "deliver no evil"
  # emp = malloc(sizeof(str))
  # for (i = 0; i < str.length; i++) {
  #   emp[len - i - 1] = str[i];
  # }

  or  $t0 $0 $a0  # t0 = str
  or  $t1 $0 $a1  # t1 = str.length

  # Allocate space for new string

  or   $a0 $0 $a1
  addi $a0 $a0 1
  ### New addi instruction
  ###   This is where we account for the null byte at the end.
  ori $v0 $0   9
  syscall
  or  $t2 $0 $v0   # t2 = emp malloc(..)
  ### Insert null byte
  ###   We manually insert the null byte at the end of the string.
  add  $v0 $v0 $t1
  sb   $0 0($v0)

  allocation:

  or  $t3 $0 $0    # t3 = i

  reverse_loop:
  # Check if i >= str.length
  sltu $t4 $t3 $t1  # t4 = if i >= str.length
                    #      then 0
                    #      else 1
  beq $t4 $0 reverse_after_loop
  #   emp[len - i - 1] = str[i];

  # |<-8->|
  # |-----|-----|-----|
  # |     |     |     |
  # |-----|-----|-----|
  # str[i] = addr(str) + i

  add $t5 $t0 $t3
  lb  $t5 0($t5)    # t5 = str[i]

  addi $t6 $t1 -1
  subu $t6 $t6 $t3  # t6 = len - i - 1
  add  $t6 $t2 $t6  # t6 = addr(emp[len-i-1])

  sb   $t5 0($t6)

  addi $t3 $t3 1
  j reverse_loop

  reverse_after_loop:
  or $v0 $0 $t2     # return t2
jr $ra # <<< Actually return

#  ^  cond not true
# | \----
# | |   |
# |/    |
#       v