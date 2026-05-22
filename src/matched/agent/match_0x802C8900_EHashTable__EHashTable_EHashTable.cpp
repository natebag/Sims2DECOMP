// 0x802C8900 EHashTable::EHashTable(EHashTable (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 0,0; stw 0,0x0(30); mr 29,4; stw 0,0x4(30); lwz 4,0xc(29); bl _s802C8900_0; mr 3,30; mr 4,29; bl _s802C8900_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C8900_0();
extern "C" void _s802C8900_1();
extern "C" void f_802C8900() {}
