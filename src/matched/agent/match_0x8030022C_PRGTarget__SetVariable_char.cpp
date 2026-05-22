// 0x8030022C PRGTarget::SetVariable(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mtspr 8,0; add 3,11,3; blrl; b 0f; lwz 11,-26392(13); addi 5,1,24; addi 6,1,8; mr 4,29; lwz 9,0x0(11); addi 30,1,56; lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26392(13); addi 5,1,8; mr 4,30; mr 6,5; lwz 9,0x0(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; mr 3,29; mr 4,30; bl _s8030022C_0; 0:; lwz 9,0x70(28); mr 4,29; lha 3,0xd0(9); lwz 0,0xd4(9); add 3,28,3; mtspr 8,0; blrl; b 1f; lwz 11,-26392(13); mr 4,29; addi 5,31,128; addi 6,31,80; lwz 9,0x0(11); lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x70(28); mr 4,29; lha 3,0xd0(9); lwz 0,0xd4(9); add 3,28,3; mtspr 8,0; blrl; 1:; lwz 9,0x70(28); mr 4,31; lha 3,0x108(9); lwz 0,0x10c(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s8030022C_0();
extern "C" int f_8030022C() {}
