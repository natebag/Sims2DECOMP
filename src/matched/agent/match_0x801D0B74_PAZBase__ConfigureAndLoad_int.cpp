// 0x801D0B74 PAZBase::ConfigureAndLoad(int, (864 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; stw 4,0xa4(31); stw 6,0xa8(31); stw 7,0xac(31); stw 5,0xb0(31); lwz 0,0x0(31); lwz 4,0x0(5); cmpwi 0,0; beq 0f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_0; 0:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x4(9); cmpwi 0,0; beq 1f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_1; 1:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x8(9); cmpwi 0,0; beq 2f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_2; 2:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0xc(9); cmpwi 0,0; beq 3f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_3; 3:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x10(9); cmpwi 0,0; beq 4f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_4; 4:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x14(9); cmpwi 0,0; beq 5f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_5; 5:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x18(9); cmpwi 0,0; beq 6f; lwz 3,0x4(31); addi 5,31,40; bl _s801D0B74_6; 6:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x1c(9); cmpwi 0,0; beq 7f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_7; 7:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x20(9); cmpwi 0,0; beq 8f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_8; 8:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x24(9); cmpwi 0,0; beq 9f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_9; 9:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x28(9); cmpwi 0,0; beq 10f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_10; 10:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x2c(9); cmpwi 0,0; beq 11f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_11; 11:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x30(9); cmpwi 0,0; beq 12f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_12; 12:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x34(9); cmpwi 0,0; beq 13f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_13; 13:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x38(9); cmpwi 0,0; beq 14f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_14; 14:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16452; cmpwi 0,0; beq 15f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_15; 15:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,16468; cmpwi 0,0; beq 16f; lwz 3,0x8(31); addi 5,31,56; bl _s801D0B74_16; 16:; lwz 9,0xb0(31); lwz 0,0x0(31); lwz 4,0x3c(9); cmpwi 0,0; beq 17f; lwz 3,0xc(31); addi 5,31,72; bl _s801D0B74_17; 17:; lwz 0,0x84(31); lis 9,-32697; lwz 3,0x5f10(9); cmpwi 0,0; bne 18f; lwz 4,0xa4(31); li 5,0; bl _s801D0B74_18; b 19f; 18:; lwz 4,0xa4(31); li 5,1; bl _s801D0B74_19; 19:; lis 30,-32705; li 3,0; addi 4,30,16484; bl _s801D0B74_20; stw 3,0xb4(31); lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 20f; addi 4,30,16484; li 3,1; bl _s801D0B74_21; stw 3,0xb8(31); b 21f; 20:; stw 0,0xb8(31); 21:; lwz 9,0x80(31); lis 5,-32705; lwz 11,0xb0(31); addi 5,5,-5288; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; lwz 4,0x2c(11); add 3,31,3; blrl; lwz 0,0x0(31); cmpwi 0,0; beq 24f; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 5,9; cmpwi 0,0; bne 22f; lwz 0,0x58(31); cmpwi 0,0; beq 23f; 22:; li 11,1; 23:; cmpwi 11,0; beq 24f; lwz 3,0x10(31); li 4,75; lwz 6,0x7c(31); bl _s801D0B74_22; 24:; mr 3,31; bl _s801D0B74_23; li 3,1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801D0B74_0();
extern "C" void _s801D0B74_1();
extern "C" void _s801D0B74_2();
extern "C" void _s801D0B74_3();
extern "C" void _s801D0B74_4();
extern "C" void _s801D0B74_5();
extern "C" void _s801D0B74_6();
extern "C" void _s801D0B74_7();
extern "C" void _s801D0B74_8();
extern "C" void _s801D0B74_9();
extern "C" void _s801D0B74_10();
extern "C" void _s801D0B74_11();
extern "C" void _s801D0B74_12();
extern "C" void _s801D0B74_13();
extern "C" void _s801D0B74_14();
extern "C" void _s801D0B74_15();
extern "C" void _s801D0B74_16();
extern "C" void _s801D0B74_17();
extern "C" void _s801D0B74_18();
extern "C" void _s801D0B74_19();
extern "C" void _s801D0B74_20();
extern "C" void _s801D0B74_21();
extern "C" void _s801D0B74_22();
extern "C" void _s801D0B74_23();
extern "C" void f_801D0B74() {}
