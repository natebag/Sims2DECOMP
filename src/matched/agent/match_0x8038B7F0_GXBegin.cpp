// 0x8038B7F0 GXBegin (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); addi 30,5,0; stw 29,0x1c(1); addi 29,4,0; stw 28,0x18(1); addi 28,3,0; lwz 6,-17720(13); lwz 31,0x5ac(6); cmplwi 31,0; beq 6f; rlwinm. 0,31,0,31,31; beq 0f; bl _s8038B7F0_0; 0:; rlwinm. 0,31,0,30,30; beq 1f; bl _s8038B7F0_1; 1:; rlwinm. 0,31,0,29,29; beq 2f; bl _s8038B7F0_2; 2:; rlwinm. 0,31,0,28,28; beq 3f; bl _s8038B7F0_3; 3:; rlwinm. 0,31,0,27,27; beq 4f; bl _s8038B7F0_4; 4:; rlwinm. 0,31,0,27,28; beq 5f; bl _s8038B7F0_5; 5:; lwz 3,-17720(13); li 0,0; stw 0,0x5ac(3); 6:; lwz 3,-17720(13); lwz 0,0x0(3); cmplwi 0,0; bne 7f; bl _s8038B7F0_6; 7:; or 0,29,28; lis 3,-13311; stb 0,-32768(3); sth 30,-32768(3); lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8038B7F0_0();
extern "C" void _s8038B7F0_1();
extern "C" void _s8038B7F0_2();
extern "C" void _s8038B7F0_3();
extern "C" void _s8038B7F0_4();
extern "C" void _s8038B7F0_5();
extern "C" void _s8038B7F0_6();
extern "C" void f_8038B7F0() {}
