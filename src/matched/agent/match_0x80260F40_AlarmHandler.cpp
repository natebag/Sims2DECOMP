// 0x80260F40 AlarmHandler (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); addi 4,3,-16952; stwu 1,-8(1); lwz 0,-23292(13); mulli 0,0,20; lwzx 3,4,0; cmpwi 3,1; bne 0f; lwz 3,-23292(13); add 6,4,0; addi 0,3,1; stw 0,-23292(13); lwz 3,0x4(6); lwz 4,0x8(6); lwz 5,0xc(6); lwz 6,0x10(6); bl _s80260F40_0; b 1f; 0:; cmpwi 3,2; bne 1f; lwz 3,-23292(13); add 4,4,0; addi 0,3,1; stw 0,-23292(13); lwz 3,0xc(4); lwz 4,0x10(4); bl _s80260F40_1; 1:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80260F40_0();
extern "C" void _s80260F40_1();
extern "C" void f_80260F40() {}
