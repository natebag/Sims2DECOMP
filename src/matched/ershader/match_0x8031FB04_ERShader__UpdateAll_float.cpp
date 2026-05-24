// 0x8031FB04 ERShader::UpdateAll(float, (712 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stfd f31,0x50(1); stmw 23,0x2c(1); stw 0,0x5c(1); mr 23,3; mr 24,4; lis 3,-32692; fmr f31,f1; mr 25,5; li 4,-1; addi 3,3,-17444; bl _s8031FB04_0; lis 3,-32693; li 4,-1; lwz 9,0x17b8(3); addi 3,3,6072; lha 0,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; li 0,0; addi 9,1,8; lwz 10,-22620(13); addi 11,9,8; stw 0,0x8(1); mr 27,9; stw 0,0x4(9); li 4,0; stw 0,0x4(11); cmpwi 10,0; beq 1f; 0:; lwz 10,0x8(10); addi 4,4,1; cmpwi 10,0; bne 0b; 1:; addi 3,1,8; bl _s8031FB04_1; lwz 28,-22620(13); cmpwi 28,0; beq 15f; mr 26,27; 2:; lwz 3,0x0(28); lha 0,0xc(3); cmpwi 0,0; ble 14f; bl _s8031FB04_2; lwz 9,0x4(26); lwz 0,0xc(26); cmpw 9,0; beq 3f; lwz 0,0x0(28); stw 0,0x0(9); lwz 9,0x4(27); addi 9,9,4; stw 9,0x4(27); b 14f; 3:; lwz 30,0x4(27); li 9,1; lwz 0,0x8(1); addi 11,1,36; stw 9,0x24(1); addi 10,1,32; subf 0,0,30; srawi 9,0,2; stw 9,0x20(1); cmplwi 9,1; bge 4f; mr 10,11; 4:; lwz 0,0x0(10); add. 0,9,0; beq 6f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 5f; mr 3,29; bl _s8031FB04_3; mr 31,3; b 7f; 5:; mr 3,29; bl _s8031FB04_4; mr 31,3; b 7f; 6:; li 31,0; li 29,0; 7:; lwz 4,0x0(27); cmpw 30,4; beq 8f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8031FB04_5; add 0,3,30; b 9f; 8:; mr 0,31; 9:; lwz 9,0x24(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 11f; 10:; lwz 0,0x0(28); stw 0,0x0(30); addi 30,30,4; bdnz 10b; 11:; lwz 3,0x0(27); lwz 0,0xc(27); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 13f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 12f; bl _s8031FB04_6; b 13f; 12:; bl _s8031FB04_7; 13:; add 0,29,31; stw 31,0x0(27); stw 30,0x4(27); stw 0,0xc(27); 14:; lwz 28,0x8(28); cmpwi 28,0; bne 2b; 15:; lis 3,-32693; lwz 9,0x17b8(3); addi 3,3,6072; lha 0,0x18(9); lwz 9,0x1c(9); add 3,0,3; mtspr 8,9; blrl; lis 3,-32692; addi 3,3,-17444; bl _s8031FB04_8; lwz 30,0x8(1); b 17f; 16:; lwz 11,0x0(30); fmr f1,f31; mr 4,23; mr 5,24; lwz 9,0x0(11); mr 6,25; addi 30,30,4; lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; 17:; lwz 0,0x4(27); cmpw 30,0; bne 16b; lwz 30,0x8(1); b 19f; 18:; lwz 3,0x0(30); addi 30,30,4; bl _s8031FB04_9; 19:; lwz 0,0x4(27); cmpw 30,0; bne 18b; lwz 3,0x8(1); cmpwi 3,0; beq 21f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 20f; bl _s8031FB04_10; b 21f; 20:; bl _s8031FB04_11; 21:; lwz 0,0x5c(1); mtspr 8,0; lmw 23,0x2c(1); lfd f31,0x50(1); addi 1,1,88"

extern "C" void _s8031FB04_0();
extern "C" void _s8031FB04_1();
extern "C" void _s8031FB04_2();
extern "C" void _s8031FB04_3();
extern "C" void _s8031FB04_4();
extern "C" void _s8031FB04_5();
extern "C" void _s8031FB04_6();
extern "C" void _s8031FB04_7();
extern "C" void _s8031FB04_8();
extern "C" void _s8031FB04_9();
extern "C" void _s8031FB04_10();
extern "C" void _s8031FB04_11();

struct ERShader {
    void UpdateAll();
};

void ERShader::UpdateAll() {
}
