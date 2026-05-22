// 0x803BC568 CBMemberTranslator0<PDATarget, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lha 10,0x2(3); lwz 8,0x8(3); cmpwi 10,0; blt 0f; lha 9,0x4(3); rlwinm 11,10,3,0,28; add 9,8,9; lwz 0,0x84(9); add 11,11,0; lwz 12,-4(11); lwz 11,-8(11); mr 9,12; b 1f; 0:; lwz 9,0x4(3); 1:; lha 3,0x0(3); cmpwi 10,0; blt 2f; srawi 0,11,16; add 0,0,3; add 3,8,0; b 3f; 2:; add 3,8,3; 3:; cmpwi 3,0; li 0,0; beq 4f; addi 0,3,132; 4:; mr 3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_803BC568() {}
