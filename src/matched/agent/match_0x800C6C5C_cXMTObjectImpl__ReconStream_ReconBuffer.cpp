// 0x800C6C5C cXMTObjectImpl::ReconStream(ReconBuffer (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 31,4; mr 29,5; lwz 3,0x0(30); bl _s800C6C5C_0; mr 3,31; addi 4,30,28; li 5,1; bl _s800C6C5C_1; mr 3,31; addi 4,30,32; li 5,1; bl _s800C6C5C_2; cmpwi 29,57; ble 0f; mr 3,31; addi 4,30,36; li 5,1; bl _s800C6C5C_3; 0:; cmpwi 29,39; ble 1f; mr 3,31; addi 4,30,16; li 5,1; bl _s800C6C5C_4; mr 3,31; addi 4,30,20; li 5,1; bl _s800C6C5C_5; mr 3,31; addi 4,30,24; li 5,1; bl _s800C6C5C_6; 1:; lwz 9,0xc(30); cmpwi 9,0; beq 2f; lwz 9,0x0(9); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x328(11); lwz 0,0x32c(11); add 3,10,3; mtspr 8,0; blrl; b 3f; 2:; li 3,0; 3:; sth 3,0x8(1); addi 4,1,8; mr 3,31; li 5,1; bl _s800C6C5C_7; lwz 0,0xc(31); cmpwi 0,0; bne 6f; lha 4,0x8(1); cmpwi 4,0; beq 6f; lwz 11,0x0(30); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x488(9); lwz 0,0x48c(9); add 3,10,3; mtspr 8,0; blrl; mr. 3,3; beq 4f; lwz 3,0x0(3); li 4,3; bl _s800C6C5C_8; mr 4,3; b 5f; 4:; li 4,0; 5:; mr 3,30; bl _s800C6C5C_9; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s800C6C5C_0();
extern "C" void _s800C6C5C_1();
extern "C" void _s800C6C5C_2();
extern "C" void _s800C6C5C_3();
extern "C" void _s800C6C5C_4();
extern "C" void _s800C6C5C_5();
extern "C" void _s800C6C5C_6();
extern "C" void _s800C6C5C_7();
extern "C" void _s800C6C5C_8();
extern "C" void _s800C6C5C_9();
extern "C" void f_800C6C5C() {}
