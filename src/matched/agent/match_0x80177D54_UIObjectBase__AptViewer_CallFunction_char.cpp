// 0x80177D54 UIObjectBase::AptViewer_CallFunction(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 9,-32697; mr 0,4; mr 11,5; mr 10,6; mr 8,7; lwz 3,0x5e80(9); mr 4,30; mr 5,0; mr 6,11; mr 7,10; bl _s80177D54_0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80177D54_0();
extern "C" void f_80177D54() {}
