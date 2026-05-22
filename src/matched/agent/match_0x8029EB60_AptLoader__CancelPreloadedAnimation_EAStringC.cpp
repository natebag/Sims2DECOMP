// 0x8029EB60 AptLoader::CancelPreloadedAnimation(EAStringC (788 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 24,0x38(1); stw 0,0x5c(1); mr 27,3; mr 5,4; addi 3,1,8; mr 4,27; bl _s8029EB60_0; lwz 3,0x8(1); cmpwi 3,0; beq 21f; lwz 9,0x8(3); cmpwi 9,1; beq 19f; cmpwi 9,2; bne 0f; lwz 3,0x14(3); cmpwi 3,0; beq 19f; lis 9,-32694; lwz 0,-16252(9); mtspr 8,0; blrl; b 19f; 0:; addi 0,9,-3; cmplwi 0,2; bgt 19f; lwz 9,0x10(3); li 30,0; lwz 0,0x28(9); cmpw 30,0; bge 19f; addi 24,1,16; 1:; lwz 10,0x10(3); rlwinm 11,30,4,0,27; addi 3,1,24; mr 26,11; lwz 9,0x2c(10); lwzx 4,11,9; bl _s8029EB60_1; mr 4,27; mr 3,24; addi 5,1,24; bl _s8029EB60_2; lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 2f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029EB60_3; 2:; lwz 3,0x10(1); li 0,1; cmpwi 7,3,0; bne cr7,3f; li 0,0; 3:; cmpwi 0,0; addi 25,30,1; beq 17f; stw 3,0x18(1); beq cr7,4f; bl _s8029EB60_4; 4:; lwz 9,-22996(13); lwz 0,0x0(9); b 13f; 5:; li 30,1; b 10f; 6:; lwz 9,0x0(9); lwz 3,0x18(1); lwz 31,0x4(9); stw 3,0x28(1); cmpwi 3,0; beq 7f; bl _s8029EB60_5; 7:; li 28,0; li 29,0; b 9f; 8:; mr 3,31; bl _s8029EB60_6; lwz 9,0x2c(3); addi 3,1,48; lwzx 4,29,9; bl _s8029EB60_7; lwz 4,0x28(1); addi 3,1,48; addi 4,4,4; bl _s8029EB60_8; mr 30,3; li 4,2; addi 3,1,48; bl _s8029EB60_9; cmpwi 30,0; bne 5b; addi 29,29,16; addi 28,28,1; 9:; mr 3,31; bl _s8029EB60_10; lwz 0,0x28(3); cmpw 28,0; blt 8b; li 30,0; 10:; lwz 3,0x28(1); cmpwi 3,0; beq 11f; bl _s8029EB60_11; cmpwi 3,0; bne 11f; lwz 3,0x28(1); bl _s8029EB60_12; 11:; cmpwi 30,0; beq 12f; li 30,1; b 15f; 12:; lwz 9,0x20(1); lwz 0,0x4(9); 13:; stw 0,0x20(1); li 0,0; lwz 9,0x20(1); stw 0,0x28(1); li 0,1; cmpwi 9,0; bne 14f; li 0,0; 14:; cmpwi 0,0; bne 6b; li 30,0; 15:; lwz 3,0x18(1); cmpwi 3,0; beq 16f; bl _s8029EB60_13; cmpwi 3,0; bne 16f; lwz 3,0x18(1); bl _s8029EB60_14; 16:; cmpwi 30,0; bne 17f; lwz 10,0x8(1); addi 3,1,32; lwz 9,0x10(10); lwz 11,0x2c(9); lwzx 4,26,11; bl _s8029EB60_15; addi 4,1,32; mr 3,27; bl _s8029EB60_16; lwz 4,0x20(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 17f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029EB60_17; 17:; lwz 3,0x10(1); cmpwi 3,0; beq 18f; bl _s8029EB60_18; cmpwi 3,0; bne 18f; lwz 3,0x10(1); bl _s8029EB60_19; 18:; lwz 9,0x8(1); mr 30,25; lwz 11,0x10(9); mr 3,9; lwz 0,0x28(11); cmpw 30,0; blt 1b; 19:; lwz 3,0x8(1); cmpwi 3,0; beq 20f; bl _s8029EB60_20; cmpwi 3,0; bne 20f; lwz 3,0x8(1); bl _s8029EB60_21; 20:; lwz 3,0x8(1); cmpwi 3,0; beq 21f; bl _s8029EB60_22; cmpwi 3,0; bne 21f; lwz 3,0x8(1); bl _s8029EB60_23; 21:; lwz 0,0x5c(1); mtspr 8,0; lmw 24,0x38(1); addi 1,1,88"
extern "C" void _s8029EB60_0();
extern "C" void _s8029EB60_1();
extern "C" void _s8029EB60_2();
extern "C" void _s8029EB60_3();
extern "C" void _s8029EB60_4();
extern "C" void _s8029EB60_5();
extern "C" void _s8029EB60_6();
extern "C" void _s8029EB60_7();
extern "C" void _s8029EB60_8();
extern "C" void _s8029EB60_9();
extern "C" void _s8029EB60_10();
extern "C" void _s8029EB60_11();
extern "C" void _s8029EB60_12();
extern "C" void _s8029EB60_13();
extern "C" void _s8029EB60_14();
extern "C" void _s8029EB60_15();
extern "C" void _s8029EB60_16();
extern "C" void _s8029EB60_17();
extern "C" void _s8029EB60_18();
extern "C" void _s8029EB60_19();
extern "C" void _s8029EB60_20();
extern "C" void _s8029EB60_21();
extern "C" void _s8029EB60_22();
extern "C" void _s8029EB60_23();
extern "C" void f_8029EB60() {}
