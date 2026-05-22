// 0x8032E88C DvdCheck(void) (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); bl _s8032E88C_0; mr 30,3; cmpwi 30,6; bgt 0f; cmpwi 30,4; bge 1f; cmpwi 30,0; beq 9f; cmpwi 30,2; beq 9f; b 6f; 0:; cmpwi 30,8; beq 9f; cmpwi 30,11; bne 6f; 1:; lwz 0,-26464(13); stw 30,-22560(13); cmpwi 0,0; bne 9f; bl _s8032E88C_1; li 31,1; cmpwi 3,0; bne 2f; li 31,0; 2:; lis 3,-32717; li 28,0; addi 3,3,-6492; bl _s8032E88C_2; stw 3,-26500(13); lis 3,-32717; addi 3,3,-6488; bl _s8032E88C_3; stw 3,-26496(13); lis 3,-32692; addi 3,3,23328; bl _s8032E88C_4; mr 3,31; bl _s8032E88C_5; li 3,0; li 4,0; bl _s8032E88C_6; li 3,1; li 4,0; bl _s8032E88C_7; li 3,2; li 4,0; bl _s8032E88C_8; li 3,3; li 4,0; bl _s8032E88C_9; lis 9,-32691; addi 31,9,21688; lwz 0,0x34c(31); cmpwi 0,0; beq 3f; addi 28,31,868; 3:; cmpwi 28,0; bne 4f; mr 3,31; addi 4,1,8; addi 5,1,12; bl _s8032E88C_10; lwz 0,0x34c(31); cmpwi 0,0; beq 4f; addi 28,31,868; 4:; lhz 9,0x4(28); lis 3,-32691; lhz 0,0x8(28); addi 3,3,21688; addi 9,9,15; rlwinm 9,9,0,16,27; mullw 9,9,0; add 29,9,9; bl _s8032E88C_11; lis 9,-32692; mr 31,3; lwz 0,0x47d0(9); cmpwi 0,0; beq 5f; mr 3,30; mtspr 8,0; blrl; 5:; bl _s8032E88C_12; lhz 4,0x4(28); mr 5,29; mr 3,31; bl _s8032E88C_13; bl _s8032E88C_14; mr 3,30; bl _s8032E88C_15; mr 5,3; li 4,180; li 3,20; bl _s8032E88C_16; mr 4,29; mr 3,31; bl _s8032E88C_17; mr 3,31; bl _s8032E88C_18; bl _s8032E88C_19; bl _s8032E88C_20; lwz 9,-26460(13); li 0,1; stw 0,-26464(13); addi 9,9,1; stw 9,-26460(13); b 9f; 6:; lwz 0,-26464(13); cmpwi 0,0; beq 8f; bl _s8032E88C_21; li 31,1; cmpwi 3,0; bne 7f; li 31,0; 7:; lwz 3,-26500(13); bl _s8032E88C_22; lwz 3,-26496(13); bl _s8032E88C_23; li 0,0; lis 3,-32692; stw 0,-26496(13); addi 3,3,23328; stw 0,-26500(13); bl _s8032E88C_24; mr 3,31; bl _s8032E88C_25; 8:; li 0,0; stw 0,-26464(13); 9:; lwz 0,-26464(13); cmpwi 0,0; beq 10f; lis 31,-32692; addi 3,31,28224; bl _s8032E88C_26; mr. 3,3; bne 10f; lis 4,-32692; lis 7,-32717; stw 3,-26412(13); addi 4,4,28288; addi 3,31,28224; addi 7,7,-8128; li 5,32; li 6,0; li 8,2; bl _s8032E88C_27; 10:; lwz 3,-26464(13); xori 3,3,1; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8032E88C_0();
extern "C" void _s8032E88C_1();
extern "C" void _s8032E88C_2();
extern "C" void _s8032E88C_3();
extern "C" void _s8032E88C_4();
extern "C" void _s8032E88C_5();
extern "C" void _s8032E88C_6();
extern "C" void _s8032E88C_7();
extern "C" void _s8032E88C_8();
extern "C" void _s8032E88C_9();
extern "C" void _s8032E88C_10();
extern "C" void _s8032E88C_11();
extern "C" void _s8032E88C_12();
extern "C" void _s8032E88C_13();
extern "C" void _s8032E88C_14();
extern "C" void _s8032E88C_15();
extern "C" void _s8032E88C_16();
extern "C" void _s8032E88C_17();
extern "C" void _s8032E88C_18();
extern "C" void _s8032E88C_19();
extern "C" void _s8032E88C_20();
extern "C" void _s8032E88C_21();
extern "C" void _s8032E88C_22();
extern "C" void _s8032E88C_23();
extern "C" void _s8032E88C_24();
extern "C" void _s8032E88C_25();
extern "C" void _s8032E88C_26();
extern "C" void _s8032E88C_27();
extern "C" void f_8032E88C() {}
