// 0x800BF18C IFFResFile2::GetID(Memory::HandleNode (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 30,4; lwz 9,0xc(31); mr 29,5; lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; li 4,-49; bl _s800BF18C_0; b 1f; 0:; mr 3,31; li 4,0; bl _s800BF18C_1; 1:; mr 3,31; bl _s800BF18C_2; cmpwi 3,0; bne 3f; lwz 3,0x138(31); mr 4,30; addi 5,1,8; li 6,0; bl _s800BF18C_3; mr. 3,3; beq 2f; lhz 0,0x6(3); sth 0,0x0(29); b 3f; 2:; mr 3,31; li 4,-98; bl _s800BF18C_4; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800BF18C_0();
extern "C" void _s800BF18C_1();
extern "C" void _s800BF18C_2();
extern "C" void _s800BF18C_3();
extern "C" void _s800BF18C_4();
extern "C" void f_800BF18C() {}
