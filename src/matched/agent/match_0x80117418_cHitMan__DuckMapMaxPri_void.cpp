// 0x80117418 cHitMan::DuckMapMaxPri(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); addi 3,3,64; li 31,0; lwz 0,0x4(3); stw 0,0x8(1); lwz 9,0x4(3); lwz 0,0x8(9); stw 0,0x10(1); b 2f; 0:; lwz 0,0x14(9); cmpw 31,0; bge 1f; mr 31,0; 1:; mr 3,9; stw 9,0x20(1); bl _s80117418_0; lwz 0,0x20(1); stw 3,0x10(1); stw 0,0x18(1); 2:; lwz 9,0x10(1); li 11,1; lwz 0,0x8(1); cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 0b; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"
extern "C" void _s80117418_0();
extern "C" void f_80117418() {}
