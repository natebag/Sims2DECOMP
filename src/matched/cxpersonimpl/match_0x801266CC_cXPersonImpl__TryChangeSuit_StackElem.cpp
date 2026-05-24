// 0x801266CC cXPersonImpl::TryChangeSuit(StackElem (852 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,5; mr 31,3; lbz 0,0x1(29); mr 28,4; cmpwi 0,1; beq 4f; bgt 0f; cmpwi 0,0; beq 1f; b 2f; 0:; cmpwi 0,2; bne 2f; lwz 3,0x10(28); bl _s801266CC_0; b 3f; 1:; lwz 3,0x10(28); bl _s801266CC_1; b 3f; 2:; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,48; lwz 11,0x0(9); li 4,48; sth 10,0x34(11); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 19f; 3:; lbz 0,0x1(29); cmpwi 0,1; bne 8f; 4:; lhz 0,0x2(29); andi. 9,0,2; beq 5f; li 3,0; b 18f; 5:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x160(9); lwz 9,0x164(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 6f; li 3,0; b 18f; 6:; lwz 3,0x4(31); li 4,8; lbz 30,0x0(29); lwz 9,0x4(3); lha 0,0x138(9); lwz 9,0x13c(9); add 3,3,0; mtspr 8,9; blrl; cmpw 3,30; beq 7f; lwz 3,0x4(31); mr 5,30; li 4,8; lwz 9,0x4(3); lha 0,0x140(9); lwz 9,0x144(9); add 3,3,0; mtspr 8,9; blrl; 7:; lwz 3,0x3f4(31); lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; b 19f; 8:; li 30,0; li 3,0; stw 30,0x8(1); li 27,0; bl _s801266CC_2; stw 30,0x8(1); bl _s801266CC_3; lbz 0,0x1(29); stw 3,0x8(1); cmpwi 0,0; beq 9f; cmpwi 0,2; bne 10f; lwz 3,0x10(28); bl _s801266CC_4; b 11f; 9:; lwz 3,0x10(28); bl _s801266CC_5; b 11f; 10:; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,48; lwz 11,0x0(9); li 4,48; b 12f; 11:; lwz 11,0x8(1); mr 4,3; li 5,304; lwz 9,0x0(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x8(1); lbz 4,0x0(29); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; mr. 27,3; bne 13f; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,49; lwz 11,0x0(9); li 4,49; 12:; sth 10,0x34(11); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; lwz 3,0x8(1); bl _s801266CC_6; li 3,-1; stw 27,0x8(1); li 4,-1; b 19f; 13:; lhz 5,0x2(29); andi. 29,5,1; beq 14f; lwz 3,0x3f4(31); mr 4,27; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; b 17f; 14:; rlwinm 30,5,31,31,31; cmpwi 30,0; beq 16f; lwz 3,0x3f4(31); mr 4,27; lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 15f; lwz 3,0x8(1); bl _s801266CC_7; li 3,0; stw 29,0x8(1); b 18f; 15:; lwz 3,0x8(1); bl _s801266CC_8; li 3,0; stw 31,0x8(1); li 4,0; b 19f; 16:; lwz 3,0x3f4(31); mr 4,27; lwz 9,0x0(3); lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x8(1); bl _s801266CC_9; li 3,0; stw 30,0x8(1); b 18f; 17:; lwz 3,0x8(1); bl _s801266CC_10; li 0,0; li 3,0; stw 0,0x8(1); 18:; li 4,1; 19:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s801266CC_0();
extern "C" void _s801266CC_1();
extern "C" void _s801266CC_2();
extern "C" void _s801266CC_3();
extern "C" void _s801266CC_4();
extern "C" void _s801266CC_5();
extern "C" void _s801266CC_6();
extern "C" void _s801266CC_7();
extern "C" void _s801266CC_8();
extern "C" void _s801266CC_9();
extern "C" void _s801266CC_10();

struct cXPersonImpl {
    void TryChangeSuit_StackElem();
};

void cXPersonImpl::TryChangeSuit_StackElem() {
}
