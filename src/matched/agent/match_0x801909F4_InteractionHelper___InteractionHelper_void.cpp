// 0x801909F4 InteractionHelper::~InteractionHelper(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 28,0x10(1); stw 0,0x24(1); stw 12,0xc(1); mr 29,3; mr 28,4; lwz 3,0x0(29); cmpwi 3,0; beq 5f; mr 30,3; 0:; lwz 11,0xc(30); cmpwi 4,30,0; cmpwi 11,0; beq 3f; 1:; lwz 31,0xc(11); cmpwi 11,0; beq 2f; lwz 9,0x18(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr. 11,31; bne 1b; 3:; lwz 31,0x4(30); beq cr4,4f; lwz 9,0x18(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; 4:; mr. 30,31; bne 0b; 5:; andi. 0,28,1; beq 6f; mr 3,29; bl _s801909F4_0; 6:; lwz 0,0x24(1); lwz 12,0xc(1); mtspr 8,0; lmw 28,0x10(1); mtcrf 8,12; addi 1,1,32"
extern "C" void _s801909F4_0();
extern "C" void f_801909F4() {}
