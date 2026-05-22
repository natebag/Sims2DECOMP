// 0x8032B818 ENgcAudio::~ENgcAudio(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 30,3; addi 9,9,-16304; mr 29,4; stw 9,0x0(30); addi 3,30,92; li 4,2; bl _s8032B818_0; addi 3,30,64; li 4,2; bl _s8032B818_1; mr 3,30; mr 4,29; bl _s8032B818_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8032B818_0();
extern "C" void _s8032B818_1();
extern "C" void _s8032B818_2();
extern "C" void f_8032B818() {}
