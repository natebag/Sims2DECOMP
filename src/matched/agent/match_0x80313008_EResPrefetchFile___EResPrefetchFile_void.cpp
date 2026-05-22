// 0x80313008 EResPrefetchFile::~EResPrefetchFile(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; li 0,0; mr 30,4; addi 9,9,-19640; stw 0,0x40(31); stw 0,0x30(31); stw 0,0x2c(31); li 4,0; stw 0,0x34(31); stw 0,0x38(31); stw 0,0x3c(31); stw 9,0x28(31); bl _s80313008_0; andi. 0,30,1; beq 0f; bl _s80313008_1; mr 4,31; bl _s80313008_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80313008_0();
extern "C" void _s80313008_1();
extern "C" void _s80313008_2();
extern "C" void f_80313008() {}
