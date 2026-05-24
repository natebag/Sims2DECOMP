// 0x8031D6FC ERShader::Clone(unsigned (1492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 24,0x18(1); stw 0,0x44(1); mr 27,3; mr 30,4; lha 0,0xc(27); cmpwi 0,0; beq 0f; lwz 0,0x1c(27); cmpwi 0,0; bne 0f; lwz 0,0x5c(27); cmpwi 0,0; bne 0f; cmpwi 30,0; beq 0f; lwz 0,0x8(27); cmpw 30,0; beq 0f; lis 3,-32692; mr 4,30; addi 3,3,-17444; lis 26,-32692; bl _s8031D6FC_0; mr. 29,3; li 3,0; bne 26f; mr 3,27; bl _s8031D6FC_1; mr. 31,3; bne 1f; 0:; li 3,0; b 26f; 1:; stw 30,0x8(31); lis 11,-32702; lwz 0,0x10(31); addi 8,27,60; lwz 9,0x10(27); addi 28,31,60; stw 29,0x14(31); addi 3,31,32; rlwimi 0,9,0,0,23; stw 29,0x18(31); stw 0,0x10(31); li 4,0; stw 29,0x1c(31); li 5,8; lfs f31,0xa74(11); mr 25,3; lwz 0,0x30(27); addi 30,31,40; mr 24,30; stw 0,0x30(31); lwz 0,0x3c(27); lwz 9,0x4(8); lwz 11,0x8(8); lwz 10,0xc(8); stw 0,0x3c(31); stw 11,0x8(28); stw 10,0xc(28); stw 9,0x4(28); lwz 0,0x10(8); stw 0,0x10(28); lbz 9,0x50(27); stw 29,0x54(31); stb 9,0x50(31); lwz 0,0x58(27); stw 29,0x5c(31); stw 0,0x58(31); stfs f31,0x60(31); lbz 0,0x64(27); stb 0,0x64(31); lbz 9,0x65(27); stb 9,0x65(31); lbz 0,0x66(27); stb 0,0x66(31); lbz 9,0x67(27); stb 9,0x67(31); stw 29,0x68(31); stw 29,0x34(31); stw 29,0x38(31); bl _s8031D6FC_2; mr 3,30; li 4,0; li 5,8; bl _s8031D6FC_3; lwz 0,0x58(31); andi. 9,0,2; beq 6f; stw 29,0x4c(31); mr 3,28; stw 29,0x48(31); bl _s8031D6FC_4; lbz 4,0x8(28); cmpwi 4,0; beq 2f; li 5,8; addi 3,26,-17444; bl _s8031D6FC_5; lbz 4,0x8(28); li 5,8; stw 3,0xc(28); rlwinm 4,4,2,0,29; addi 3,26,-17444; bl _s8031D6FC_6; stw 3,0x10(28); 2:; lbz 5,0x44(27); lwz 4,0x48(27); lwz 3,0x48(31); crxor 6,6,6; bl _s8031D6FC_7; lbz 5,0x44(27); lwz 3,0x4c(31); lwz 4,0x4c(27); rlwinm 5,5,2,0,29; crxor 6,6,6; bl _s8031D6FC_8; lwz 3,0x18(27); cmpwi 3,0; beq 3f; bl _s8031D6FC_9; 3:; lwz 0,0x68(27); cmpwi 0,0; beq 24f; li 4,68; li 5,16; addi 3,26,-17444; bl _s8031D6FC_10; lis 9,-32702; addi 8,3,48; lfs f0,0xa78(9); addi 11,3,16; addi 7,11,16; lis 6,-32702; stfs f0,0x8(1); fmr f12,f31; stfs f0,0x10(1); addi 30,3,64; stfs f0,0xc(1); li 29,0; lwz 0,0x8(1); li 4,0; lwz 9,0xc(1); mr 5,3; lwz 10,0x10(1); stw 0,0x30(3); stw 9,0x4(8); stw 10,0x8(8); lfs f0,0x30(3); stfs f0,0x10(11); lfs f13,0x4(8); stfs f13,0x4(7); lfs f0,0x8(8); stfs f0,0x8(7); lfs f13,0x10(11); stfs f13,0x10(3); lfs f0,0x4(7); stfs f0,0x4(11); lfs f13,0x8(7); stfs f13,0x8(11); lfs f0,0xc(7); stfs f0,0xc(11); lfs f13,0xa7c(6); stfs f13,0x2c(11); 4:; stfs f12,0x0(5); stfs f12,0x8(5); stbx 29,30,4; addi 5,5,4; addi 4,4,1; cmpwi 4,1; ble 4b; stw 3,0x68(31); mr 8,3; li 9,48; lwz 3,0x68(27); 5:; lwz 0,0x0(3); addic. 9,9,-24; stw 0,0x0(8); lwz 0,0x4(3); stw 0,0x4(8); lwz 0,0x8(3); stw 0,0x8(8); lwz 0,0xc(3); stw 0,0xc(8); lwz 0,0x10(3); stw 0,0x10(8); lwz 0,0x14(3); addi 3,3,24; stw 0,0x14(8); addi 8,8,24; bne 5b; lwz 0,0x0(3); stw 0,0x0(8); lwz 0,0x4(3); stw 0,0x4(8); lwz 0,0x8(3); stw 0,0x8(8); lwz 0,0xc(3); stw 0,0xc(8); lwz 0,0x10(3); stw 0,0x10(8); b 24f; 6:; lwz 3,0x14(27); cmpwi 3,0; beq 7f; mr 11,3; b 8f; 7:; lwz 9,0x18(27); li 11,0; cmpwi 9,0; beq 8f; lwz 11,0x14(9); 8:; lwz 9,0xf0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x58(31); stw 3,0x14(31); andi. 9,0,2; beq 9f; li 0,0; b 11f; 9:; cmpwi 3,0; bne 10f; lwz 9,0x18(31); li 3,0; cmpwi 9,0; beq 10f; lwz 3,0x14(9); 10:; lwz 0,0x4(3); rlwinm 0,0,6,31,31; 11:; cmpwi 0,0; beq 20f; lwz 4,0x30(31); cmpwi 4,0; beq 24f; lis 30,-32692; li 5,8; rlwinm 4,4,2,0,29; addi 3,30,-17444; bl _s8031D6FC_11; stw 3,0x38(31); lwz 5,0x30(31); lwz 4,0x38(27); rlwinm 5,5,2,0,29; crxor 6,6,6; bl _s8031D6FC_12; lwz 4,0x30(31); li 5,8; addi 3,30,-17444; rlwinm 4,4,2,0,29; bl _s8031D6FC_13; stw 3,0x34(31); lwz 5,0x30(31); lwz 4,0x34(27); rlwinm 5,5,2,0,29; crxor 6,6,6; bl _s8031D6FC_14; lwz 0,0x14(31); cmpwi 0,0; beq 12f; mr 9,0; b 13f; 12:; lwz 11,0x18(31); li 9,0; cmpwi 11,0; beq 13f; lwz 9,0x14(11); 13:; addi 28,9,100; lis 3,-32692; lbz 4,0x24(28); addi 3,3,-17444; li 5,8; li 29,0; rlwinm 4,4,2,0,29; bl _s8031D6FC_15; stw 3,0x4(28); lwz 0,0x30(31); cmplw 29,0; bge 15f; li 30,0; 14:; lwz 9,0x34(31); addi 29,29,1; lwzx 3,30,9; bl _s8031D6FC_16; lwz 11,0x34(31); lwz 10,0x4(28); lwzx 9,30,11; lwz 0,0x14(9); stwx 0,30,10; addi 30,30,4; lwz 0,0x30(31); cmplw 29,0; blt 14b; 15:; lhz 4,0x26(28); cmpwi 4,0; beq 19f; lis 3,-32692; li 5,8; addi 3,3,-17444; li 29,0; bl _s8031D6FC_17; lhz 0,0x26(28); stw 3,0x8(28); cmplw 29,0; bge 24f; 16:; lwz 0,0x14(27); cmpwi 0,0; beq 17f; mr 9,0; b 18f; 17:; lwz 11,0x18(27); li 9,0; cmpwi 11,0; beq 18f; lwz 9,0x14(11); 18:; lwz 9,0x6c(9); lwz 11,0x8(28); lbzx 0,9,29; stbx 0,11,29; addi 29,29,1; lhz 0,0x26(28); cmplw 29,0; blt 16b; b 24f; 19:; stw 4,0x8(28); b 24f; 20:; addi 26,27,32; li 29,0; addi 27,27,40; li 28,0; li 30,0; 21:; lwzx 0,30,27; stwx 0,30,24; lwzx 0,30,26; cmpwi 0,0; beq 23f; mr 3,0; stwx 0,30,25; bl _s8031D6FC_18; lwz 11,0x14(31); cmpwi 11,0; bne 22f; lwz 9,0x18(31); li 11,0; cmpwi 9,0; beq 22f; lwz 11,0x14(9); 22:; lwzx 9,30,25; addi 11,11,100; lwz 0,0x14(9); stwx 0,11,28; 23:; addi 29,29,1; addi 28,28,64; addi 30,30,4; cmplwi 29,1; ble 21b; 24:; lwz 0,0x58(31); andi. 9,0,2; beq 25f; mr 3,31; bl _s8031D6FC_19; 25:; mr 3,31; 26:; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x18(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s8031D6FC_0();
extern "C" void _s8031D6FC_1();
extern "C" void _s8031D6FC_2();
extern "C" void _s8031D6FC_3();
extern "C" void _s8031D6FC_4();
extern "C" void _s8031D6FC_5();
extern "C" void _s8031D6FC_6();
extern "C" void _s8031D6FC_7();
extern "C" void _s8031D6FC_8();
extern "C" void _s8031D6FC_9();
extern "C" void _s8031D6FC_10();
extern "C" void _s8031D6FC_11();
extern "C" void _s8031D6FC_12();
extern "C" void _s8031D6FC_13();
extern "C" void _s8031D6FC_14();
extern "C" void _s8031D6FC_15();
extern "C" void _s8031D6FC_16();
extern "C" void _s8031D6FC_17();
extern "C" void _s8031D6FC_18();
extern "C" void _s8031D6FC_19();

struct ERShader {
    void Clone();
};

void ERShader::Clone() {
}
