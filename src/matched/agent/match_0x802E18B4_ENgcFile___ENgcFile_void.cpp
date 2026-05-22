// 0x802E18B4 ENgcFile::~ENgcFile(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-23304; mr 30,4; stw 9,0x28(31); bl _s802E18B4_0; lwz 4,0x6c(31); bl _s802E18B4_1; mr 3,31; li 4,0; bl _s802E18B4_2; andi. 0,30,1; beq 0f; bl _s802E18B4_3; mr 4,31; bl _s802E18B4_4; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802E18B4_0();
extern "C" void _s802E18B4_1();
extern "C" void _s802E18B4_2();
extern "C" void _s802E18B4_3();
extern "C" void _s802E18B4_4();
extern "C" void f_802E18B4() {}
