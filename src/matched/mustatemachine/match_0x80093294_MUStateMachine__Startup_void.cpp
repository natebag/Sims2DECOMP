// 0x80093294 MUStateMachine::Startup(void) (1008 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 27,0xc(1); stw 0,0x2c(1); mr 28,3; li 30,0; bl _s80093294_0; li 29,-1; li 3,32; li 27,1; bl _s80093294_1; lis 11,-32698; mr 9,3; addi 11,11,-8656; mr 4,9; stw 11,0x18(9); mr 3,28; stw 30,0x0(9); stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_2; li 3,36; bl _s80093294_3; lis 11,-32698; mr 9,3; addi 11,11,-8728; mr 4,9; stw 11,0x18(9); mr 3,28; stw 27,0x0(9); stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_4; li 3,36; bl _s80093294_5; lis 11,-32698; mr 9,3; addi 11,11,-8944; li 0,2; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_6; li 3,36; bl _s80093294_7; lis 11,-32698; mr 9,3; addi 11,11,-9016; li 0,3; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_8; li 3,32; bl _s80093294_9; lis 11,-32698; mr 9,3; addi 11,11,-9088; li 0,5; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_10; li 3,56; bl _s80093294_11; lis 10,-32706; lis 11,-32698; lfs f31,-32020(10); mr 9,3; addi 11,11,-9160; li 0,6; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); stfs f31,0x30(9); stfs f31,0x34(9); bl _s80093294_12; li 3,28; bl _s80093294_13; lis 11,-32698; mr 9,3; addi 11,11,-8800; li 0,4; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_14; li 3,36; bl _s80093294_15; lis 11,-32698; mr 9,3; addi 11,11,-9232; li 0,7; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_16; li 3,36; bl _s80093294_17; lis 11,-32698; mr 9,3; addi 11,11,-9304; li 0,8; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_18; li 3,36; bl _s80093294_19; lis 11,-32698; mr 9,3; addi 11,11,-9376; li 0,9; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_20; li 3,36; bl _s80093294_21; lis 11,-32698; mr 9,3; addi 11,11,-9448; li 0,10; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_22; li 3,28; bl _s80093294_23; lis 11,-32698; mr 9,3; addi 11,11,-8872; li 0,11; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_24; li 3,36; bl _s80093294_25; lis 11,-32698; mr 9,3; addi 11,11,-9520; li 0,13; mr 4,9; stw 0,0x0(9); stw 11,0x18(9); mr 3,28; stw 29,0x4(9); stw 30,0x8(9); stw 29,0xc(9); stw 30,0x10(9); stw 27,0x14(9); bl _s80093294_26; li 3,28; bl _s80093294_27; lis 11,-32698; mr 9,3; li 0,14; addi 11,11,-9592; mr 4,9; stw 0,0x0(9); stw 29,0xc(9); mr 3,28; stw 30,0x10(9); stw 27,0x14(9); stw 11,0x18(9); stw 29,0x4(9); stw 30,0x8(9); bl _s80093294_28; mr 3,28; fmr f1,f31; li 4,0; bl _s80093294_29; lwz 9,0x18(28); lha 3,0x20(9); lwz 0,0x24(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0xc(1); lfd f31,0x20(1); addi 1,1,40"

extern "C" void _s80093294_0();
extern "C" void _s80093294_1();
extern "C" void _s80093294_2();
extern "C" void _s80093294_3();
extern "C" void _s80093294_4();
extern "C" void _s80093294_5();
extern "C" void _s80093294_6();
extern "C" void _s80093294_7();
extern "C" void _s80093294_8();
extern "C" void _s80093294_9();
extern "C" void _s80093294_10();
extern "C" void _s80093294_11();
extern "C" void _s80093294_12();
extern "C" void _s80093294_13();
extern "C" void _s80093294_14();
extern "C" void _s80093294_15();
extern "C" void _s80093294_16();
extern "C" void _s80093294_17();
extern "C" void _s80093294_18();
extern "C" void _s80093294_19();
extern "C" void _s80093294_20();
extern "C" void _s80093294_21();
extern "C" void _s80093294_22();
extern "C" void _s80093294_23();
extern "C" void _s80093294_24();
extern "C" void _s80093294_25();
extern "C" void _s80093294_26();
extern "C" void _s80093294_27();
extern "C" void _s80093294_28();
extern "C" void _s80093294_29();

struct MUStateMachine {
    void Startup();
};

void MUStateMachine::Startup() {
}
