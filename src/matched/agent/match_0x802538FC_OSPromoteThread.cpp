// 0x802538FC __OSPromoteThread (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,4; 0:; lwz 0,0x2cc(3); cmpwi 0,0; bgt 1f; lwz 0,0x2d0(3); cmpw 0,31; ble 1f; mr 4,31; bl _s802538FC_0; cmplwi 3,0; bne 0b; 1:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802538FC_0();
extern "C" void f_802538FC() {}
