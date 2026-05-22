// 0x802D7800 ESemaphore::~ESemaphore(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 0,0x4(31); addi 9,9,-23736; mr 30,4; stw 9,0x0(31); cmpwi 0,0; beq 0f; bl _s802D7800_0; 0:; mr 3,31; mr 4,30; bl _s802D7800_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D7800_0();
extern "C" void _s802D7800_1();
extern "C" void f_802D7800() {}
