// 0x800CF1CC NeighborhoodImpl::RemoveFromFamily(Neighbor (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,4; mr 27,3; addi 26,28,112; lha 4,0x7a(26); cmpwi 4,0; beq 0f; lwz 9,0x0(27); lha 3,0x120(9); lwz 0,0x124(9); add 3,27,3; mtspr 8,0; blrl; mr. 31,3; beq 0f; lwz 30,0x0(31); mr 3,28; lha 29,0x48(30); addi 30,30,72; add 29,31,29; bl _s800CF1CC_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; 0:; li 3,-1; b 3f; 1:; lwz 29,-21484(13); mr 3,28; lwz 30,0x0(29); lha 0,0xe8(30); addi 30,30,232; add 29,29,0; bl _s800CF1CC_1; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 11,3; beq 2f; lwz 9,0x4(11); li 4,61; li 5,0; lha 3,0x140(9); lwz 0,0x144(9); add 3,11,3; mtspr 8,0; blrl; 2:; li 0,0; mr 3,28; sth 0,0x7a(26); lwz 30,0x0(31); lha 29,0x20(30); addi 30,30,32; add 29,31,29; bl _s800CF1CC_2; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; lwz 9,0x0(27); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,27,3; blrl; li 0,1; li 3,228; stw 0,0x20(31); li 4,0; bl _s800CF1CC_3; li 3,0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s800CF1CC_0();
extern "C" void _s800CF1CC_1();
extern "C" void _s800CF1CC_2();
extern "C" void _s800CF1CC_3();
extern "C" void f_800CF1CC() {}
