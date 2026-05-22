// 0x80384730 CARDWriteAsync (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 27,0x24(1); addi 28,6,0; addi 27,5,0; addi 31,4,0; addi 30,3,0; addi 29,7,0; addi 4,27,0; addi 5,28,0; addi 6,1,28; bl _s80384730_0; cmpwi 3,0; bge 0f; b 7f; 0:; lwz 3,0x1c(1); lwz 4,0xc(3); addi 4,4,-1; and. 0,28,4; bne 1f; and. 0,27,4; beq 2f; 1:; li 4,-128; bl _s80384730_1; b 7f; 2:; bl _s80384730_2; lwz 0,0x4(30); rlwinm 0,0,6,0,25; add 4,3,0; lwz 3,0x1c(1); bl _s80384730_3; mr. 4,3; bge 3f; lwz 3,0x1c(1); bl _s80384730_4; b 7f; 3:; addi 3,31,0; addi 4,27,0; bl _s80384730_5; cmplwi 29,0; beq 4f; mr 0,29; b 5f; 4:; lis 3,-32712; addi 0,3,-4304; 5:; lwz 4,0x1c(1); lis 3,-32712; addi 5,3,18048; stw 0,0xd0(4); lwz 3,0x1c(1); stw 31,0xb4(3); lwz 3,0x1c(1); lhz 0,0x10(30); lwz 4,0xc(3); lwz 3,0x0(30); mullw 4,4,0; bl _s80384730_6; mr. 30,3; bge 6f; lwz 3,0x1c(1); mr 4,30; bl _s80384730_7; 6:; mr 3,30; 7:; lmw 27,0x24(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80384730_0();
extern "C" void _s80384730_1();
extern "C" void _s80384730_2();
extern "C" void _s80384730_3();
extern "C" void _s80384730_4();
extern "C" void _s80384730_5();
extern "C" void _s80384730_6();
extern "C" void _s80384730_7();
extern "C" void f_80384730() {}
