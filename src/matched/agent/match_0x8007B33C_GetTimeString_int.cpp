// 0x8007B33C GetTimeString(int, (696 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1096(1); mfspr 0,8; stmw 23,0x424(1); stw 0,0x44c(1); addi 30,1,8; mr 31,3; mr 24,4; li 5,256; addi 4,30,8; mr 27,6; mr 3,30; li 29,0; bl _s8007B33C_0; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,26360; addi 3,1,1048; crxor 6,6,6; bl _s8007B33C_1; lwz 9,0x418(1); cmpwi 9,0; beq 0f; lwz 29,0x0(9); 0:; addi 4,1,536; addi 3,1,528; li 5,256; li 25,1; bl _s8007B33C_2; li 23,0; addi 3,1,528; li 5,-1; mr 4,29; bl _s8007B33C_3; addi 4,1,528; mr 3,30; bl _s8007B33C_4; addi 3,13,-24876; bl _s8007B33C_5; mr 4,3; li 5,0; mr 3,30; bl _s8007B33C_6; cmpwi 3,-1; beq 2f; lis 0,10922; srawi 9,31,31; ori 0,0,43691; cmpwi 7,31,12; mulhw 0,31,0; cror 31,30,29; mfcr 23; rlwinm 23,23,0,31,31; srawi 0,0,1; subf 0,9,0; mulli 0,0,12; subf. 31,0,31; bne 1f; li 31,12; 1:; li 25,0; 2:; lis 29,-32696; mr 3,27; bl _s8007B33C_7; addi 26,29,22460; li 28,0; mr 4,26; li 5,32; li 6,2; mr 3,24; sth 28,0x57bc(29); bl _s8007B33C_8; cmpwi 25,0; addi 3,1,8; mfcr 25; bl _s8007B33C_9; mr 30,3; addi 3,13,-24880; bl _s8007B33C_10; mr 4,3; mr 5,26; mr 3,30; mr 6,27; bl _s8007B33C_11; sth 28,0x57bc(29); mtcrf 128,25; bne 3f; mr 4,26; li 5,32; li 6,0; mr 3,31; bl _s8007B33C_12; mr 3,27; bl _s8007B33C_13; mr 30,3; addi 3,13,-24888; bl _s8007B33C_14; mr 4,3; mr 5,26; mr 3,30; mr 6,27; bl _s8007B33C_15; b 4f; 3:; mr 4,26; li 5,32; li 6,2; mr 3,31; bl _s8007B33C_16; mr 3,27; bl _s8007B33C_17; mr 30,3; addi 3,13,-24884; bl _s8007B33C_18; mr 4,3; mr 5,26; mr 3,30; mr 6,27; bl _s8007B33C_19; 4:; lis 9,-32696; li 0,0; sth 0,0x57bc(9); mr 3,27; bl _s8007B33C_20; mr 30,3; addi 3,13,-24844; bl _s8007B33C_21; mr 31,3; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,26372; addi 3,1,1052; crxor 6,6,6; bl _s8007B33C_22; lwz 9,0x41c(1); li 5,0; cmpwi 9,0; beq 5f; lwz 5,0x0(9); 5:; mr 3,30; mr 4,31; mr 6,27; bl _s8007B33C_23; mtcrf 128,25; bne 7f; cmpwi 23,0; beq 6f; mr 3,27; bl _s8007B33C_24; mr 30,3; addi 3,13,-24876; bl _s8007B33C_25; mr 4,3; lis 5,-32707; mr 3,30; addi 5,5,26388; mr 6,27; bl _s8007B33C_26; b 7f; 6:; mr 3,27; bl _s8007B33C_27; mr 30,3; addi 3,13,-24876; bl _s8007B33C_28; mr 4,3; lis 5,-32707; mr 3,30; addi 5,5,26396; mr 6,27; bl _s8007B33C_29; 7:; lwz 0,0x44c(1); mtspr 8,0; lmw 23,0x424(1); addi 1,1,1096"
extern "C" void _s8007B33C_0();
extern "C" void _s8007B33C_1();
extern "C" void _s8007B33C_2();
extern "C" void _s8007B33C_3();
extern "C" void _s8007B33C_4();
extern "C" void _s8007B33C_5();
extern "C" void _s8007B33C_6();
extern "C" void _s8007B33C_7();
extern "C" void _s8007B33C_8();
extern "C" void _s8007B33C_9();
extern "C" void _s8007B33C_10();
extern "C" void _s8007B33C_11();
extern "C" void _s8007B33C_12();
extern "C" void _s8007B33C_13();
extern "C" void _s8007B33C_14();
extern "C" void _s8007B33C_15();
extern "C" void _s8007B33C_16();
extern "C" void _s8007B33C_17();
extern "C" void _s8007B33C_18();
extern "C" void _s8007B33C_19();
extern "C" void _s8007B33C_20();
extern "C" void _s8007B33C_21();
extern "C" void _s8007B33C_22();
extern "C" void _s8007B33C_23();
extern "C" void _s8007B33C_24();
extern "C" void _s8007B33C_25();
extern "C" void _s8007B33C_26();
extern "C" void _s8007B33C_27();
extern "C" void _s8007B33C_28();
extern "C" void _s8007B33C_29();
extern "C" void f_8007B33C() {}
