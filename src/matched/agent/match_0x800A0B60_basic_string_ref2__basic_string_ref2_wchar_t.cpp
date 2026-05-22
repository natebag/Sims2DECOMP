// 0x800A0B60 basic_string_ref2::basic_string_ref2(wchar_t, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,5; mr 31,3; sth 4,0x8(1); cmpwi 30,-1; bne 0f; bl _s800A0B60_0; 0:; stw 30,0x4(31); cmpwi 30,0; stw 30,0x8(31); beq 5f; addi 30,30,1; stw 30,0x8(31); cmpwi 30,0; beq 1f; bl _s800A0B60_1; rlwinm 4,30,1,0,30; li 5,0; bl _s800A0B60_2; b 2f; 1:; li 3,0; 2:; lwz 0,0x4(31); li 8,0; stw 3,0x0(31); cmplw 8,0; bge 4f; 3:; lwz 10,0x0(31); add 11,8,8; lhz 9,0x8(1); addi 8,8,1; sthx 9,11,10; lwz 0,0x4(31); cmplw 8,0; blt 3b; 4:; lwz 30,0x4(31); bl _s800A0B60_3; lwz 9,0x0(31); add 30,30,30; sthx 3,30,9; b 6f; 5:; stw 30,0x0(31); 6:; li 0,1; mr 3,31; stw 0,0xc(31); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800A0B60_0();
extern "C" void _s800A0B60_1();
extern "C" void _s800A0B60_2();
extern "C" void _s800A0B60_3();
extern "C" void f_800A0B60() {}
