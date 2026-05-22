// 0x8038879C GXSetCPUFifo (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s8038879C_0; lwz 0,-21956(13); addi 31,3,0; stw 30,-21960(13); cmplw 30,0; bne 0f; lwz 0,0x0(30); li 8,0; lwz 3,-22000(13); li 6,0; rlwinm 0,0,0,2,31; stw 0,0xc(3); li 0,1; li 3,1; lwz 7,0x4(30); li 4,1; lwz 5,-22000(13); rlwinm 7,7,0,2,31; stw 7,0x10(5); lwz 7,0x18(30); lwz 5,-22000(13); rlwimi 8,7,0,6,26; addi 7,8,0; rlwimi 7,6,26,5,5; stw 7,0x14(5); stb 0,-21948(13); bl _s8038879C_1; li 3,1; li 4,0; bl _s8038879C_2; li 3,1; bl _s8038879C_3; b 2f; 0:; lbz 0,-21948(13); cmplwi 0,0; beq 1f; li 3,0; bl _s8038879C_4; li 0,0; stb 0,-21948(13); 1:; li 3,0; li 4,0; bl _s8038879C_5; lwz 4,0x0(30); li 5,0; lwz 3,-22000(13); li 0,0; rlwinm 4,4,0,2,31; stw 4,0xc(3); lwz 4,0x4(30); lwz 3,-22000(13); rlwinm 4,4,0,2,31; stw 4,0x10(3); lwz 4,0x18(30); lwz 3,-22000(13); rlwimi 5,4,0,6,26; addi 4,5,0; rlwimi 4,0,26,5,5; stw 4,0x14(3); 2:; bl _s8038879C_6; mr 3,31; bl _s8038879C_7; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038879C_0();
extern "C" void _s8038879C_1();
extern "C" void _s8038879C_2();
extern "C" void _s8038879C_3();
extern "C" void _s8038879C_4();
extern "C" void _s8038879C_5();
extern "C" void _s8038879C_6();
extern "C" void _s8038879C_7();
extern "C" void f_8038879C() {}
