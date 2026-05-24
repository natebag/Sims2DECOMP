// 0x80070154 SimImageMaker::CreateImage32x32(void) (664 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 28,0x30(1); stw 0,0x44(1); stw 12,0x2c(1); mr 29,3; li 4,64; li 5,64; li 6,32; lwz 28,0x8(29); bl _s80070154_0; mr 3,29; bl _s80070154_1; mr. 30,3; bne 1f; 0:; li 3,0; b 9f; 1:; mcrf cr4,cr0; addi 8,1,8; mr 10,30; li 0,24; 2:; lwz 9,0x0(10); addic. 0,0,-24; stw 9,0x0(8); lwz 9,0x4(10); stw 9,0x4(8); lwz 9,0x8(10); stw 9,0x8(8); lwz 9,0xc(10); stw 9,0xc(8); lwz 9,0x10(10); stw 9,0x10(8); lwz 9,0x14(10); addi 10,10,24; stw 9,0x14(8); addi 8,8,24; bne 2b; lwz 9,0x0(10); li 0,32; lwz 11,-26392(13); addi 4,1,8; stw 9,0x0(8); lwz 9,0x4(10); stw 9,0x4(8); sth 0,0x18(1); sth 0,0x1a(1); lwz 9,0x0(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; mr. 31,3; bne 4f; beq cr4,0b; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 3f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 3:; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; b 0b; 4:; lbz 6,-32208(13); mr 3,30; lbz 0,-32207(13); mr 4,31; lbz 9,-32206(13); rlwinm 6,6,24,0,7; rlwinm 0,0,16,0,15; lbz 11,-32205(13); or 6,6,0; rlwinm 9,9,8,0,23; or 6,6,9; li 5,32; or 6,6,11; bl _s80070154_2; beq cr4,6f; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 5f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 5:; lwz 3,-26392(13); mr 4,30; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; 6:; mr 6,28; mr 3,29; li 5,32; li 4,32; bl _s80070154_3; mr 3,29; mr 4,31; bl _s80070154_4; mr 30,3; cmpwi 31,0; beq 8f; lwz 3,-26392(13); mr 4,31; lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 7f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 7:; lwz 3,-26392(13); mr 4,31; lwz 9,0x0(3); lha 0,0xc0(9); lwz 9,0xc4(9); add 3,3,0; mtspr 8,9; blrl; 8:; mr 3,30; 9:; lwz 0,0x44(1); lwz 12,0x2c(1); mtspr 8,0; lmw 28,0x30(1); mtcrf 8,12; addi 1,1,64"

extern "C" void _s80070154_0();
extern "C" void _s80070154_1();
extern "C" void _s80070154_2();
extern "C" void _s80070154_3();
extern "C" void _s80070154_4();

struct SimImageMaker {
    void CreateImage32x32();
};

void SimImageMaker::CreateImage32x32() {
}
