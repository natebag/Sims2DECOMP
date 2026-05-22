// 0x801769E8 UI3D::~UI3D(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lis 9,-32698; lwz 0,0x0(30); addi 9,9,25904; mr 28,4; stw 9,0x1c(30); cmpwi 0,0; lwz 11,0x8(30); beq 0f; lwz 9,0x4(30); stw 11,0x4(9); lwz 11,0x8(30); lwz 0,0x4(30); stw 0,0x0(11); lwz 11,0x0(30); 0:; addi 29,30,12; 1:; lwz 31,0x4(11); cmpwi 11,0; beq 2f; lwz 9,0x24(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr. 11,31; bne 1b; lwz 0,-31488(13); cmpwi 0,0; bne 3f; li 3,16; bl _s801769E8_0; bl _s801769E8_1; stw 3,-31488(13); 3:; lwz 3,-31488(13); mr 4,29; bl _s801769E8_2; andi. 0,28,1; beq 4f; mr 3,30; bl _s801769E8_3; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801769E8_0();
extern "C" void _s801769E8_1();
extern "C" void _s801769E8_2();
extern "C" void _s801769E8_3();
extern "C" void f_801769E8() {}
