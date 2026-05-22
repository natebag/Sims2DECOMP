// 0x80360634 EStringRedBlackTreeNoCase::EStringRedBlackTreeNoCase(EStringRedBlackTreeNoCase (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32700; mr 30,3; li 0,0; addi 9,9,11816; stw 0,0x0(30); stw 9,0x8(30); li 5,1; stw 0,0x4(30); bl _s80360634_0; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80360634_0();
extern "C" void f_80360634() {}
