// 0x803C81EC EStream (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,4; mr 31,3; mr 3,30; bl _s803C81EC_0; lwz 9,0x18(31); addi 4,1,8; stw 3,0x8(1); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; lwz 30,0x0(30); b 1f; 0:; lwz 4,0x0(30); mr 3,31; bl _s803C81EC_1; lwz 30,0x8(30); 1:; li 0,1; cmpwi 30,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s803C81EC_0();
extern "C" void _s803C81EC_1();
extern "C" void f_803C81EC() {}
