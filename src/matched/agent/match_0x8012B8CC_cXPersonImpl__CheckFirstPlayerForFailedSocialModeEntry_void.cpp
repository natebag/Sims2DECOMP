// 0x8012B8CC cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 11,0x4(31); li 4,0; lwz 9,0x4(11); lwz 0,0x33c(9); lha 3,0x338(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(31); li 5,0; li 4,40; lwz 9,0x4(11); lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x3f4(31); lwz 9,0x0(11); lha 3,0x138(9); lwz 0,0x13c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_8012B8CC() {}
