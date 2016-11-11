
.section .exceptions.exit.user, "xa"
addi r4, sp, 0
call my_scheduler
addi sp, r2, 0
