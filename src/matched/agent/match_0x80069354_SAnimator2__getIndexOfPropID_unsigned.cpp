// 0x80069354 SAnimator2::getIndexOfPropID(unsigned (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x168(3); li 10,0; lwz 0,0x16c(3); li 3,-1; mr 11,9; subf 0,9,0; srawi 8,0,2; cmpw 10,8; bgelr; lwz 9,0x0(11); lwz 0,0x0(9); cmpw 0,4; bne 0f; li 3,0; blr; 0:; addi 10,10,1; addi 11,11,4; cmpw 10,8; bgelr; lwz 9,0x0(11); lwz 0,0x0(9); cmpw 0,4; bne 0b; mr 3,10"
extern "C" int f_80069354() {}
