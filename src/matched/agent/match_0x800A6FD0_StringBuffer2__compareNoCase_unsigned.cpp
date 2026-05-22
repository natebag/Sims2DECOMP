// 0x800A6FD0 StringBuffer2::compareNoCase(unsigned (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,5; mr 28,4; bl _s800A6FD0_0; mr 29,3; mr 3,30; bl _s800A6FD0_1; mr 6,3; mr 7,6; cmpw 6,31; ble 0f; mr 7,31; 0:; li 8,0; cmpw 8,7; bge 4f; li 10,0; 1:; lhzx 11,10,29; lhzx 9,10,28; addi 0,11,-65; cmplwi 0,25; bgt 2f; addi 0,11,32; rlwinm 11,0,0,16,31; 2:; addi 0,9,-65; cmplwi 0,25; bgt 3f; addi 0,9,32; rlwinm 9,0,0,16,31; 3:; subf. 3,9,11; bne 5f; addi 8,8,1; addi 10,10,2; cmpw 8,7; blt 1b; 4:; subf 3,31,6; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A6FD0_0();
extern "C" void _s800A6FD0_1();
extern "C" void f_800A6FD0() {}
