// 0x80110674 ObjSelector::IsPreloaded(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; li 28,0; lwz 0,0xa0(29); cmpwi 0,1; beq 0f; addi 9,29,28; lwz 11,0x1c(9); lwz 0,0xc0(11); cmpwi 0,0; bne 1f; 0:; li 28,1; addi 9,29,28; 1:; lwz 9,0x1c(9); lwz 0,0xc0(9); cmpwi 0,0; bne 5f; lwz 30,-21508(13); li 4,0; lha 27,0x14(9); lwz 9,0x0(30); b 4f; 2:; lwz 9,0x38(31); lha 0,0x14(9); cmpw 0,27; bne 3f; lwz 0,0xc0(9); cmpwi 0,0; beq 3f; mr 3,31; mr 4,29; bl _s80110674_0; cmpwi 3,0; beq 3f; lwz 0,0xa0(31); cmpwi 0,1; beq 3f; li 28,0; 3:; lwz 9,0x0(30); mr 4,31; 4:; lha 3,0x70(9); lwz 0,0x74(9); add 3,30,3; mtspr 8,0; blrl; mr. 31,3; bne 2b; 5:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80110674_0();
extern "C" void f_80110674() {}
