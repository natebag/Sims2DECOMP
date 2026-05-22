// 0x80361570 EStringTableNoCase::EStringTableNoCase(EStringTableNoCase (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 0,0; stw 0,0x8(30); mr 29,4; stw 0,0x4(30); stw 0,0x0(30); stw 0,0x14(30); lwz 4,0xc(29); bl _s80361570_0; mr 3,30; mr 4,29; bl _s80361570_1; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80361570_0();
extern "C" void _s80361570_1();
extern "C" void f_80361570() {}
