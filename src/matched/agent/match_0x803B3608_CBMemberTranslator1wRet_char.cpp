// 0x803B3608 CBMemberTranslator1wRet<char (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lha 10,0x2(3); lwz 8,0x8(3); cmpwi 10,0; blt 0f; lha 0,0x4(3); rlwinm 9,10,3,0,28; lwzx 11,8,0; add 9,9,11; lwz 11,-8(9); lwz 12,-4(9); mr 9,12; b 1f; 0:; lwz 9,0x4(3); 1:; lha 3,0x0(3); cmpwi 10,0; blt 2f; srawi 0,11,16; add 0,0,3; b 3f; 2:; mr 0,3; 3:; add 3,8,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_803B3608() {}
