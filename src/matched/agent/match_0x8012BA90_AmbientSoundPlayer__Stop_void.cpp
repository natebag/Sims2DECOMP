// 0x8012BA90 AmbientSoundPlayer::Stop(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="add 3,31,3; blrl; lwz 9,0x4(31); li 4,0; lwz 0,0x33c(9); lha 3,0x338(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); li 4,40; li 5,0; lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); lha 3,0x188(9); lwz 0,0x18c(9); add 3,31,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x0(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lha 4,0x58(3); cmpwi 4,0; bne 1f; li 3,0; b 3f; 1:; lwz 11,0x0(3); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x488(9); lwz 0,0x48c(9); add 3,10,3; mtspr 8,0; blrl; mr. 3,3; beq 2f; lwz 3,0x0(3); li 4,2; bl _s8012BA90_0; b 3f; 2:; li 3,0; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8012BA90_0();
extern "C" void f_8012BA90() {}
