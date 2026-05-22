// 0x800A0110 BString2::delete_ref(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x0(30); lwz 11,0xc(9); addi 11,11,-1; stw 11,0xc(9); lwz 3,0x0(30); lwz 0,0xc(3); cmpwi 0,0; bne 0f; li 4,2; bl _s800A0110_0; lwz 30,0x0(30); bl _s800A0110_1; mr 4,30; bl _s800A0110_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800A0110_0();
extern "C" void _s800A0110_1();
extern "C" void _s800A0110_2();
extern "C" void f_800A0110() {}
