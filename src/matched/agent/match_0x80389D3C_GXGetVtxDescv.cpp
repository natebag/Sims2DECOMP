// 0x80389D3C GXGetVtxDescv (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); li 31,0; stw 30,0x18(1); li 30,0; stw 29,0x14(1); addi 29,3,0; 0:; add 4,29,31; stw 30,0x0(4); addi 3,30,0; addi 4,4,4; bl _s80389D3C_0; addi 30,30,1; cmpwi 30,20; addi 31,31,8; ble 0b; rlwinm 0,30,3,0,28; add 3,29,0; li 0,25; stw 0,0x0(3); addi 4,3,4; li 3,25; bl _s80389D3C_1; addi 30,30,1; rlwinm 0,30,3,0,28; li 3,255; stwx 3,29,0; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80389D3C_0();
extern "C" void _s80389D3C_1();
extern "C" void f_80389D3C() {}
