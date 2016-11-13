
.section .exceptions.exit.user, "xa"
call check_interrupt
beq r0, r2, GOTO
addi r4, sp, 0
call my_scheduler
addi sp, r2,0
#ldw ea, 72(sp)
#stw ea, 0(sp)
GOTO:
