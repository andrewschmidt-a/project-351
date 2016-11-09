.section .exceptions.exit, "xa"
addi $r4, $r27, 0
call my_scheduler
addi $r27, $r2, 0

