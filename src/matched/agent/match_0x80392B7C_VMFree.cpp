// 0x80392B7C VMFree (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); stw 31,0x1c(1); stw 30,0x18(1); mr 30,3; rlwinm 0,30,22,17,29; stw 29,0x14(1); mr 29,4; li 4,0; stw 28,0x10(1); lwz 3,-21852(13); add 3,3,0; rlwinm 0,29,22,10,29; add 6,3,0; addi 0,6,3; mr 5,3; subf 0,3,0; rlwinm 0,0,30,2,31; mtspr 9,0; cmplw 3,6; bge 2f; 0:; lwz 0,0x0(5); cmplwi 0,0; bne 1f; li 3,0; b 6f; 1:; lwz 3,-21856(13); rlwinm 0,0,22,11,29; stwx 4,3,0; stw 4,0x0(5); addi 5,5,4; lwz 3,-21848(13); addi 0,3,-4096; stw 0,-21848(13); bdnz 0b; 2:; bl _s80392B7C_0; mr 28,3; add 29,30,29; b 5f; 3:; mr 3,30; bl _s80392B7C_1; cmpwi 3,0; beq 4f; mr 3,30; bl _s80392B7C_2; mr 31,3; bl _s80392B7C_3; subf 0,3,31; mr 3,30; rlwinm 4,0,20,12,31; bl _s80392B7C_4; 4:; addi 30,30,4096; 5:; cmplw 30,29; blt 3b; mr 3,28; bl _s80392B7C_5; li 3,1; 6:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); lwz 28,0x10(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s80392B7C_0();
extern "C" void _s80392B7C_1();
extern "C" void _s80392B7C_2();
extern "C" void _s80392B7C_3();
extern "C" void _s80392B7C_4();
extern "C" void _s80392B7C_5();
extern "C" void f_80392B7C() {}
