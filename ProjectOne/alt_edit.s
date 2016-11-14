.section .exceptions.exit.user, "xa"
call check_interrupt
beq r0, r2, GOTO
stw  fp, -4(sp)
addi r4, sp, 0
call my_scheduler
addi sp, r2,0
ldw  fp, -4(sp)
GOTO:
