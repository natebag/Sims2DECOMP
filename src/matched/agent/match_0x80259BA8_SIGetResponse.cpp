// 0x80259BA8 SIGetResponse (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-32694; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 29,3,0; addi 30,4,0; addi 28,5,-21872; bl _s80259BA8_0; addi 31,3,0; addi 3,29,0; bl _s80259BA8_1; rlwinm. 0,3,0,26,26; beq 0f; mulli 4,29,12; lis 3,-13312; addi 0,3,25600; add 4,0,4; rlwinm 3,29,3,0,28; lwz 0,0x4(4); add 5,28,3; stw 0,0x1c0(5); rlwinm 0,29,2,0,29; add 3,28,0; lwz 4,0x8(4); li 0,1; stw 4,0x1c4(5); stw 0,0x1b0(3); 0:; rlwinm 0,29,2,0,29; add 3,28,0; lwz 27,0x1b0(3); li 0,0; cmpwi 27,0; stw 0,0x1b0(3); beq 1f; rlwinm 0,29,3,0,28; add 3,28,0; lwz 0,0x1c0(3); stw 0,0x0(30); lwz 0,0x1c4(3); stw 0,0x4(30); 1:; mr 3,31; bl _s80259BA8_2; mr 3,27; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80259BA8_0();
extern "C" void _s80259BA8_1();
extern "C" void _s80259BA8_2();
extern "C" void f_80259BA8() {}
