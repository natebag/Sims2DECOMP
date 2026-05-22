// 0x8024D014 LCStoreData (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); stw 28,0x18(1); mr 28,3; mr 29,4; addi 0,5,31; rlwinm 3,0,27,5,31; addi 0,3,127; mr 31,3; rlwinm 30,0,25,7,31; b 0f; 0:; b 1f; 1:; b 4f; 2:; cmplwi 31,128; bge 3f; mr 3,28; mr 4,29; mr 5,31; bl _s8024D014_0; li 31,0; b 4f; 3:; mr 3,28; mr 4,29; li 5,0; bl _s8024D014_1; addi 31,31,-128; addi 28,28,4096; addi 29,29,4096; 4:; cmplwi 31,0; bne 2b; mr 3,30; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8024D014_0();
extern "C" void _s8024D014_1();
extern "C" void f_8024D014() {}
