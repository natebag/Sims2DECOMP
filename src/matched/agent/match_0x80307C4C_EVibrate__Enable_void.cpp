// 0x80307C4C EVibrate::Enable(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80307C4C_0; mr. 3,3; bne 1f; li 0,1; stw 3,0x4(31); stw 0,0x0(31); addi 3,31,56; li 11,0; li 10,0; 0:; mulli 9,11,68; addi 0,11,1; rlwinm 11,0,0,24,31; cmplwi 11,1; stwx 10,3,9; ble 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80307C4C_0();
extern "C" void f_80307C4C() {}
