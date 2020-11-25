# Sieve of Eratosthenes
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
main:

    # PUT YOUR CODE


    li $t0, 0
    li $t1, 1000
    la $t2, prime
    loop1:
        bge $t0, $t1, end_1
        add $t4, $t2, $t0
        sb  $t3, ($t4)
        addi $t0, $t0, 1
        j loop1

    end_1:
        li $t0, 2
        

    loop2:
        add $t4, $t2, $t0
        lb $t5, ($t4)
        beq $t5, $0, add_function
        move $a0, $t0
        li $v0, 1
        syscall
        
        move $a0, '\n'
        li $v0, 1
        syscall

        li $t6, 2
        mul $t6, $t6, $t0
    loop3:
        bge $t6, $t1, end_3
        add $t4, $t2, $t0
        sb $0, ($t4)
        add $t6, $t6, $0
        j loop3

    end_3:
    add_function:
        add $t0, $t0, 1
        j loop2

    end_2:
    
    li $v0, 0           # return 0
    jr $31

.data
prime:
    .space 1000
