// 0x800A9738 AmbientSoundPlayer::Stop(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x8(31); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x8(31); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x8(31); 0:; li 0,-1; li 3,1; stw 0,0x2c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_800A9738() {}
