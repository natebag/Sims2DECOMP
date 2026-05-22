// 0x802481D4 _sn_sinit (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lis 9,-32731; addi 9,9,-31516; li 0,1; addi 29,30,484; stw 9,0x3c(30); stw 0,0x38(30); mr 3,29; li 4,4; li 5,0; mr 6,30; bl _s802481D4_0; addi 3,30,580; li 4,9; li 5,1; mr 6,30; bl _s802481D4_1; addi 3,30,676; li 4,10; li 5,2; mr 6,30; bl _s802481D4_2; lis 8,-32694; li 10,3; addi 11,8,-24956; stw 10,0x1dc(30); stw 29,0x1e0(30); lis 9,-32694; stw 11,0x1d8(30); li 0,0; stw 0,-24956(8); addi 9,9,-25916; li 10,10; stw 9,0x8(11); stw 10,0x4(11); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802481D4_0();
extern "C" void _s802481D4_1();
extern "C" void _s802481D4_2();
extern "C" void f_802481D4() {}
