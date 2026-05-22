// 0x80325688 EResourceManager::~EResourceManager(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 0,0x48(31); addi 9,9,-17096; mr 30,4; stw 9,0xd1c(31); cmpwi 0,0; beq 0f; bl _s80325688_0; 0:; addi 3,31,3336; li 4,2; bl _s80325688_1; addi 3,31,88; li 4,2; bl _s80325688_2; lwz 4,0x44(31); addi 3,31,68; bl _s80325688_3; lis 9,-32697; addi 3,31,28; addi 9,9,-24248; li 4,2; stw 9,0x0(31); bl _s80325688_4; mr 3,31; li 4,2; bl _s80325688_5; andi. 0,30,1; beq 1f; mr 3,31; bl _s80325688_6; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80325688_0();
extern "C" void _s80325688_1();
extern "C" void _s80325688_2();
extern "C" void _s80325688_3();
extern "C" void _s80325688_4();
extern "C" void _s80325688_5();
extern "C" void _s80325688_6();
extern "C" void f_80325688() {}
