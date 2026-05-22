// 0x80125FE8 cXPersonImpl::HasQueuedActionOfPri(int) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x534(3); li 9,0; cmpwi 0,0; beq 0f; li 9,1; 0:; addi 3,3,304; mr 11,9; lwz 9,0x2a8(3); lwz 0,0x2ac(3); subf 0,9,0; cmplw 11,0; bge 3f; lis 10,-13108; mr 7,9; mr 8,0; ori 10,10,52429; 1:; add 9,7,11; mulhwu 0,9,10; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 9,3,9; lwz 0,0x28(9); cmpw 0,4; bne 2f; li 3,1; blr; 2:; addi 11,11,1; cmplw 11,8; blt 1b; 3:; li 3,0"
extern "C" int f_80125FE8() {}
