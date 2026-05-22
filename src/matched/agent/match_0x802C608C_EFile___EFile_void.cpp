// 0x802C608C EFile::~EFile(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-24472; mr 30,4; stw 9,0x28(31); bl _s802C608C_0; lwz 4,0x1c(31); bl _s802C608C_1; bl _s802C608C_2; lwz 4,0x20(31); bl _s802C608C_3; li 0,0; andi. 9,30,1; stw 0,0x20(31); stw 0,0x1c(31); beq 0f; bl _s802C608C_4; mr 4,31; bl _s802C608C_5; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C608C_0();
extern "C" void _s802C608C_1();
extern "C" void _s802C608C_2();
extern "C" void _s802C608C_3();
extern "C" void _s802C608C_4();
extern "C" void _s802C608C_5();
extern "C" void f_802C608C() {}
