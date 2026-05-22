// 0x8005BE08 {anonymous}::HandleEffectNote(cXPerson (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 26,0x10(1); stw 0,0x2c(1); stw 12,0xc(1); mr 26,4; mr 27,5; mr. 3,3; beq 5f; bl _s8005BE08_0; mr. 30,3; blt 5f; lis 9,-32697; rlwinm 0,30,2,0,29; addi 31,9,24012; mr 29,0; addi 9,31,188; lwzx 11,9,0; cmpwi 11,0; beq 5f; lwz 9,0x4(11); lha 3,0x330(9); lwz 0,0x334(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 5f; cmpwi 4,27,13; bne cr4,0f; addi 9,31,280; lwzx 3,9,29; bl _s8005BE08_1; mr 4,3; mr 3,26; bl _s8005BE08_2; b 2f; 0:; cmpwi 27,14; bne 1f; addi 9,31,280; lwzx 3,9,29; bl _s8005BE08_3; mr 4,3; mr 3,26; bl _s8005BE08_4; b 2f; 1:; cmpwi 27,15; bne 2f; addi 9,31,280; lwzx 3,9,29; bl _s8005BE08_5; mr 4,3; mr 3,26; bl _s8005BE08_6; 2:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 5f; lis 11,-32697; addi 9,30,1; addi 28,11,24012; rlwinm 0,9,1,31,31; addi 30,28,188; add 0,9,0; lwzx 10,30,29; rlwinm 0,0,0,0,30; subf 29,0,9; lwz 11,0x4(10); rlwinm 31,29,2,0,29; lwz 0,0x36c(11); lha 3,0x368(11); mtspr 8,0; add 3,10,3; blrl; lwzx 0,30,31; cmpw 3,0; bne 5f; mr 3,29; bl _s8005BE08_7; cmpwi 3,0; beq 5f; bne cr4,3f; addi 9,28,280; lwzx 3,9,31; bl _s8005BE08_8; mr 4,3; mr 3,26; bl _s8005BE08_9; b 5f; 3:; cmpwi 27,14; bne 4f; addi 9,28,280; lwzx 3,9,31; bl _s8005BE08_10; mr 4,3; mr 3,26; bl _s8005BE08_11; b 5f; 4:; cmpwi 27,15; bne 5f; addi 9,28,280; lwzx 3,9,31; bl _s8005BE08_12; mr 4,3; mr 3,26; bl _s8005BE08_13; 5:; lwz 0,0x2c(1); lwz 12,0xc(1); mtspr 8,0; lmw 26,0x10(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s8005BE08_0();
extern "C" void _s8005BE08_1();
extern "C" void _s8005BE08_2();
extern "C" void _s8005BE08_3();
extern "C" void _s8005BE08_4();
extern "C" void _s8005BE08_5();
extern "C" void _s8005BE08_6();
extern "C" void _s8005BE08_7();
extern "C" void _s8005BE08_8();
extern "C" void _s8005BE08_9();
extern "C" void _s8005BE08_10();
extern "C" void _s8005BE08_11();
extern "C" void _s8005BE08_12();
extern "C" void _s8005BE08_13();
extern "C" void f_8005BE08() {}
