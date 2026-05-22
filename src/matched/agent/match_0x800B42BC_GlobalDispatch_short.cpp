// 0x800B42BC GlobalDispatch(short, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,-32076(13); mr 28,3; mr 29,4; li 30,0; cmpwi 11,0; beq 2f; 0:; lwz 9,0xc(11); mr 4,28; mr 5,29; lwz 31,0x0(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; li 30,1; 1:; mr. 11,31; bne 0b; 2:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_800B42BC() {}
