// 0x8000DFF8 AptLine::Draw(ERC (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 30,0x4(3); mr 27,4; mr 28,5; mr 29,6; mr 31,7; cmpwi 30,0; beq 1f; 0:; lwz 9,0x2c(30); mr 4,27; mr 5,28; mr 6,29; lha 3,0x10(9); mr 7,31; lwz 0,0x14(9); add 3,30,3; mtspr 8,0; lwz 30,0x0(30); blrl; mr. 30,30; bne 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_8000DFF8() {}
