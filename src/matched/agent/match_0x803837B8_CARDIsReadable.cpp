// 0x803837B8 __CARDIsReadable (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); mr 27,4; lwz 28,0x10c(3); bl _s803837B8_0; addi 29,3,0; cmpwi 29,-10; bne 1f; lbz 3,0x34(27); lbz 0,-25334(13); and 0,3,0; rlwinm 30,0,0,24,31; rlwinm. 0,0,0,26,26; beq 0f; lis 3,-32688; addi 31,3,-23456; addi 3,27,0; addi 4,31,0; li 5,4; bl _s803837B8_1; cmpwi 3,0; bne 0f; addi 3,27,4; addi 4,31,4; li 5,2; bl _s803837B8_2; cmpwi 3,0; bne 0f; li 29,0; b 1f; 0:; rlwinm. 0,30,0,25,25; beq 1f; lis 3,-32688; addi 4,3,-23456; addi 3,27,0; li 5,4; bl _s803837B8_3; cmpwi 3,0; bne 1f; addi 3,27,4; addi 4,28,4; li 5,2; bl _s803837B8_4; cmpwi 3,0; bne 1f; li 29,0; 1:; cmpwi 29,-10; bne 2f; lbz 0,0x34(27); rlwinm. 0,0,0,29,29; beq 2f; li 3,0; b 3f; 2:; mr 3,29; 3:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s803837B8_0();
extern "C" void _s803837B8_1();
extern "C" void _s803837B8_2();
extern "C" void _s803837B8_3();
extern "C" void _s803837B8_4();
extern "C" void f_803837B8() {}
