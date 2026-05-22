// 0x800677B0 SAnimator2::PropsHaveAlpha(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x168(3); li 10,0; lwz 0,0x16c(3); subf 0,9,0; srawi 0,0,2; cmpw 10,0; bge 4f; mtspr 9,0; mr 11,9; 0:; lwz 9,0x0(11); addi 11,11,4; lwz 9,0x8(9); cmpwi 9,0; beq 3f; cmpwi 10,0; li 10,1; bne 1f; li 10,0; 1:; lwz 0,0x100(9); li 3,1; cmpwi 0,0; bne 2f; li 3,0; 2:; or 10,10,3; 3:; bdnz 0b; 4:; mr 3,10"
extern "C" int f_800677B0() {}
