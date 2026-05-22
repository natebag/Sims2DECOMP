// 0x80242800 atexit (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-27948(13); mr 31,3; lwz 10,0x148(9); cmpwi 10,0; bne 0f; addi 10,9,332; stw 10,0x148(9); 0:; lwz 0,0x4(10); cmpwi 0,31; ble 2f; li 3,136; bl _s80242800_0; mr. 10,3; bne 1f; li 3,-1; b 3f; 1:; lwz 11,-27948(13); li 0,0; stw 0,0x4(10); lwz 9,0x148(11); stw 9,0x0(10); stw 10,0x148(11); 2:; lwz 9,0x4(10); addi 11,10,8; li 3,0; rlwinm 0,9,2,0,29; stwx 31,11,0; addi 9,9,1; stw 9,0x4(10); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80242800_0();
extern "C" void f_80242800() {}
