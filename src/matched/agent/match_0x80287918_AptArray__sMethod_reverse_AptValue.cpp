// 0x80287918 AptArray::sMethod_reverse(AptValue (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 2f; lwz 0,0x2c(3); li 8,0; rlwinm 9,0,1,31,31; add 0,0,9; srawi. 9,0,1; blelr; li 7,0; 1:; lwz 9,0x2c(3); lwz 11,0x24(3); subf 9,8,9; rlwinm 9,9,2,0,29; lwzx 10,7,11; add 9,9,11; lwz 0,-4(9); stwx 0,7,11; addi 7,7,4; lwz 9,0x2c(3); lwz 0,0x24(3); subf 9,8,9; rlwinm 9,9,2,0,29; addi 8,8,1; add 9,9,0; stw 10,-4(9); lwz 0,0x2c(3); rlwinm 9,0,1,31,31; add 0,0,9; srawi 0,0,1; cmpw 8,0; blt 1b; blr; 2:; lwz 3,-22936(13)"
extern "C" void f_80287918() {}
