// 0x802F7C00 ERC::Texture(ETexture (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 9,0x70(31); mr 30,5; li 5,0; li 4,0; lwz 0,0x2b4(9); lha 3,0x2b0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 4,1; lwz 0,0x2ac(9); lha 3,0x2a8(9); mtspr 8,0; add 3,31,3; blrl; li 0,17; cmpwi 29,0; stb 0,0x0(3); stb 30,0x1(3); stw 29,0x4(3); beq 0f; lwz 3,0x0(31); mr 4,29; addi 3,3,48; bl _s802F7C00_0; 0:; lwz 9,0x70(31); lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802F7C00_0();
extern "C" void f_802F7C00() {}
