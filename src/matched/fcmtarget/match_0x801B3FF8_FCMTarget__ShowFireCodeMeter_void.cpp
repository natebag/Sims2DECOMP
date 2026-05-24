// 0x801B3FF8 FCMTarget::ShowFireCodeMeter(void) (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 27,3; bl _s801B3FF8_0; xoris 0,3,32768; stw 0,0xc(1); lis 8,17200; lis 9,-32705; lis 10,-32705; stw 8,0x8(1); lfd f13,0x938(9); lis 8,-32705; lfd f0,0x8(1); lis 9,-32705; lfs f11,0x940(10); fsub f0,f0,f13; lfs f12,0x944(9); frsp f0,f0; lfd f10,0x948(8); fdivs f0,f0,f11; stw 3,0xa4(27); fmuls f0,f0,f12; fmr f13,f0; fcmpu 0,f13,f10; cror 3,2,1; bso 0f; mr 9,11; fctiwz f0,f13; stfd f0,0x8(1); lwz 31,0xc(1); b 1f; 0:; fsub f0,f13,f10; fctiwz f13,f0; stfd f13,0x8(1); lwz 31,0xc(1); xoris 31,31,32768; 1:; addi 0,31,1; addi 30,27,168; rlwinm 0,0,0,31,31; mr 3,30; add 31,31,0; mr 26,30; bl _s801B3FF8_1; rlwinm 28,31,31,1,31; lis 4,-32705; li 5,0; addi 4,4,2236; mr 3,30; bl _s801B3FF8_2; subfic 29,28,326; mr 3,30; li 4,1; bl _s801B3FF8_3; li 4,64; mr 3,30; bl _s801B3FF8_4; lis 4,-32705; li 5,0; addi 4,4,2312; mr 3,30; bl _s801B3FF8_5; mr 4,31; mr 3,30; bl _s801B3FF8_6; mr 4,29; mr 3,30; bl _s801B3FF8_7; lis 4,-32705; li 5,0; addi 4,4,2324; mr 3,30; bl _s801B3FF8_8; subf 4,28,29; mr 3,30; bl _s801B3FF8_9; lis 4,-32705; li 5,0; addi 4,4,2332; mr 3,30; bl _s801B3FF8_10; li 4,330; mr 3,30; bl _s801B3FF8_11; lis 4,-32705; mr 3,30; addi 4,4,2344; li 5,0; bl _s801B3FF8_12; lwz 0,0xa4(27); cmpwi 0,96; ble 2f; mr 3,26; li 4,255; bl _s801B3FF8_13; li 0,1; b 3f; 2:; mr 3,26; li 4,0; bl _s801B3FF8_14; li 0,0; 3:; stw 0,0x98(27); mr 3,26; bl _s801B3FF8_15; li 0,1; stw 0,0x90(27); lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

extern "C" void _s801B3FF8_0();
extern "C" void _s801B3FF8_1();
extern "C" void _s801B3FF8_2();
extern "C" void _s801B3FF8_3();
extern "C" void _s801B3FF8_4();
extern "C" void _s801B3FF8_5();
extern "C" void _s801B3FF8_6();
extern "C" void _s801B3FF8_7();
extern "C" void _s801B3FF8_8();
extern "C" void _s801B3FF8_9();
extern "C" void _s801B3FF8_10();
extern "C" void _s801B3FF8_11();
extern "C" void _s801B3FF8_12();
extern "C" void _s801B3FF8_13();
extern "C" void _s801B3FF8_14();
extern "C" void _s801B3FF8_15();

struct FCMTarget {
    void ShowFireCodeMeter();
};

void FCMTarget::ShowFireCodeMeter() {
}
