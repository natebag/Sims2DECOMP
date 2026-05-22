// 0x8032E04C ENgcEngine::ENgcEngine(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s8032E04C_0; lis 9,-32697; li 3,1; addi 9,9,-15336; stw 9,0x0(30); stw 30,-26512(13); bl _s8032E04C_1; li 0,0; mr 3,30; stw 0,0x50(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032E04C_0();
extern "C" void _s8032E04C_1();
extern "C" void f_8032E04C() {}
