// 0x800BFB5C IFFResFile2::Remove(Memory::HandleNode (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BFB5C_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BFB5C_1; 1:; mr 3,31; bl _s800BFB5C_2; cmpwi 3,0; bne 6f; lwz 9,0xc(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 2f; mr 3,31; li 4,-45; bl _s800BFB5C_3; b 6f; 2:; lwz 3,0x138(31); mr 4,30; addi 5,1,8; li 6,0; bl _s800BFB5C_4; mr. 30,3; beq 4f; mr 3,31; mr 4,30; bl _s800BFB5C_5; mr. 3,3; beq 3f; mr 4,3; mr 3,31; bl _s800BFB5C_6; b 5f; 3:; lwz 3,0x138(31); mr 4,30; bl _s800BFB5C_7; b 5f; 4:; mr 3,31; li 4,-99; bl _s800BFB5C_8; 5:; addi 3,31,16; bl _s800BFB5C_9; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800BFB5C_0();
extern "C" void _s800BFB5C_1();
extern "C" void _s800BFB5C_2();
extern "C" void _s800BFB5C_3();
extern "C" void _s800BFB5C_4();
extern "C" void _s800BFB5C_5();
extern "C" void _s800BFB5C_6();
extern "C" void _s800BFB5C_7();
extern "C" void _s800BFB5C_8();
extern "C" void _s800BFB5C_9();
extern "C" void f_800BFB5C() {}
