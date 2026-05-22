// 0x803839FC CARDFastOpen (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); mr. 30,4; stw 29,0x1c(1); addi 29,3,0; stw 28,0x18(1); blt 0f; cmpwi 30,127; blt 1f; 0:; li 3,-128; b 7f; 1:; li 0,-1; stw 0,0x0(31); addi 3,29,0; addi 4,1,20; bl _s803839FC_0; cmpwi 3,0; bge 2f; b 7f; 2:; lwz 3,0x14(1); bl _s803839FC_1; rlwinm 0,30,6,0,25; lwz 4,0x14(1); add 28,3,0; addi 3,4,0; addi 4,28,0; bl _s803839FC_2; cmpwi 3,-10; bne 3f; lbz 0,0x34(28); rlwinm. 0,0,0,29,29; beq 3f; li 3,0; 3:; cmpwi 3,0; addi 4,3,0; blt 6f; lhz 5,0x36(28); cmplwi 5,5; blt 4f; lwz 3,0x14(1); lhz 0,0x10(3); cmplw 5,0; blt 5f; 4:; li 4,-6; b 6f; 5:; stw 29,0x0(31); li 0,0; stw 30,0x4(31); stw 0,0x8(31); lhz 0,0x36(28); sth 0,0x10(31); 6:; lwz 3,0x14(1); bl _s803839FC_3; 7:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s803839FC_0();
extern "C" void _s803839FC_1();
extern "C" void _s803839FC_2();
extern "C" void _s803839FC_3();
extern "C" void f_803839FC() {}
