// 0x8011EC7C cXPersonImpl::PostLoad(int, (708 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,-21476(13); mr 28,3; mr 31,4; mr 30,5; lwz 9,0x0(11); lwz 4,0x4(28); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x0(28); mr 5,30; mr 4,31; bl _s8011EC7C_0; lwz 11,0x4(28); lwz 9,0x4(11); lwz 0,0x1ac(9); lha 3,0x1a8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x3f4(28); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21508(13); lwz 9,0x0(11); lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(28); lwz 0,0x8c(9); cmpw 0,3; bne 0f; lwz 10,0x58(9); lwz 9,0x4(28); lwz 11,0x0(10); lwz 4,0x0(9); lwz 0,0x134(11); lha 3,0x130(11); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(28); li 4,0; lwz 9,0x4(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(28); lwz 10,0x4(9); lwz 30,0x58(9); lwz 11,0x4(10); lwz 9,0x0(30); lha 3,0x328(11); lwz 11,0x32c(11); addi 29,9,96; add 3,10,3; lha 0,0x60(9); mtspr 8,11; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; li 5,1; mtspr 8,0; blrl; 0:; cmpwi 31,49; bgt 6f; 1:; li 31,0; b 4f; 2:; lwz 9,0x0(28); mr 4,31; lwz 10,0x60(9); lwz 30,0x4(9); lwz 11,0x0(10); lwz 9,0x4(30); lha 3,0x60(11); lwz 11,0x64(11); addi 29,9,1160; add 3,10,3; lha 0,0x488(9); mtspr 8,11; add 30,30,0; blrl; lwz 0,0x4(29); extsh 4,3; mr 3,30; mtspr 8,0; blrl; mr. 11,3; beq 3f; lwz 9,0x4(11); lha 3,0x318(9); lwz 0,0x31c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,2; bne 3f; lwz 11,0x0(28); mr 4,31; li 31,-1; lwz 30,0x60(11); lwz 9,0x0(30); lha 3,0x60(9); addi 29,9,48; lwz 11,0x64(9); add 3,30,3; lha 0,0x30(9); mtspr 8,11; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; b 5f; 3:; addi 31,31,1; 4:; lwz 11,0x0(28); lwz 3,0x60(11); lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; cmpw 31,3; blt 2b; 5:; cmpwi 31,-1; beq 1b; 6:; mr 3,28; bl _s8011EC7C_1; mr 3,28; bl _s8011EC7C_2; cmpwi 3,0; bne 7f; lwz 11,0x3f4(28); li 4,0; lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; lwz 10,0x4(28); li 4,1; lwz 9,0x0(10); lwz 11,0x0(9); lwz 3,0x14(11); bl _s8011EC7C_3; b 8f; 7:; lwz 9,0x4(28); li 4,0; lwz 11,0x0(9); lwz 10,0x0(11); lwz 3,0x14(10); bl _s8011EC7C_4; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8011EC7C_0();
extern "C" void _s8011EC7C_1();
extern "C" void _s8011EC7C_2();
extern "C" void _s8011EC7C_3();
extern "C" void _s8011EC7C_4();

struct cXPersonImpl {
    void PostLoad();
};

void cXPersonImpl::PostLoad() {
}
