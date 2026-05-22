// 0x8026BF54 AptLinker::~AptLinker(void) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 26,4; addi 28,29,4; addi 0,29,16; lwz 30,0x8(28); cmpw 30,0; beq 3f; cmpwi 30,0; bne 0f; li 3,8; bl _s8026BF54_0; stw 30,0x0(3); b 3f; 0:; lwz 0,-8(30); addi 27,30,-8; rlwinm 0,0,2,0,29; add 31,30,0; 1:; cmpw 30,31; beq 2f; lwzu 3,-4(31); cmpwi 3,0; beq 1b; bl _s8026BF54_1; cmpwi 3,0; bne 1b; lwz 3,0x0(31); bl _s8026BF54_2; b 1b; 2:; mr 3,27; bl _s8026BF54_3; 3:; addic. 0,28,12; mr 30,0; beq 7f; addi 31,28,20; 4:; cmpw 30,31; beq 7f; lwzu 3,-4(31); cmpwi 3,0; beq 4b; bl _s8026BF54_4; cmpwi 3,0; bne 4b; lwz 3,0x0(31); bl _s8026BF54_5; b 4b; 5:; lwz 31,0x0(29); cmpwi 31,0; beq 7f; lwz 3,0x0(31); lwz 30,0x4(31); cmpwi 3,0; beq 6f; bl _s8026BF54_6; cmpwi 3,0; bne 6f; lwz 3,0x0(31); bl _s8026BF54_7; 6:; lwz 3,-23020(13); mr 4,31; li 5,8; bl _s8026BF54_8; stw 30,0x0(29); 7:; lwz 0,0x0(29); cmpwi 0,0; bne 5b; andi. 0,26,1; beq 8f; lwz 3,-23020(13); mr 4,29; li 5,24; bl _s8026BF54_9; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8026BF54_0();
extern "C" void _s8026BF54_1();
extern "C" void _s8026BF54_2();
extern "C" void _s8026BF54_3();
extern "C" void _s8026BF54_4();
extern "C" void _s8026BF54_5();
extern "C" void _s8026BF54_6();
extern "C" void _s8026BF54_7();
extern "C" void _s8026BF54_8();
extern "C" void _s8026BF54_9();
extern "C" void f_8026BF54() {}
