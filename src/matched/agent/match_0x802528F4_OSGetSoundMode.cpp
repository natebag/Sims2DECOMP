// 0x802528F4 OSGetSoundMode (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,3,-24704; bl _s802528F4_0; lwz 0,0x48(31); addi 4,31,72; cmpwi 0,0; beq 0f; bl _s802528F4_1; li 31,0; b 1f; 0:; stw 3,0x44(31); li 0,1; stw 0,0x0(4); 1:; lbz 0,0x13(31); rlwinm. 0,0,0,29,29; beq 2f; li 31,1; b 3f; 2:; li 31,0; 3:; li 3,0; li 4,0; bl _s802528F4_2; mr 3,31; lwz 0,0x24(1); lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802528F4_0();
extern "C" void _s802528F4_1();
extern "C" void _s802528F4_2();
extern "C" void f_802528F4() {}
