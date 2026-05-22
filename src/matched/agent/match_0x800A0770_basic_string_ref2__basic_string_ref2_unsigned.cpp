// 0x800A0770 basic_string_ref2::basic_string_ref2(unsigned (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; cmpwi 5,1; bne 2f; li 0,0; stw 31,0x8(30); stw 0,0x4(30); cmpwi 31,0; beq 0f; bl _s800A0770_0; rlwinm 4,31,1,0,30; li 5,0; bl _s800A0770_1; b 1f; 0:; li 3,0; 1:; stw 3,0x0(30); b 7f; 2:; cmpwi 5,0; bne 6f; cmpwi 31,-1; beq 6f; stw 31,0x4(30); cmpwi 31,0; stw 31,0x8(30); beq 5f; addi 0,31,-1; li 29,0; stw 0,0x4(30); bl _s800A0770_2; rlwinm 4,31,1,0,30; li 5,0; bl _s800A0770_3; lwz 0,0x4(30); stw 3,0x0(30); cmplw 29,0; bge 4f; 3:; bl _s800A0770_4; lwz 11,0x0(30); add 9,29,29; addi 29,29,1; sthx 3,9,11; lwz 0,0x4(30); cmplw 29,0; blt 3b; 4:; bl _s800A0770_5; lwz 11,0x0(30); add 9,29,29; sthx 3,9,11; b 7f; 5:; stw 31,0x0(30); b 7f; 6:; bl _s800A0770_6; 7:; li 0,1; mr 3,30; stw 0,0xc(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A0770_0();
extern "C" void _s800A0770_1();
extern "C" void _s800A0770_2();
extern "C" void _s800A0770_3();
extern "C" void _s800A0770_4();
extern "C" void _s800A0770_5();
extern "C" void _s800A0770_6();
extern "C" void f_800A0770() {}
