// 0x8038A5E8 GXGetVtxAttrFmtv (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); li 31,9; stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; 0:; stw 31,0x0(30); addi 3,29,0; addi 4,31,0; addi 5,30,4; addi 6,30,8; addi 7,30,12; bl _s8038A5E8_0; addi 31,31,1; cmpwi 31,20; addi 30,30,16; ble 0b; li 0,255; stw 0,0x0(30); lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038A5E8_0();
extern "C" void f_8038A5E8() {}
