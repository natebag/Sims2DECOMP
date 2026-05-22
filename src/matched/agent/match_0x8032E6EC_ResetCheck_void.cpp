// 0x8032E6EC ResetCheck(void) (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,-26480(13); li 29,0; li 31,0; cmpwi 0,0; beq 0f; bl _s8032E6EC_0; cmpwi 3,0; bne 0f; lis 3,-32717; stw 29,-26480(13); addi 3,3,-6484; li 31,1; bl _s8032E6EC_1; 0:; cmpwi 31,0; bne 1f; lwz 0,-26400(13); cmpwi 0,0; bne 1f; lwz 0,-26484(13); cmpwi 0,0; beq 8f; 1:; bl _s8032E6EC_2; li 30,1; cmpwi 3,0; bne 2f; li 30,0; 2:; lwz 9,-26512(13); li 31,0; lwz 0,0xc(9); cmpwi 0,0; beq 3f; addi 3,13,-22552; bl _s8032E6EC_3; cmpwi 3,0; bne 3f; lwz 0,-26748(13); subfic 9,0,0; adde 31,9,0; 3:; cmpwi 31,0; beq 7f; lis 3,-32717; addi 3,3,-6492; bl _s8032E6EC_4; stw 3,-26500(13); lis 3,-32717; addi 3,3,-6488; bl _s8032E6EC_5; stw 3,-26496(13); lis 3,-32692; addi 3,3,23328; bl _s8032E6EC_6; mr 3,30; bl _s8032E6EC_7; li 0,0; li 9,1; stw 0,-26400(13); stw 9,-26472(13); bl _s8032E6EC_8; bl _s8032E6EC_9; bl _s8032E6EC_10; li 3,1; bl _s8032E6EC_11; bl _s8032E6EC_12; bl _s8032E6EC_13; bl _s8032E6EC_14; lis 3,-4096; bl _s8032E6EC_15; lis 3,-32692; addi 3,3,9472; bl _s8032E6EC_16; cmpwi 29,0; beq 4f; li 3,1; li 4,0; li 5,1; bl _s8032E6EC_17; b 8f; 4:; bl _s8032E6EC_18; cmpwi 3,0; beq 5f; lwz 0,-26464(13); cmpwi 0,0; li 3,0; beq 6f; 5:; li 3,1; 6:; li 4,0; li 5,0; bl _s8032E6EC_19; b 8f; 7:; mr 3,30; bl _s8032E6EC_20; li 0,1; stw 0,-26400(13); 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8032E6EC_0();
extern "C" void _s8032E6EC_1();
extern "C" void _s8032E6EC_2();
extern "C" void _s8032E6EC_3();
extern "C" void _s8032E6EC_4();
extern "C" void _s8032E6EC_5();
extern "C" void _s8032E6EC_6();
extern "C" void _s8032E6EC_7();
extern "C" void _s8032E6EC_8();
extern "C" void _s8032E6EC_9();
extern "C" void _s8032E6EC_10();
extern "C" void _s8032E6EC_11();
extern "C" void _s8032E6EC_12();
extern "C" void _s8032E6EC_13();
extern "C" void _s8032E6EC_14();
extern "C" void _s8032E6EC_15();
extern "C" void _s8032E6EC_16();
extern "C" void _s8032E6EC_17();
extern "C" void _s8032E6EC_18();
extern "C" void _s8032E6EC_19();
extern "C" void _s8032E6EC_20();
extern "C" void f_8032E6EC() {}
