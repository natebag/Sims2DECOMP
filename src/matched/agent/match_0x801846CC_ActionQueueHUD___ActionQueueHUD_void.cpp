// 0x801846CC ActionQueueHUD::~ActionQueueHUD(void) (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,4; bl _s801846CC_0; addic. 0,30,344; beq 3f; addi 31,30,704; cmpw 0,31; beq 3f; mr 28,0; li 29,0; 0:; lwzu 0,-20(31); cmpwi 0,0; beq 1f; bl _s801846CC_1; lwz 4,0x0(31); bl _s801846CC_2; stw 29,0x0(31); 1:; lwz 3,0x8(31); cmpwi 3,0; beq 2f; bl _s801846CC_3; stw 29,0x8(31); 2:; cmpw 28,31; bne 0b; 3:; addic. 0,30,156; mr 29,0; beq 7f; addi 31,30,336; cmpw 29,31; beq 7f; li 28,0; 4:; lwzu 0,-20(31); cmpwi 0,0; beq 5f; bl _s801846CC_4; lwz 4,0x0(31); bl _s801846CC_5; stw 28,0x0(31); 5:; lwz 3,0x8(31); cmpwi 3,0; beq 6f; bl _s801846CC_6; stw 28,0x8(31); 6:; cmpw 29,31; bne 4b; 7:; andi. 0,27,1; beq 8f; mr 3,30; bl _s801846CC_7; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801846CC_0();
extern "C" void _s801846CC_1();
extern "C" void _s801846CC_2();
extern "C" void _s801846CC_3();
extern "C" void _s801846CC_4();
extern "C" void _s801846CC_5();
extern "C" void _s801846CC_6();
extern "C" void _s801846CC_7();
extern "C" void f_801846CC() {}
