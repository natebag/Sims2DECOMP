// 0x803822D0 CARDProbeEx (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); mr. 27,3; addi 28,4,0; addi 31,5,0; blt 0f; cmpwi 27,2; blt 1f; 0:; li 3,-128; b 15f; 1:; lis 3,-32768; lbz 0,0x30e3(3); rlwinm. 0,0,0,24,24; beq 2f; li 3,-3; b 15f; 2:; mulli 4,27,272; lis 3,-32688; addi 0,3,-24000; add 30,0,4; bl _s803822D0_0; addi 29,3,0; addi 3,27,0; bl _s803822D0_1; cmpwi 3,-1; bne 3f; li 30,-3; b 14f; 3:; cmpwi 3,0; bne 4f; li 30,-1; b 14f; 4:; lwz 0,0x0(30); cmpwi 0,0; beq 8f; lwz 0,0x24(30); cmpwi 0,1; bge 5f; li 30,-1; b 14f; 5:; cmplwi 28,0; beq 6f; lhz 0,0x8(30); stw 0,0x0(28); 6:; cmplwi 31,0; beq 7f; lwz 0,0xc(30); stw 0,0x0(31); 7:; li 30,0; b 14f; 8:; mr 3,27; bl _s803822D0_2; rlwinm. 0,3,0,28,28; beq 9f; li 30,-2; b 14f; 9:; addi 3,27,0; addi 5,1,20; li 4,0; bl _s803822D0_3; cmpwi 3,0; bne 10f; li 30,-1; b 14f; 10:; lwz 3,0x14(1); bl _s803822D0_4; cmpwi 3,0; beq 13f; cmplwi 28,0; beq 11f; lwz 0,0x14(1); rlwinm 0,0,0,24,29; stw 0,0x0(28); 11:; cmplwi 31,0; beq 12f; lwz 4,0x14(1); lis 3,-32698; addi 0,3,-27464; rlwinm 3,4,23,27,29; add 3,0,3; lwz 0,0x0(3); stw 0,0x0(31); 12:; li 30,0; b 14f; 13:; li 30,-2; 14:; mr 3,29; bl _s803822D0_5; mr 3,30; 15:; lmw 27,0x1c(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s803822D0_0();
extern "C" void _s803822D0_1();
extern "C" void _s803822D0_2();
extern "C" void _s803822D0_3();
extern "C" void _s803822D0_4();
extern "C" void _s803822D0_5();
extern "C" void f_803822D0() {}
