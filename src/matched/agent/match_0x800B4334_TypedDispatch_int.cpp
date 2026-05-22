// 0x800B4334 TypedDispatch(int, (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); lwz 11,-32076(13); mr 27,3; mr 28,4; mr 29,5; li 30,0; cmpwi 11,0; beq 2f; cmpwi 4,6,0; 0:; lwz 0,0x4(11); lwz 31,0x0(11); cmpw 0,27; bne 1f; lwz 9,0xc(11); mr 4,28; mr 5,29; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; li 30,1; beq cr4,1f; li 3,1; b 3f; 1:; mr. 11,31; bne 0b; 2:; mr 3,30; 3:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"
extern "C" void f_800B4334() {}
