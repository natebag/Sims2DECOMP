// 0x802C899C EHashTable::InitTable(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; bl _s802C899C_0; rlwinm 29,28,2,0,29; mr 4,29; li 5,0; bl _s802C899C_1; stw 3,0x8(30); stw 28,0xc(30); mr 3,30; bl _s802C899C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802C899C_0();
extern "C" void _s802C899C_1();
extern "C" void _s802C899C_2();
extern "C" void f_802C899C() {}
