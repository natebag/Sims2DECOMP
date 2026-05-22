// 0x801A8A74 CSPTarget::~CSPTarget(void) (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 11,-32698; lwz 0,0x94(31); lis 9,-32698; addi 11,11,30552; addi 9,9,30576; mr 30,4; stw 11,0x84(31); stw 9,0x80(31); cmpwi 0,0; beq 0f; mr 4,0; li 3,0; bl _s801A8A74_0; li 0,0; stw 0,0x94(31); 0:; lwz 4,0x98(31); cmpwi 4,0; beq 1f; li 3,1; bl _s801A8A74_1; li 0,0; stw 0,0x98(31); 1:; lis 9,-32697; li 4,35; lwz 3,0x5f10(9); bl _s801A8A74_2; lwz 0,0x0(31); cmpwi 0,0; beq 11f; lwz 3,0x4(31); addi 4,31,40; bl _s801A8A74_3; lwz 3,0x8(31); addi 4,31,56; bl _s801A8A74_4; lwz 3,0xc(31); addi 4,31,72; bl _s801A8A74_5; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(31); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(31); bl _s801A8A74_6; 4:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(31); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(31); bl _s801A8A74_7; 7:; lwz 3,0x18(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801A8A74_8; 8:; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801A8A74_9; 9:; lwz 3,0x20(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801A8A74_10; 10:; lwz 3,0x24(31); cmpwi 3,0; beq 11f; lwz 4,0x7c(31); bl _s801A8A74_11; 11:; addi 3,31,424; li 4,2; bl _s801A8A74_12; addi 3,31,280; li 4,2; bl _s801A8A74_13; addi 3,31,276; li 4,2; bl _s801A8A74_14; addi 3,31,172; li 4,2; bl _s801A8A74_15; addi 3,31,168; li 4,2; bl _s801A8A74_16; addi 3,31,164; li 4,2; bl _s801A8A74_17; addi 3,31,160; li 4,2; bl _s801A8A74_18; addi 3,31,156; li 4,2; bl _s801A8A74_19; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 12f; mr 3,31; bl _s801A8A74_20; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801A8A74_0();
extern "C" void _s801A8A74_1();
extern "C" void _s801A8A74_2();
extern "C" void _s801A8A74_3();
extern "C" void _s801A8A74_4();
extern "C" void _s801A8A74_5();
extern "C" void _s801A8A74_6();
extern "C" void _s801A8A74_7();
extern "C" void _s801A8A74_8();
extern "C" void _s801A8A74_9();
extern "C" void _s801A8A74_10();
extern "C" void _s801A8A74_11();
extern "C" void _s801A8A74_12();
extern "C" void _s801A8A74_13();
extern "C" void _s801A8A74_14();
extern "C" void _s801A8A74_15();
extern "C" void _s801A8A74_16();
extern "C" void _s801A8A74_17();
extern "C" void _s801A8A74_18();
extern "C" void _s801A8A74_19();
extern "C" void _s801A8A74_20();
extern "C" void f_801A8A74() {}
