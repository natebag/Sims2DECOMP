// 0x80300040 EWindow::Select(ERC (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 31,3; mr 28,4; lwz 0,0x98(31); cmpwi 0,0; bne 0f; lwz 0,0x90(31); addi 29,1,40; cmpwi 0,0; bne 3f; 0:; lwz 11,0x90(31); cmpwi 11,0; beq 1f; addi 0,1,40; lwz 9,0x20(11); mr 4,0; mr 29,0; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; lwz 11,-26392(13); addi 30,1,40; lwz 5,0x94(31); mr 4,30; lwz 9,0x0(11); mr 29,30; lha 3,0x68(9); lwz 0,0x6c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,31; mr 4,30; bl _s80300040_0; lfs f0,0x50(31); addi 9,31,80; lfs f12,0x80(31); addi 11,1,8; stfs f0,0x8(1); addi 10,31,128; mr 3,30; lfs f0,0x4(9); stfs f0,0x4(11); lfs f13,0x8(9); stfs f13,0x8(11); lfs f0,0xc(9); stfs f0,0xc(11); stfs f12,0x18(1); lfs f0,0x4(10); stfs f0,0x1c(1); lfs f13,0x8(10); stfs f13,0x20(1); lfs f0,0xc(10); stfs f0,0x24(1); bl _s80300040_1; 2:; mr 3,31; mr 4,29; bl _s80300040_2; li 0,0; stw 0,0x98(31); 3:; lwz 9,0x9c(31); stw 31,-26708(13); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(28); stw 3,-26704(13); lwz 0,0x1e4(9); lha 3,0x1e0(9); mtspr 8,0; lwz 4,0x90(31); add 3,28,3; lwz 5,0x94(31); blrl; lwz 0,0x90(31); cmpwi 0,0; bne 7f; lfs f13,0x8(1); addi 9,1,8; lfs f0,0x18(1); li 0,0; fcmpu 0,f13,f0; bne 4f; lfs f13,0x4(9); lfs f0,0x1c(1); fcmpu 0,f13,f0; bne 4f; lfs f13,0x8(9); lfs f0,0x20(1); fcmpu 0,f13,f0; bne 4f; lfs f0,0xc(9); lfs f13,0x24(1); fcmpu 7,f0,f13; mfcr 0; rlwinm 0,0,31,31,31; 4:; cmpwi 0,0; beq 5f; lwz 11,-26392(13); addi 30,1,56; mr 4,30; lwz 5,0x94(31); lwz 9,0x0(11); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); mr 5,30; mr 4,29; mr 6,5; lwz 9,0x0(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; b 6f; 5:; lwz 11,-26392(13); addi 5,1,24; addi 6,1,8; mr 4,29; lwz 9,0x0(11); addi 30,1,56; lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); addi 5,1,8; mr 4,30; mr 6,5; lwz 9,0x0(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; mr 3,29; mr 4,30; bl _s80300040_3; 6:; lwz 9,0x70(28); mr 4,29; lha 3,0xd0(9); lwz 0,0xd4(9); add 3,28,3; mtspr 8,0; blrl; b 8f; 7:; lwz 11,-26392(13); mr 4,29; addi 5,31,128; addi 6,31,80; lwz 9,0x0(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x70(28); mr 4,29; lha 3,0xd0(9); lwz 0,0xd4(9); add 3,28,3; mtspr 8,0; blrl; 8:; lwz 9,0x70(28); mr 4,31; lha 3,0x108(9); lwz 0,0x10c(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"

extern "C" void _s80300040_0();
extern "C" void _s80300040_1();
extern "C" void _s80300040_2();
extern "C" void _s80300040_3();

struct EWindow {
    void Select();
};

void EWindow::Select() {
}
