// 0x802F7B6C ERC::WindowMatrix(EMat4 (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; li 5,64; bl _s802F7B6C_0; lwz 9,0x70(30); mr 29,3; li 4,0; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,30,3; blrl; li 0,15; stw 29,0x4(3); stb 0,0x0(3); lwz 9,0x70(30); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F7B6C_0();
extern "C" void f_802F7B6C() {}
