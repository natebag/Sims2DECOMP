// 0x80254830 OSSetThreadPriority (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); mr. 31,4; stw 30,0x18(1); stw 29,0x14(1); addi 29,3,0; blt 0f; cmpwi 31,31; ble 1f; 0:; li 3,0; b 5f; 1:; bl _s80254830_0; lwz 0,0x2d4(29); addi 30,3,0; cmpw 0,31; beq 4f; stw 31,0x2d4(29); mr 31,29; 2:; lwz 0,0x2cc(31); cmpwi 0,0; bgt 3f; mr 3,31; bl _s80254830_1; lwz 0,0x2d0(31); addi 4,3,0; cmpw 0,4; beq 3f; mr 3,31; bl _s80254830_2; mr. 31,3; bne 2b; 3:; lwz 0,-23580(13); cmpwi 0,0; beq 4f; li 3,0; bl _s80254830_3; 4:; mr 3,30; bl _s80254830_4; li 3,1; 5:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80254830_0();
extern "C" void _s80254830_1();
extern "C" void _s80254830_2();
extern "C" void _s80254830_3();
extern "C" void _s80254830_4();
extern "C" void f_80254830() {}
