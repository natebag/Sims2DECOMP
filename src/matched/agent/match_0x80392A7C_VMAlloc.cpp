// 0x80392A7C VMAlloc (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; stw 28,0x10(1); mr 28,4; bl _s80392A7C_0; rlwinm 31,3,20,12,31; bl _s80392A7C_1; lwz 0,-21844(13); rlwinm 3,3,20,12,31; add 30,31,3; cmplw 0,31; bge 0f; stw 31,-21844(13); 0:; bl _s80392A7C_2; lwz 0,-21848(13); add 0,0,28; cmplw 0,3; ble 1f; li 3,0; b 6f; 1:; addi 0,28,4095; li 5,0; rlwinm 0,0,20,12,31; mtspr 9,0; cmplwi 28,0; ble 5f; 2:; add 6,29,5; lwz 4,-21856(13); 3:; lwz 3,-21844(13); addi 0,3,1; cmplw 0,30; stw 0,-21844(13); blt 4f; stw 31,-21844(13); 4:; lwz 0,-21844(13); rlwinm 3,0,2,0,29; lwzx 0,4,3; cmplwi 0,0; bne 3b; stwx 6,4,3; rlwinm 0,6,22,17,29; addi 5,5,4096; lwz 4,-21844(13); lwz 3,-21852(13); rlwinm 4,4,12,0,19; stwx 4,3,0; lwz 3,-21848(13); addi 0,3,4096; stw 0,-21848(13); bdnz 2b; 5:; li 3,1; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s80392A7C_0();
extern "C" void _s80392A7C_1();
extern "C" void _s80392A7C_2();
extern "C" void f_80392A7C() {}
