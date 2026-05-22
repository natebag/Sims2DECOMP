// 0x800ACE64 IFFBehavior::GetTreeIDByName(char (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-328(1); mfspr 0,8; stmw 26,0x130(1); stw 0,0x14c(1); lis 9,-32706; addi 11,1,8; lwz 0,-27864(9); mr 30,4; addi 9,9,-27864; mr 28,3; lwz 10,0x8(9); addi 4,1,32; lwz 8,0x4(9); li 5,260; stw 0,0x8(1); addi 3,1,24; stw 10,0x8(11); li 27,0; stw 8,0x4(11); li 26,0; bl _s800ACE64_0; mr 4,30; addi 3,1,24; li 5,-1; bl _s800ACE64_1; addi 31,1,10; 0:; lwz 30,0x0(28); lhz 3,0x0(31); lha 29,0x30(30); addi 31,31,4; addi 30,30,48; extsh 3,3; add 29,28,29; bl _s800ACE64_2; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 4,3; cmpwi 4,-1; beq 1f; lwz 3,-21508(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; mr. 30,3; beq 1f; lwz 9,0xc(30); lis 4,16968; ori 4,4,16726; addi 5,1,24; lha 3,0x88(9); li 6,0; lwz 0,0x8c(9); add 3,30,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; lwz 9,0xc(30); mr 4,3; sth 26,0x128(1); addi 5,1,296; lha 3,0xb0(9); lwz 0,0xb4(9); add 3,30,3; mtspr 8,0; blrl; lha 3,0x128(1); b 2f; 1:; addi 27,27,1; cmpwi 27,2; ble 0b; li 3,0; 2:; lwz 0,0x14c(1); mtspr 8,0; lmw 26,0x130(1); addi 1,1,328"
extern "C" void _s800ACE64_0();
extern "C" void _s800ACE64_1();
extern "C" void _s800ACE64_2();
extern "C" void f_800ACE64() {}
