// 0x802F811C ERC::Lights(ELights (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; li 5,248; li 28,0; bl _s802F811C_0; mr. 30,3; beq 0f; lwz 28,0xf0(30); 0:; li 29,0; beq 1f; lwz 29,0xf4(30); 1:; lwz 9,0x70(31); li 4,0; li 5,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,24; li 11,0; stw 30,0x4(3); stb 0,0x0(3); stb 28,0x1(3); stb 29,0x2(3); stb 11,0x3(3); lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802F811C_0();
extern "C" void f_802F811C() {}
