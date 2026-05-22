// 0x803B239C void (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 31,6; mr 29,3; mr 28,5; cmplw 31,30; ble 1f; bl _s803B239C_0; cmpwi 3,0; beq 0f; li 9,0; stw 9,0x0(9); 0:; .long 0x00000001; 1:; mr 4,30; rlwinm 9,31,2,0,29; subf. 0,31,4; mtspr 9,0; beq 3f; rlwinm 0,4,2,0,29; add 4,0,29; 2:; lwz 0,-4(4); stw 0,0x0(4); addi 4,4,-4; bdnz 2b; 3:; lwz 0,0x0(28); stwx 0,9,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803B239C_0();
extern "C" void f_803B239C() {}
