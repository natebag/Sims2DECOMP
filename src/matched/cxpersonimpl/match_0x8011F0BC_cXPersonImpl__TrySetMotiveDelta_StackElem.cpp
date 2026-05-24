// 0x8011F0BC cXPersonImpl::TrySetMotiveDelta(StackElem (932 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 27,0x3c(1); stw 0,0x54(1); mr 30,5; mr 31,3; lbz 9,0x3(30); li 11,1; rlwinm 0,9,0,29,30; cmpwi 0,0; bne 0f; li 11,0; 0:; cmpwi 11,0; beq 1f; lwz 3,0x0(31); mr 5,30; bl _s8011F0BC_0; b 26f; 1:; andi. 0,9,1; beq 4f; lwz 10,0x3e4(31); addi 3,31,996; lwz 0,0x4(3); mr 11,10; cmpw 10,0; beq 3f; 2:; addi 11,11,12; cmpw 11,0; bne 2b; 3:; stw 10,0x4(3); b 25f; 4:; lbz 0,0x2(30); cmpwi 0,4; blt 5f; cmpwi 0,9; ble 6f; cmpwi 0,15; bgt 5f; cmpwi 0,14; bge 6f; 5:; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,26; lwz 11,0x0(9); li 4,26; sth 10,0x34(11); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; b 8f; 6:; lwz 3,0x0(31); li 6,0; lbz 4,0x0(30); li 7,0; lha 5,0x4(30); addi 8,1,8; bl _s8011F0BC_1; cmpwi 3,-1; bne 7f; cmpwi 4,-1; beq 8f; 7:; lwz 3,0x0(31); li 6,0; lbz 4,0x1(30); li 7,0; lha 5,0x6(30); addi 8,1,10; bl _s8011F0BC_2; cmpwi 3,-1; bne 9f; cmpwi 4,-1; bne 9f; 8:; li 3,-1; li 4,-1; b 26f; 9:; addi 29,31,996; lwz 7,0x3e4(31); lwz 0,0x4(29); lis 3,-21846; ori 3,3,43691; subf 0,7,0; mullw 0,0,3; srawi 0,0,2; cmplwi 0,15; bgt 25f; lha 0,0x8(1); lis 8,17200; lis 9,-32706; xoris 0,0,32768; lfd f12,-13216(9); stw 0,0x34(1); lis 9,-32706; lfs f0,-13208(9); lis 10,-32706; stw 8,0x30(1); mr 9,11; lfs f11,-13204(10); lfd f13,0x30(1); lha 0,0xa(1); fsub f13,f13,f12; lbz 5,0x2(30); frsp f13,f13; xoris 0,0,32768; fdivs f13,f13,f0; stw 0,0x34(1); stw 5,0x10(1); stw 8,0x30(1); lfd f0,0x30(1); fdivs f13,f13,f11; fsub f0,f0,f12; stfs f13,0x14(1); frsp f0,f0; stfs f0,0x18(1); lwz 9,0x4(29); lwz 0,0xc(29); cmpw 9,0; beq 10f; lwz 11,0x14(1); lwz 0,0x18(1); stw 5,0x0(9); stw 0,0x8(9); stw 11,0x4(9); lwz 9,0x4(29); addi 9,9,12; stw 9,0x4(29); b 25f; 10:; mr 30,9; addi 11,1,36; subf 0,7,30; li 9,1; mullw 0,0,3; stw 9,0x24(1); addi 9,1,32; srawi 3,0,2; stw 3,0x20(1); cmplwi 3,1; bge 11f; mr 9,11; 11:; lwz 0,0x0(9); add. 0,3,0; beq 13f; mulli 0,0,12; mr 28,0; cmplwi 0,128; ble 12f; mr 3,28; bl _s8011F0BC_3; b 14f; 12:; mr 3,28; bl _s8011F0BC_4; b 14f; 13:; li 3,0; li 28,0; 14:; mr 31,3; lwz 10,0x0(29); mr 27,31; mr 3,27; cmpw 10,30; beq 16f; 15:; lwz 0,0x0(10); lwz 9,0x4(10); lwz 11,0x8(10); stw 0,0x0(3); addi 10,10,12; stw 9,0x4(3); cmpw 10,30; stw 11,0x8(3); addi 3,3,12; bne 15b; 16:; lwz 0,0x24(1); mr 31,3; cmpwi 0,1; bne 17f; lwz 0,0x10(1); lwz 9,0x14(1); lwz 11,0x18(1); stw 0,0x0(31); stw 9,0x4(31); stw 11,0x8(31); addi 31,31,12; b 20f; 17:; mr. 9,0; mr 3,31; mtspr 9,9; beq 19f; 18:; lwz 0,0x10(1); lwz 9,0x14(1); lwz 11,0x18(1); stw 0,0x0(3); stw 9,0x4(3); stw 11,0x8(3); addi 3,3,12; bdnz 18b; 19:; mr 31,3; 20:; lwz 11,0x0(29); lwz 0,0x4(29); mr 3,11; lwz 9,0xc(29); cmpw 11,0; beq 22f; 21:; addi 11,11,12; cmpw 11,0; bne 21b; 22:; lis 0,-21846; subf 9,3,9; ori 0,0,43691; cmpwi 3,0; mullw 9,9,0; srawi 4,9,2; beq 24f; mulli 4,4,12; cmplwi 4,128; ble 23f; bl _s8011F0BC_5; b 24f; 23:; bl _s8011F0BC_6; 24:; add 0,28,27; stw 27,0x0(29); stw 0,0xc(29); stw 31,0x4(29); 25:; li 3,0; li 4,1; 26:; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x3c(1); addi 1,1,80"

extern "C" void _s8011F0BC_0();
extern "C" void _s8011F0BC_1();
extern "C" void _s8011F0BC_2();
extern "C" void _s8011F0BC_3();
extern "C" void _s8011F0BC_4();
extern "C" void _s8011F0BC_5();
extern "C" void _s8011F0BC_6();

struct cXPersonImpl {
    void TrySetMotiveDelta_StackElem();
};

void cXPersonImpl::TrySetMotiveDelta_StackElem() {
}
