// 0x800484B4 EIFloor::~EIFloor(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,-18488; mr 30,4; stw 9,0x0(31); bl _s800484B4_0; mr 3,31; li 4,0; bl _s800484B4_1; andi. 0,30,1; beq 0f; mr 3,31; bl _s800484B4_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800484B4_0();
extern "C" void _s800484B4_1();
extern "C" void _s800484B4_2();
extern "C" void f_800484B4() {}
