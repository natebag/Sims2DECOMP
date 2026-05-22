// 0x800CC9E8 NeighborList::DeleteAll(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); mr 30,3; addi 29,1,8; lwz 31,0x0(30); addi 28,1,32; lwz 0,0x4(30); cmpw 31,0; beq 2f; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; li 4,3; bl _s800CC9E8_0; 1:; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 0b; 2:; li 0,0; addi 8,29,8; stw 0,0x8(1); addi 7,30,8; stw 0,0x4(29); stw 0,0x4(8); lwz 0,0x4(30); lwz 9,0x0(30); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x0(30); lwz 0,0x4(8); stw 10,0x4(30); stw 0,0x4(28); lwz 9,0x8(30); lwz 0,0x4(7); stw 9,0x8(29); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(30); stw 0,0x4(7); lwz 3,0x8(1); cmpwi 3,0; beq 4f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 3f; bl _s800CC9E8_1; b 4f; 3:; bl _s800CC9E8_2; 4:; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s800CC9E8_0();
extern "C" void _s800CC9E8_1();
extern "C" void _s800CC9E8_2();
extern "C" void f_800CC9E8() {}
