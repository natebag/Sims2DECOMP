// 0x800BF46C IFFResFile2::Detach(Memory::HandleNode (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BF46C_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BF46C_1; 1:; mr 3,31; bl _s800BF46C_2; mr. 28,3; bne 4f; lwz 3,0x138(31); mr 4,29; addi 5,1,8; li 6,0; bl _s800BF46C_3; mr. 30,3; beq 3f; lwz 0,0x0(30); cmpwi 0,-1; bne 2f; lwz 9,0xc(31); mr 4,29; lha 3,0x108(9); lwz 0,0x10c(9); add 3,31,3; mtspr 8,0; blrl; 2:; lhz 0,0xa(30); mr 3,31; stw 28,0xc(30); li 4,0; sth 0,0x8(30); bl _s800BF46C_4; b 4f; 3:; mr 3,31; li 4,-99; bl _s800BF46C_5; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800BF46C_0();
extern "C" void _s800BF46C_1();
extern "C" void _s800BF46C_2();
extern "C" void _s800BF46C_3();
extern "C" void _s800BF46C_4();
extern "C" void _s800BF46C_5();
extern "C" void f_800BF46C() {}
