// 0x800C1960 Interaction::SetName(BString2 (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,52; bl _s800C1960_0; lwz 0,0x3c(30); ori 0,0,128; stw 0,0x3c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800C1960_0();
extern "C" void f_800C1960() {}
