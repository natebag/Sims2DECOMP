// 0x8026C094 AptSavedInputCheckpoints::~AptSavedInputCheckpoints(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; lwz 30,0x8(29); addi 0,29,12; cmpw 30,0; beq 3f; cmpwi 30,0; bne 0f; li 3,8; bl _s8026C094_0; stw 30,0x0(3); b 3f; 0:; lwz 0,-8(30); addi 28,30,-8; rlwinm 0,0,3,0,28; add 31,30,0; cmpw 30,31; beq 2f; 1:; addi 31,31,-8; li 4,2; mr 3,31; bl _s8026C094_1; cmpw 30,31; bne 1b; 2:; mr 3,28; bl _s8026C094_2; 3:; addic. 0,29,12; mr 30,0; beq 5f; addi 31,29,28; cmpw 30,31; beq 5f; 4:; addi 31,31,-8; li 4,2; mr 3,31; bl _s8026C094_3; cmpw 30,31; bne 4b; 5:; andi. 0,27,1; beq 6f; lwz 3,-23020(13); mr 4,29; li 5,28; bl _s8026C094_4; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8026C094_0();
extern "C" void _s8026C094_1();
extern "C" void _s8026C094_2();
extern "C" void _s8026C094_3();
extern "C" void _s8026C094_4();
extern "C" void f_8026C094() {}
