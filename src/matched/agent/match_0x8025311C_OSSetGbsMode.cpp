// 0x8025311C OSSetGbsMode (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; rlwinm 4,3,0,16,31; stw 0,0x4(1); rlwinm 0,3,0,17,21; cmplwi 0,20480; stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,3,0; lis 3,-32694; addi 31,3,-24704; beq 0f; rlwinm 0,4,0,24,25; cmplwi 0,192; bne 1f; 0:; li 30,0; 1:; bl _s8025311C_0; lwz 0,0x48(31); addi 5,31,72; cmpwi 0,0; beq 2f; bl _s8025311C_1; li 4,0; b 3f; 2:; stw 3,0x44(31); li 0,1; addi 4,31,20; stw 0,0x0(5); 3:; lhz 0,0x28(4); rlwinm 3,30,0,16,31; cmplw 3,0; bne 4f; li 3,0; li 4,20; bl _s8025311C_2; b 5f; 4:; sth 30,0x28(4); li 3,1; li 4,20; bl _s8025311C_3; 5:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8025311C_0();
extern "C" void _s8025311C_1();
extern "C" void _s8025311C_2();
extern "C" void _s8025311C_3();
extern "C" void f_8025311C() {}
