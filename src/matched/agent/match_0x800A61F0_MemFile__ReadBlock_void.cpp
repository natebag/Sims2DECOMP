// 0x800A61F0 MemFile::ReadBlock(void (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; mr 30,5; bl _s800A61F0_0; li 29,0; cmpwi 3,0; bne 0f; li 3,-49; b 4f; 0:; lwz 9,0x120(31); lwz 0,0x11c(31); subf. 9,0,9; bge 1f; li 0,0; li 29,-48; stw 0,0x0(30); b 3f; 1:; lwz 0,0x0(30); cmpw 0,9; ble 2f; stw 9,0x0(30); li 29,-48; 2:; lwz 0,0x114(31); mr 3,28; lwz 4,0x11c(31); lwz 5,0x0(30); add 4,0,4; bl _s800A61F0_1; lwz 9,0x0(30); lwz 0,0x11c(31); add 0,0,9; stw 0,0x11c(31); 3:; mr 3,29; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A61F0_0();
extern "C" void _s800A61F0_1();
extern "C" void f_800A61F0() {}
