// 0x801A25B8 ACTTarget::PlaceItem(ACTTarget::ACTRecord (624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); lwz 9,0x40(1); mr 31,4; stw 6,0x3c(31); mr 29,3; stw 7,0x38(31); mr 5,10; stw 8,0x40(31); cmpwi 9,0; lwz 27,0x44(1); beq 0f; lwz 0,0x0(29); lwz 4,0x28(31); cmpwi 0,0; beq 1f; lwz 3,0x1c(29); cmpwi 3,0; beq 1f; lwz 6,0x7c(29); mr 5,9; li 7,0; bl _s801A25B8_0; b 1f; 0:; lwz 0,0x0(29); lwz 4,0x28(31); cmpwi 0,0; beq 1f; lwz 3,0x1c(29); cmpwi 3,0; beq 1f; lwz 6,0x7c(29); li 7,0; bl _s801A25B8_1; 1:; lwz 0,0xe4(29); li 28,0; cmpwi 0,0; bne 2f; stw 31,0xe4(29); mr 3,29; stw 31,0xe8(29); stw 28,0x48(31); stw 28,0x44(31); li 28,1; bl _s801A25B8_2; b 7f; 2:; cmpwi 27,0; beq 7f; mr 30,0; 3:; lwz 0,0x38(30); cmpw 0,27; bne 6f; lwz 0,0x48(30); li 28,1; stw 30,0x44(31); stw 0,0x48(31); lwz 9,0x48(30); cmpwi 9,0; beq 4f; stw 31,0x44(9); b 5f; 4:; stw 31,0xe4(29); 5:; stw 31,0x48(30); mr 3,29; bl _s801A25B8_3; 6:; lwz 30,0x44(30); cmpwi 30,0; beq 7f; cmpwi 28,0; beq 3b; 7:; cmpwi 28,0; bne 8f; lwz 9,0xe8(29); mr 3,29; stw 31,0x44(9); lwz 0,0xe8(29); stw 0,0x48(31); stw 31,0xe8(29); stw 28,0x44(31); bl _s801A25B8_4; 8:; li 30,1; li 0,0; li 9,-1; stw 30,0x4(31); stw 0,0x8(31); mr 3,29; stw 9,0xc(31); bl _s801A25B8_5; addi 3,1,8; bl _s801A25B8_6; addi 3,1,8; bl _s801A25B8_7; lwz 5,0xdc(29); addi 3,1,8; lwz 4,0x24(31); bl _s801A25B8_8; lwz 9,0x10(31); addi 3,1,8; lwz 0,0x14(31); addi 9,9,128; mr 4,9; stw 0,0x1c(31); stw 9,0x18(31); bl _s801A25B8_9; lwz 4,0x1c(31); addi 3,1,8; bl _s801A25B8_10; addi 3,1,8; li 4,0; bl _s801A25B8_11; addi 3,1,8; li 4,1; bl _s801A25B8_12; lwz 5,0xdc(29); addi 3,1,8; lwz 4,0x2c(31); bl _s801A25B8_13; lis 4,255; addi 3,1,8; ori 4,4,65535; bl _s801A25B8_14; addi 3,1,8; bl _s801A25B8_15; lwz 8,0xdc(29); addi 3,1,8; lwz 7,0x30(31); li 5,250; lwz 4,0x24(31); li 6,0; bl _s801A25B8_16; lwz 4,0x10(31); addi 3,1,8; bl _s801A25B8_17; lwz 4,0x14(31); addi 3,1,8; bl _s801A25B8_18; li 4,255; addi 3,1,8; bl _s801A25B8_19; addi 3,1,8; bl _s801A25B8_20; lwz 9,0x10(31); addi 3,1,8; lwz 0,0x14(31); li 4,2; stw 30,0x20(31); stw 0,0x1c(31); stw 9,0x18(31); bl _s801A25B8_21; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s801A25B8_0();
extern "C" void _s801A25B8_1();
extern "C" void _s801A25B8_2();
extern "C" void _s801A25B8_3();
extern "C" void _s801A25B8_4();
extern "C" void _s801A25B8_5();
extern "C" void _s801A25B8_6();
extern "C" void _s801A25B8_7();
extern "C" void _s801A25B8_8();
extern "C" void _s801A25B8_9();
extern "C" void _s801A25B8_10();
extern "C" void _s801A25B8_11();
extern "C" void _s801A25B8_12();
extern "C" void _s801A25B8_13();
extern "C" void _s801A25B8_14();
extern "C" void _s801A25B8_15();
extern "C" void _s801A25B8_16();
extern "C" void _s801A25B8_17();
extern "C" void _s801A25B8_18();
extern "C" void _s801A25B8_19();
extern "C" void _s801A25B8_20();
extern "C" void _s801A25B8_21();
extern "C" void f_801A25B8() {}
