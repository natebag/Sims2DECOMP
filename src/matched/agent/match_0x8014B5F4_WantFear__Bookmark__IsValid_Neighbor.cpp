// 0x8014B5F4 WantFear::Bookmark::IsValid(Neighbor (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 31,4; cmpwi 5,0; beq 0f; mr 3,31; mr 4,30; bl _s8014B5F4_0; cmpwi 3,0; li 3,0; beq 4f; 0:; mr 3,30; bl _s8014B5F4_1; cmpwi 3,0; bne 1f; mr 3,30; bl _s8014B5F4_2; cmpwi 3,0; li 3,1; bne 4f; 1:; lwz 3,0x4(30); bl _s8014B5F4_3; lha 28,0x6(3); cmpwi 28,-1; beq 3f; li 9,0; lhz 0,0x4(31); li 10,0; mr 3,30; stw 9,0x8(1); stw 10,0xc(1); sth 0,0x8(1); bl _s8014B5F4_4; cmpwi 3,0; li 0,0; beq 2f; li 0,1; 2:; addi 31,1,8; mr 3,30; sth 0,0x2(31); bl _s8014B5F4_5; lwz 9,0x4(30); lis 4,-25070; sth 3,0x4(31); ori 4,4,48956; lwz 11,-21484(13); lhz 0,0x8(9); sth 0,0x6(31); lwz 9,0x0(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 3f; lwz 9,0x4(11); lwz 29,0x0(11); lha 3,0x378(9); lwz 9,0x37c(9); lwz 30,0x18(29); add 3,11,3; mtspr 8,9; lha 0,0xa0(30); addi 30,30,160; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mr 6,28; mr 7,31; li 5,0; mtspr 8,0; blrl; b 4f; 3:; li 3,1; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8014B5F4_0();
extern "C" void _s8014B5F4_1();
extern "C" void _s8014B5F4_2();
extern "C" void _s8014B5F4_3();
extern "C" void _s8014B5F4_4();
extern "C" void _s8014B5F4_5();
extern "C" void f_8014B5F4() {}
