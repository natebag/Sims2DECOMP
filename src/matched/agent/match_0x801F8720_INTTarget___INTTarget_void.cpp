// 0x801F8720 INTTarget::~INTTarget(void) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,31832; lwz 0,0x98(31); stw 9,0x80(31); lis 11,-32697; mr 30,4; cmpwi 0,0; lwz 3,0x5f10(11); bne 0f; li 4,62; bl _s801F8720_0; b 1f; 0:; li 4,63; bl _s801F8720_1; 1:; lwz 0,0x0(31); cmpwi 0,0; beq 11f; lwz 3,0x4(31); addi 4,31,40; bl _s801F8720_2; lwz 3,0x8(31); addi 4,31,56; bl _s801F8720_3; lwz 3,0xc(31); addi 4,31,72; bl _s801F8720_4; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(31); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(31); bl _s801F8720_5; 4:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(31); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(31); bl _s801F8720_6; 7:; lwz 3,0x18(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801F8720_7; 8:; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801F8720_8; 9:; lwz 3,0x20(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801F8720_9; 10:; lwz 3,0x24(31); cmpwi 3,0; beq 11f; lwz 4,0x7c(31); bl _s801F8720_10; 11:; addi 3,31,200; li 4,2; bl _s801F8720_11; addi 3,31,196; li 4,2; bl _s801F8720_12; addi 3,31,192; li 4,2; bl _s801F8720_13; addi 3,31,188; li 4,2; bl _s801F8720_14; addi 3,31,184; li 4,2; bl _s801F8720_15; addi 3,31,180; li 4,2; bl _s801F8720_16; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 12f; mr 3,31; bl _s801F8720_17; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F8720_0();
extern "C" void _s801F8720_1();
extern "C" void _s801F8720_2();
extern "C" void _s801F8720_3();
extern "C" void _s801F8720_4();
extern "C" void _s801F8720_5();
extern "C" void _s801F8720_6();
extern "C" void _s801F8720_7();
extern "C" void _s801F8720_8();
extern "C" void _s801F8720_9();
extern "C" void _s801F8720_10();
extern "C" void _s801F8720_11();
extern "C" void _s801F8720_12();
extern "C" void _s801F8720_13();
extern "C" void _s801F8720_14();
extern "C" void _s801F8720_15();
extern "C" void _s801F8720_16();
extern "C" void _s801F8720_17();
extern "C" void f_801F8720() {}
