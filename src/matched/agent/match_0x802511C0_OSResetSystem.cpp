// 0x802511C0 OSResetSystem (512 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stw 31,0x2c(1); stw 30,0x28(1); stw 29,0x24(1); stw 28,0x20(1); mr 28,3; mr 29,4; mr 30,5; bl _s802511C0_0; cmpwi 28,1; bne 0f; cmpwi 30,0; beq 0f; bl _s802511C0_1; lbz 0,0x13(3); ori 0,0,64; stb 0,0x13(3); li 3,1; bl _s802511C0_2; li 29,0; 0:; cmpwi 28,2; beq 1f; cmpwi 28,0; bne 6f; lwz 0,-23624(13); cmplwi 0,0; bne 1f; addis 0,29,16383; cmplwi 0,0; bne 6f; 1:; bl _s802511C0_3; li 3,1; bl _s802511C0_4; mr 31,3; b 2f; 2:; b 3f; 3:; li 3,0; bl _s802511C0_5; cmpwi 3,0; beq 3b; b 4f; 4:; b 5f; 5:; bl _s802511C0_6; cmpwi 3,0; beq 5b; bl _s802511C0_7; li 3,1; bl _s802511C0_8; bl _s802511C0_9; mr 3,31; bl _s802511C0_10; bl _s802511C0_11; b 11f; 6:; bl _s802511C0_12; b 7f; 7:; b 8f; 8:; li 3,0; bl _s802511C0_13; cmpwi 3,0; beq 8b; b 9f; 9:; b 10f; 10:; bl _s802511C0_14; cmpwi 3,0; beq 10b; bl _s802511C0_15; li 3,1; bl _s802511C0_16; bl _s802511C0_17; bl _s802511C0_18; 11:; cmpwi 28,1; bne 12f; bl _s802511C0_19; lis 3,-13312; addi 3,3,8192; li 0,0; sth 0,0x2(3); bl _s802511C0_20; rlwinm 3,29,3,0,28; bl _s802511C0_21; b 14f; 12:; cmpwi 28,0; bne 14f; cmpwi 30,1; bne 13f; lis 3,-32700; crxor 6,6,6; addi 3,3,-18552; bl _s802511C0_22; 13:; bl _s802511C0_23; mr 3,29; lwz 4,-23624(13); bl _s802511C0_24; 14:; lis 31,-32768; addi 3,31,64; li 4,0; li 5,140; bl _s802511C0_25; addi 3,31,212; li 4,0; li 5,20; bl _s802511C0_26; addi 3,31,244; li 4,0; li 5,4; bl _s802511C0_27; addi 3,31,12288; li 4,0; li 5,192; bl _s802511C0_28; addi 3,31,12488; li 4,0; li 5,12; bl _s802511C0_29; addi 3,31,12514; li 4,0; li 5,1; bl _s802511C0_30; lwz 0,0x34(1); lwz 31,0x2c(1); lwz 30,0x28(1); lwz 29,0x24(1); lwz 28,0x20(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s802511C0_0();
extern "C" void _s802511C0_1();
extern "C" void _s802511C0_2();
extern "C" void _s802511C0_3();
extern "C" void _s802511C0_4();
extern "C" void _s802511C0_5();
extern "C" void _s802511C0_6();
extern "C" void _s802511C0_7();
extern "C" void _s802511C0_8();
extern "C" void _s802511C0_9();
extern "C" void _s802511C0_10();
extern "C" void _s802511C0_11();
extern "C" void _s802511C0_12();
extern "C" void _s802511C0_13();
extern "C" void _s802511C0_14();
extern "C" void _s802511C0_15();
extern "C" void _s802511C0_16();
extern "C" void _s802511C0_17();
extern "C" void _s802511C0_18();
extern "C" void _s802511C0_19();
extern "C" void _s802511C0_20();
extern "C" void _s802511C0_21();
extern "C" void _s802511C0_22();
extern "C" void _s802511C0_23();
extern "C" void _s802511C0_24();
extern "C" void _s802511C0_25();
extern "C" void _s802511C0_26();
extern "C" void _s802511C0_27();
extern "C" void _s802511C0_28();
extern "C" void _s802511C0_29();
extern "C" void _s802511C0_30();
extern "C" void f_802511C0() {}
