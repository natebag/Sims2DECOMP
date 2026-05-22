// 0x80048798 ObjectList::RemoveAll(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 0,0x2c(1); addi 6,1,8; li 0,0; addi 8,6,8; stw 0,0x8(1); addi 7,3,8; stw 0,0x4(6); stw 0,0x4(8); lwz 0,0x4(3); lwz 9,0x0(3); lwz 11,0x8(1); lwz 10,0xc(1); stw 9,0x8(1); stw 0,0xc(1); stw 11,0x0(3); lwz 0,0x4(8); stw 10,0x4(3); stw 0,0x24(1); lwz 9,0x8(3); lwz 0,0x4(7); stw 9,0x8(6); stw 0,0x4(8); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(3); stw 0,0x4(7); lwz 3,0x8(1); cmpwi 3,0; beq 1f; lwz 0,0xc(6); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s80048798_0; b 1f; 0:; bl _s80048798_1; 1:; lwz 0,0x2c(1); mtspr 8,0; addi 1,1,40"
extern "C" void _s80048798_0();
extern "C" void _s80048798_1();
extern "C" void f_80048798() {}
