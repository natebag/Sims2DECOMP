// 0x802611E0 HitCache (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); lwz 5,0x4(4); lwz 6,0x8(4); lwz 0,0x8(3); addi 4,5,-1; add 3,6,4; rlwinm 31,3,17,15,31; rlwinm 30,0,17,15,31; bl _s802611E0_0; lbz 0,0x8(3); cmplwi 0,0; beq 0f; li 0,1; b 1f; 0:; li 0,0; 1:; cmpwi 0,0; beq 2f; li 3,5; b 3f; 2:; li 3,15; 3:; addi 0,31,-2; cmplw 30,0; bgt 4f; addi 0,3,3; add 0,31,0; cmplw 30,0; bge 5f; 4:; li 3,1; b 6f; 5:; li 3,0; 6:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802611E0_0();
extern "C" void f_802611E0() {}
