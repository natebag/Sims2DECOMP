// 0x801771D8 UIAUDIO::~UIAUDIO(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; lis 9,-32698; lwz 0,0x0(30); addi 9,9,25952; mr 26,4; stw 9,0x74(30); cmpwi 0,0; lwz 11,0x8(30); beq 0f; lwz 9,0x4(30); stw 11,0x4(9); lwz 11,0x8(30); lwz 0,0x4(30); stw 0,0x0(11); lwz 11,0x0(30); 0:; addi 28,30,16; 1:; lwz 31,0x4(11); cmpwi 11,0; beq 2f; lwz 9,0x14(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr. 11,31; bne 1b; li 29,0; li 27,0; li 31,0; 3:; lwzx 0,31,28; cmpwi 0,0; beq 4f; mr 3,30; mr 4,29; bl _s801771D8_0; lwz 3,-26564(13); lwzx 4,31,28; lwz 9,0x0(3); lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; stwx 27,31,28; 4:; addi 29,29,1; addi 31,31,4; cmpwi 29,4; ble 3b; andi. 0,26,1; beq 5f; mr 3,30; bl _s801771D8_1; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s801771D8_0();
extern "C" void _s801771D8_1();
extern "C" void f_801771D8() {}
