// 0x801D8088 PCTTarget::WallPainterCallback(InteractorModule::Interactor::CallbackData (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; mr. 29,4; beq 13f; lwz 0,0x0(29); cmpwi 0,3; beq 1f; bgt 0f; cmpwi 0,0; beq 2f; b 13f; 0:; cmpwi 0,4; beq 7f; cmpwi 0,5; beq 10f; b 13f; 1:; bl _s801D8088_0; lwz 4,0x84(30); bl _s801D8088_1; li 4,1; mr 3,30; bl _s801D8088_2; lis 3,30424; ori 3,3,7210; bl _s801D8088_3; b 8f; 2:; mr 4,29; mr 3,30; bl _s801D8088_4; lwz 0,0xe8(30); mr 31,3; cmpwi 0,0; bne 3f; xoris 0,31,32768; stw 0,0x14(1); lis 11,17200; lis 10,-32705; mr 8,9; stw 11,0x10(1); lfd f13,0x48c8(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0x10(1); lwz 31,0x14(1); 3:; cmpwi 31,0; beq 6f; li 3,0; bl _s801D8088_5; lwz 0,0xe8(30); cmpwi 0,0; beq 4f; subf 3,31,3; b 5f; 4:; add 3,3,31; 5:; mr 4,3; li 3,0; bl _s801D8088_6; lis 3,-30726; ori 3,3,3858; bl _s801D8088_7; 6:; mr 3,30; bl _s801D8088_8; lwz 0,0x214(30); stw 3,0x20c(30); cmpwi 0,0; beq 8f; mr 3,0; li 4,0; bl _s801D8088_9; lwz 3,0x214(30); li 4,0; bl _s801D8088_10; b 8f; 7:; li 4,0; li 5,0; mr 3,30; bl _s801D8088_11; 8:; li 3,0; crxor 6,6,6; bl _s801D8088_12; 9:; li 3,1; b 14f; 10:; mr 3,30; mr 4,29; bl _s801D8088_13; lwz 0,0xe8(30); mr 31,3; cmpwi 0,0; bne 11f; xoris 0,31,32768; stw 0,0x14(1); lis 11,17200; lis 10,-32705; mr 8,9; stw 11,0x10(1); lfd f13,0x48c8(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; fmr f13,f0; fctiwz f12,f13; stfd f12,0x10(1); lwz 31,0x14(1); 11:; lwz 4,0x10(29); lis 3,-32705; addi 3,3,18600; mr 5,31; crxor 6,6,6; bl _s801D8088_14; lwz 3,0x214(30); cmpwi 3,0; beq 9b; mr 4,31; bl _s801D8088_15; lwz 3,0x214(30); cmpwi 31,0; li 4,1; bne 12f; li 4,0; 12:; bl _s801D8088_16; b 9b; 13:; li 3,0; 14:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s801D8088_0();
extern "C" void _s801D8088_1();
extern "C" void _s801D8088_2();
extern "C" void _s801D8088_3();
extern "C" void _s801D8088_4();
extern "C" void _s801D8088_5();
extern "C" void _s801D8088_6();
extern "C" void _s801D8088_7();
extern "C" void _s801D8088_8();
extern "C" void _s801D8088_9();
extern "C" void _s801D8088_10();
extern "C" void _s801D8088_11();
extern "C" void _s801D8088_12();
extern "C" void _s801D8088_13();
extern "C" void _s801D8088_14();
extern "C" void _s801D8088_15();
extern "C" void _s801D8088_16();

struct PCTTarget {
    void WallPainterCallback_InteractorModule__Interactor();
};

void PCTTarget::WallPainterCallback_InteractorModule__Interactor() {
}
