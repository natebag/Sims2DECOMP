// 0x801B41C4 FCMTarget::UpdateFireCodeMeter(void) (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 28,3; lwz 0,0x88(28); cmpwi 0,0; beq 7f; lwz 0,0x90(28); cmpwi 0,0; beq 0f; bl _s801B41C4_0; mr 4,3; mr 3,28; bl _s801B41C4_1; 0:; lwz 0,0xa0(28); lwz 9,0xa4(28); mr 6,0; cmpw 0,9; beq 4f; lwz 0,0x9c(28); cmpwi 0,0; bne 4f; xoris 0,6,32768; stw 0,0xc(1); lis 11,17200; lis 10,-32705; lis 8,-32705; stw 11,0x8(1); lis 7,-32705; lfd f13,0x950(10); lis 11,-32705; lfd f0,0x8(1); lfs f11,0x958(8); fsub f0,f0,f13; lfs f12,0x95c(7); frsp f0,f0; lfd f10,0x960(11); fdivs f0,f0,f11; fmuls f0,f0,f12; fmr f13,f0; fcmpu 0,f13,f10; cror 3,2,1; bso 1f; fctiwz f0,f13; stfd f0,0x8(1); lwz 31,0xc(1); b 2f; 1:; fsub f0,f13,f10; fctiwz f13,f0; stfd f13,0x8(1); lwz 31,0xc(1); xoris 31,31,32768; 2:; addi 0,31,1; lwz 9,0xa4(28); rlwinm 0,0,0,31,31; add 31,31,0; subf. 29,6,9; rlwinm 26,31,31,1,31; subfic 27,26,326; bge 3f; subf 29,9,6; 3:; mulli 29,29,6; addi 30,28,168; lis 4,-32705; lis 7,-32705; li 6,0; addi 7,7,2240; li 8,0; addi 29,29,33; addi 4,4,2312; mr 5,29; mr 3,30; bl _s801B41C4_2; mr 4,31; mr 3,30; bl _s801B41C4_3; mr 4,27; mr 3,30; bl _s801B41C4_4; mr 3,30; bl _s801B41C4_5; lis 4,-32705; lis 7,-32705; mr 5,29; addi 7,7,-8764; li 6,0; li 8,0; addi 4,4,2324; mr 3,30; bl _s801B41C4_6; subf 4,26,27; mr 3,30; bl _s801B41C4_7; mr 3,30; bl _s801B41C4_8; lwz 9,0xa0(28); li 0,1; stw 0,0x9c(28); stw 9,0xa4(28); 4:; lwz 0,0xa4(28); cmpwi 0,96; ble 5f; lwz 0,0x98(28); cmpwi 0,0; bne 7f; lwz 0,0x94(28); cmpwi 0,0; bne 7f; addi 30,28,168; lis 4,-32705; lis 7,-32705; li 5,250; addi 7,7,2260; li 6,0; li 8,0; addi 4,4,2344; mr 3,30; bl _s801B41C4_9; mr 3,30; li 4,255; b 6f; 5:; lwz 0,0x98(28); cmpwi 0,0; beq 7f; lwz 0,0x94(28); cmpwi 0,0; bne 7f; addi 30,28,168; lis 4,-32705; lis 7,-32705; li 5,250; addi 7,7,2280; li 6,0; li 8,0; addi 4,4,2344; mr 3,30; bl _s801B41C4_10; mr 3,30; li 4,0; 6:; bl _s801B41C4_11; mr 3,30; bl _s801B41C4_12; li 0,1; stw 0,0x94(28); 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

extern "C" void _s801B41C4_0();
extern "C" void _s801B41C4_1();
extern "C" void _s801B41C4_2();
extern "C" void _s801B41C4_3();
extern "C" void _s801B41C4_4();
extern "C" void _s801B41C4_5();
extern "C" void _s801B41C4_6();
extern "C" void _s801B41C4_7();
extern "C" void _s801B41C4_8();
extern "C" void _s801B41C4_9();
extern "C" void _s801B41C4_10();
extern "C" void _s801B41C4_11();
extern "C" void _s801B41C4_12();

struct FCMTarget {
    void UpdateFireCodeMeter();
};

void FCMTarget::UpdateFireCodeMeter() {
}
