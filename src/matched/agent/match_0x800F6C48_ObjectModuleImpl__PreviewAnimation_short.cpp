// 0x800F6C48 ObjectModuleImpl::PreviewAnimation(short, (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 27,0x5c(1); stw 0,0x74(1); mr 30,3; mr 31,5; lwz 9,0x0(30); mr 28,6; mr 27,7; lha 3,0x90(9); lwz 0,0x94(9); add 3,30,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 3,0x0(3); li 4,2; bl _s800F6C48_0; mr 29,3; b 1f; 0:; li 29,0; 1:; cmpwi 29,0; beq 3f; li 11,0; cmpwi 31,0; beq 2f; lwz 9,0x0(30); mr 4,31; lha 3,0x90(9); lwz 0,0x94(9); add 3,30,3; mtspr 8,0; blrl; mr. 11,3; beq 3f; lwz 9,0x4(11); lha 3,0x288(9); lwz 0,0x28c(9); add 3,11,3; mtspr 8,0; blrl; mr 11,3; 2:; cmpwi 11,0; beq 3f; cmpwi 28,0; ble 3f; lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; cmpw 28,3; bge 3f; lha 4,0x2054(30); cmpwi 4,0; bne 4f; 3:; li 3,0; b 6f; 4:; sth 31,0x50(1); cmpwi 27,0; addi 31,1,80; li 9,0; sth 28,0x2(31); beq 5f; li 9,1; 5:; li 0,0; sth 9,0x4(31); sth 0,0x6(31); lwz 9,0x0(30); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,30,3; blrl; mr 5,3; li 6,0; li 7,100; addi 3,1,8; mr 4,29; bl _s800F6C48_1; addi 3,1,8; mr 4,31; bl _s800F6C48_2; lwz 9,0x4(29); addi 4,1,8; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,29,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s800F6C48_3; li 3,1; 6:; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x5c(1); addi 1,1,112"
extern "C" void _s800F6C48_0();
extern "C" void _s800F6C48_1();
extern "C" void _s800F6C48_2();
extern "C" void _s800F6C48_3();
extern "C" void f_800F6C48() {}
