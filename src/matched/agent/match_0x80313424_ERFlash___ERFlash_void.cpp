// 0x80313424 ERFlash::~ERFlash(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-19544; mr 30,4; stw 9,0x0(31); bl _s80313424_0; mr 3,31; li 4,0; bl _s80313424_1; andi. 0,30,1; beq 0f; lis 3,-32693; mr 4,31; addi 3,3,31260; bl _s80313424_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80313424_0();
extern "C" void _s80313424_1();
extern "C" void _s80313424_2();
extern "C" void f_80313424() {}
