// 0x800BEF6C IFFResFile2::GetName(Memory::HandleNode (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 9,0xc(31); mr 30,5; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BEF6C_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BEF6C_1; 1:; mr 3,31; bl _s800BEF6C_2; cmpwi 3,0; bne 3f; lwz 3,0x138(31); mr 4,29; addi 5,1,8; li 6,0; bl _s800BEF6C_3; mr. 4,3; beq 2f; mr 3,30; addi 4,4,16; bl _s800BEF6C_4; b 3f; 2:; mr 3,30; bl _s800BEF6C_5; mr 3,31; li 4,-98; bl _s800BEF6C_6; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800BEF6C_0();
extern "C" void _s800BEF6C_1();
extern "C" void _s800BEF6C_2();
extern "C" void _s800BEF6C_3();
extern "C" void _s800BEF6C_4();
extern "C" void _s800BEF6C_5();
extern "C" void _s800BEF6C_6();
extern "C" void f_800BEF6C() {}
