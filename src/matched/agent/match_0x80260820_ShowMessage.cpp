// 0x80260820 ShowMessage (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); lwz 3,-18472(13); lwz 0,-18468(13); stw 3,0x14(1); stw 0,0x10(1); bl _s80260820_0; cmplwi 3,0; bne 1f; bl _s80260820_1; rlwinm 0,3,0,16,31; cmplwi 0,1; bne 0f; lwz 5,-27704(13); b 2f; 0:; lwz 5,-27700(13); b 2f; 1:; bl _s80260820_2; lis 4,-32704; rlwinm 3,3,2,22,29; addi 0,4,1096; add 3,0,3; lwz 5,0x0(3); 2:; lwz 6,0x14(1); addi 4,1,8; lwz 0,0x10(1); addi 3,1,12; stw 6,0x8(1); stw 0,0xc(1); bl _s80260820_3; lwz 0,0x1c(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80260820_0();
extern "C" void _s80260820_1();
extern "C" void _s80260820_2();
extern "C" void _s80260820_3();
extern "C" void f_80260820() {}
