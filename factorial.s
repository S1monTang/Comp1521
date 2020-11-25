# Recursive factorial function
# n < 1 yields n! = 1
# $s0 is used for n
# we use an s register because the convention is their value
# is preserved across function calls
# f is in $t0

# DO NOT CHANGE THE CODE IN MAIN
#z5212799
#Siyuan Tang

main:
    addi $sp, $sp, -8  # create stack frame
    sw   $ra, 4($sp)   # save return address
    sw   $s0, 0($sp)   # save $s0

    li   $s0, 0
    la   $a0, msg1
    li   $v0, 4
    syscall            # printf(Enter n: ")

    li    $v0, 5
    syscall            # scanf("%d", &n)
    move  $s0, $v0

    move  $a0, $s0     # factorial(n)
    jal   factorial    #
    move  $t0, $v0     #

    move  $a0, $s0
    li    $v0, 1
    syscall            # printf ("%d", n)

    la    $a0, msg2
    li    $v0, 4
    syscall            # printf("! = ")

    move  $a0, $t0
    li    $v0, 1
    syscall            # printf ("%d", f)

    li   $a0, '\n'     # printf("%c", '\n');
    li   $v0, 11
    syscall

                       # clean up stack frame
    lw   $s0, 0($sp)   # restore $s0
    lw   $ra, 4($sp)   # restore $ra
    addi $sp, $sp, 8   # restore sp

    li  $v0, 0         # return 0
    jr  $ra

    .data
msg1:   .asciiz "Enter n: "
msg2:   .asciiz "! = "


# DO NOT CHANGE CODE ABOVE HERE


    .text
factorial:
    #  ADD CODE TO CREATE STACK FRAME
    sw $fp, -4($sp)
    addi $fp, $sp, -4
    sw $ra, -4($fp)
    sw $s0, -8($fp)
    la $sp, -8($fp)

    # ADD CODE FORFUNCTION HERE
    li $t0, 1
    bgt $a0, $t1, recur 
    li $v0, 1
    j end


    recur:
        move $s0, $a0,
        addi $a0, $a0, -1
        jal factorial
        mul $v0, $s0, $v0
        

    # ADD CODE TO REMOVE STACK FRAME
    end:
        lw $s0, -8($fp)
        lw $ra, -4($fp)
        addi $sp, $sp, 12
        lw $fp, ($fp)
        jr  $ra
