// 0x803C7618 ENgcDL::~ENgcDL(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; mr 30,4; addi 9,9,-15152; stw 9,0x64(31); li 4,0; bl _s803C7618_0; andi. 0,30,1; beq 0f; mr 3,31; bl _s803C7618_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803C7618_0();
extern "C" void _s803C7618_1();
extern "C" void f_803C7618() {}
