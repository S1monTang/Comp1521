# read a mark and print the corresponding UNSW grade

main:
    la   $a0, prompt    # printf("Enter a mark: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", mark);
    syscall

    move $t0 , $v0

    blt $t0 , 50 , fail
    blt $t0 , 65 , pass
    blt $t0 , 75 , credit
    blt $t0 , 85 , dist
    

    la   $a0, hd        # printf("FL\n");
    j printout

    fail:
        la   $a0, fl
        j printout
    pass:
       la   $a0, ps
       j printout
    credit:
        la   $a0, cr
        j printout
    dist:
        la   $a0, dn
        j printout
        

    printout:

    li   $v0, 4
    syscall


    jr   $ra            # return

    .data
prompt:
    .asciiz "Enter a mark: "
fl:
    .asciiz "FL\n"
ps:
    .asciiz "PS\n"
cr:
    .asciiz "CR\n"
dn:
    .asciiz "DN\n"
hd:
    .asciiz "HD\n"
