// 0x80361BFC EStringTableNoCase::RemoveAll(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 30,0x4(29); cmpwi 30,0; beq 2f; 0:; lwz 31,0x0(30); cmpwi 30,0; beq 1f; lwz 4,0xc(30); addi 3,30,12; bl _s80361BFC_0; mr 3,30; bl _s80361BFC_1; 1:; mr. 30,31; bne 0b; 2:; li 30,0; mr 3,29; stw 30,0x4(29); stw 30,0x0(29); bl _s80361BFC_2; stw 30,0x14(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80361BFC_0();
extern "C" void _s80361BFC_1();
extern "C" void _s80361BFC_2();
extern "C" void f_80361BFC() {}
