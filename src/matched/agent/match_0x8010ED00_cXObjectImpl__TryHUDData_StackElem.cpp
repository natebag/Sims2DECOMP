// 0x8010ED00 cXObjectImpl::TryHUDData(StackElem (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); lis 9,-32697; mr 29,3; lwz 0,0x5bc8(9); mr 31,5; cmpwi 0,0; beq 4f; li 0,0; lbz 4,0x2(31); lha 5,0x0(31); mr 3,29; sth 0,0x8(1); li 6,0; li 7,0; addi 8,1,8; bl _s8010ED00_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; beq 4f; 0:; addi 30,1,10; addi 6,1,12; lha 5,0x4(31); mr 28,6; lbz 4,0x6(31); mr 3,29; li 7,0; mr 8,30; bl _s8010ED00_1; mr 5,30; cmpwi 3,-1; bne 1f; cmpwi 4,-1; beq 4f; 1:; lbz 0,0x3(31); cmpwi 0,1; bne 2f; lis 9,-32697; lha 4,0x8(1); lwz 3,0x5bc8(9); lha 5,0xa(1); bl _s8010ED00_2; cmpwi 3,0; bne 6f; b 4f; 2:; lwz 0,0xc(1); cmpwi 0,0; bne 3f; lwz 11,0x0(29); li 0,1; stw 0,-24512(13); li 9,19; sth 9,0x34(11); li 4,19; lwz 11,0x4(29); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 7f; 3:; lis 9,-32697; lha 4,0x8(1); lwz 3,0x5bc8(9); bl _s8010ED00_3; cmpwi 3,0; bne 5f; 4:; li 3,0; li 4,0; b 7f; 5:; lha 5,0x4(31); mr 3,29; lbz 4,0x6(31); mr 6,28; lha 7,0xa(1); bl _s8010ED00_4; 6:; li 3,0; li 4,1; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8010ED00_0();
extern "C" void _s8010ED00_1();
extern "C" void _s8010ED00_2();
extern "C" void _s8010ED00_3();
extern "C" void _s8010ED00_4();
extern "C" void f_8010ED00() {}
