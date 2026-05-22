// 0x80254640 OSSleepThread (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80254640_0; lis 4,-32768; lwz 4,0xe4(4); li 0,4; mr 31,3; sth 0,0x2c8(4); stw 30,0x2dc(4); lwz 5,0x0(30); b 1f; 0:; lwz 5,0x2e0(5); 1:; cmplwi 5,0; beq 2f; lwz 3,0x2d0(5); lwz 0,0x2d0(4); cmpw 3,0; ble 0b; 2:; cmplwi 5,0; bne 5f; lwz 3,0x4(30); cmplwi 3,0; bne 3f; stw 4,0x0(30); b 4f; 3:; stw 4,0x2e0(3); 4:; stw 3,0x2e4(4); li 0,0; stw 0,0x2e0(4); stw 4,0x4(30); b 7f; 5:; stw 5,0x2e0(4); lwz 3,0x2e4(5); stw 4,0x2e4(5); cmplwi 3,0; stw 3,0x2e4(4); bne 6f; stw 4,0x0(30); b 7f; 6:; stw 4,0x2e0(3); 7:; li 0,1; stw 0,-23580(13); lwz 0,-23580(13); cmpwi 0,0; beq 8f; li 3,0; bl _s80254640_1; 8:; mr 3,31; bl _s80254640_2; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80254640_0();
extern "C" void _s80254640_1();
extern "C" void _s80254640_2();
extern "C" void f_80254640() {}
