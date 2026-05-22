// 0x800BF5D0 IFFResFile2::IsLittleEndian(Memory::HandleNode (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BF5D0_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BF5D0_1; 1:; mr 3,31; bl _s800BF5D0_2; cmpwi 3,0; li 3,1; bne 3f; lwz 3,0x138(31); mr 4,30; addi 5,1,8; li 6,0; bl _s800BF5D0_3; mr. 30,3; bne 2f; mr 3,31; li 4,-99; bl _s800BF5D0_4; li 3,1; b 3f; 2:; mr 3,31; li 4,0; bl _s800BF5D0_5; lhz 3,0x8(30); rlwinm 3,3,28,31,31; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800BF5D0_0();
extern "C" void _s800BF5D0_1();
extern "C" void _s800BF5D0_2();
extern "C" void _s800BF5D0_3();
extern "C" void _s800BF5D0_4();
extern "C" void _s800BF5D0_5();
extern "C" void f_800BF5D0() {}
