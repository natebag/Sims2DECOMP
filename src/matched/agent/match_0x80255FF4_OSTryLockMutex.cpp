// 0x80255FF4 OSTryLockMutex (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s80255FF4_0; mr 31,3; bl _s80255FF4_1; lwz 0,0x8(29); cmplwi 0,0; bne 2f; stw 3,0x8(29); lwz 4,0xc(29); addi 0,4,1; stw 0,0xc(29); lwz 4,0x2f8(3); cmplwi 4,0; bne 0f; stw 29,0x2f4(3); b 1f; 0:; stw 29,0x10(4); 1:; stw 4,0x14(29); li 0,0; li 30,1; stw 0,0x10(29); stw 29,0x2f8(3); b 4f; 2:; cmplw 0,3; bne 3f; lwz 3,0xc(29); li 30,1; addi 0,3,1; stw 0,0xc(29); b 4f; 3:; li 30,0; 4:; mr 3,31; bl _s80255FF4_2; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80255FF4_0();
extern "C" void _s80255FF4_1();
extern "C" void _s80255FF4_2();
extern "C" void f_80255FF4() {}
