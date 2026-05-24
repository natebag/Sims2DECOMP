// 0x8008F1B8 ELiveMode::InitPlayerXWindow(ERC (696 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f28,0x40(1); stfd f29,0x48(1); stfd f30,0x50(1); stfd f31,0x58(1); stmw 27,0x2c(1); stw 0,0x64(1); mr 27,4; mr 31,5; lwz 9,0x70(27); mr 28,6; li 4,1; li 5,2; lha 3,0x1c8(9); li 6,0; lwz 0,0x1cc(9); li 7,0; add 3,27,3; mtspr 8,0; blrl; lis 9,-32697; lwz 9,0x5ec8(9); lwz 3,0x14(9); cmpwi 3,0; beq 0f; mr 11,3; b 1f; 0:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 1f; lwz 11,0x14(9); 1:; lwz 9,0xf0(11); li 5,0; mr 4,27; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lis 30,-32697; rlwinm 0,28,2,0,29; addi 30,30,24012; addi 9,30,280; mr 3,30; lwzx 4,9,0; bl _s8008F1B8_0; lis 9,-32697; rlwinm 11,28,4,0,27; addi 9,9,23428; mr 3,30; add 11,11,9; lwz 29,0x100(11); mr 4,29; bl _s8008F1B8_1; mr 3,30; bl _s8008F1B8_2; bl _s8008F1B8_3; lwz 11,-26392(13); fmr f29,f1; lwz 9,0x0(11); lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); mr 30,3; lwz 9,0x0(11); lwz 0,0x14c(9); lha 3,0x148(9); mtspr 8,0; add 3,11,3; blrl; xoris 30,30,32768; stw 30,0x24(1); lis 0,17200; lis 9,-32707; mr 10,11; stw 0,0x20(1); xoris 3,3,32768; lfd f13,0x7e58(9); lfd f0,0x20(1); stw 3,0x24(1); fsub f0,f0,f13; lwz 11,-26392(13); stw 0,0x20(1); frsp f0,f0; fmuls f29,f29,f0; lwz 9,0x0(11); lfd f0,0x20(1); lwz 0,0x144(9); fsub f0,f0,f13; lha 3,0x140(9); frsp f0,f0; mtspr 8,0; fdivs f29,f29,f0; add 3,11,3; blrl; lis 9,-32707; mr 3,29; lfs f28,0x7e60(9); fmuls f31,f1,f28; bl _s8008F1B8_4; fmr f30,f1; mr 3,29; bl _s8008F1B8_5; fmr f4,f1; mr 3,31; fmr f2,f31; fmr f3,f30; fmr f1,f29; bl _s8008F1B8_6; mr 3,29; mr 4,31; bl _s8008F1B8_7; cmpwi 28,0; bne 2f; lis 9,-32707; lis 11,-32707; lfs f31,0x7e64(9); addi 30,1,8; lfs f30,0x7e68(11); mr 3,31; stfs f31,0x8(1); mr 4,30; stfs f31,0x4(30); stfs f28,0x8(30); stfs f30,0xc(30); bl _s8008F1B8_8; stfs f31,0x8(1); mr 4,30; stfs f31,0x4(30); mr 3,31; stfs f28,0x8(30); stfs f30,0xc(30); bl _s8008F1B8_9; b 3f; 2:; lis 11,-32707; lis 9,-32707; lfs f31,0x7e68(9); addi 30,1,8; lfs f30,0x7e64(11); mr 3,31; stfs f28,0x8(1); mr 4,30; stfs f30,0x4(30); stfs f31,0x8(30); stfs f31,0xc(30); bl _s8008F1B8_10; stfs f28,0x8(1); mr 4,30; stfs f30,0x4(30); mr 3,31; stfs f31,0xc(30); stfs f31,0x8(30); bl _s8008F1B8_11; 3:; lwz 9,0x9c(31); mr 4,27; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x2c(1); lfd f28,0x40(1); lfd f29,0x48(1); lfd f30,0x50(1); lfd f31,0x58(1); addi 1,1,96"

extern "C" void _s8008F1B8_0();
extern "C" void _s8008F1B8_1();
extern "C" void _s8008F1B8_2();
extern "C" void _s8008F1B8_3();
extern "C" void _s8008F1B8_4();
extern "C" void _s8008F1B8_5();
extern "C" void _s8008F1B8_6();
extern "C" void _s8008F1B8_7();
extern "C" void _s8008F1B8_8();
extern "C" void _s8008F1B8_9();
extern "C" void _s8008F1B8_10();
extern "C" void _s8008F1B8_11();

struct ELiveMode {
    void InitPlayerXWindow();
};

void ELiveMode::InitPlayerXWindow() {
}
