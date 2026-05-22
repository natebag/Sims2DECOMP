// 0x80119EB0 ActionQueue::CountVisible(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; li 26,0; lwz 9,0x2ac(30); li 29,0; lwz 0,0x2a8(30); li 28,0; subf. 11,0,9; ble 2f; lis 27,-13108; ori 27,27,52429; 0:; lwz 9,0x2a8(30); mr 3,30; add 9,9,29; mulhwu 0,9,27; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 31,30,9; mr 4,31; bl _s80119EB0_0; cmpwi 3,0; beq 1f; lwz 4,0x38(31); cmpw 26,4; beq 1f; extsh 26,4; addi 28,28,1; 1:; lwz 9,0x2ac(30); addi 29,29,1; lwz 0,0x2a8(30); subf 9,0,9; cmpw 29,9; blt 0b; 2:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80119EB0_0();
extern "C" void f_80119EB0() {}
