// 0x80293468 AptCIH::isVisiable(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stw 31,0x14(1); stw 0,0x24(1); mr. 31,3; beq 2f; lis 9,-32704; lfs f31,0x5c08(9); 0:; mr 3,31; li 4,11; bl _s80293468_0; fcmpu 0,f1,f31; bne 1f; li 3,0; b 3f; 1:; lwz 31,0x48(31); cmpwi 31,0; bne 0b; 2:; li 3,1; 3:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x14(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s80293468_0();
extern "C" void f_80293468() {}
