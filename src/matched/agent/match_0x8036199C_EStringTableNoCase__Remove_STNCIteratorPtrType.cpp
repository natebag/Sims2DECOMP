// 0x8036199C EStringTableNoCase::Remove(STNCIteratorPtrType (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 4,0xc(30); bl _s8036199C_0; mr 4,3; mr 5,30; mr 3,29; bl _s8036199C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8036199C_0();
extern "C" void _s8036199C_1();
extern "C" void f_8036199C() {}
