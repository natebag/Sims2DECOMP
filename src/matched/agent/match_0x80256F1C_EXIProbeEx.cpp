// 0x80256F1C EXIProbeEx (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 31,0,4; addi 3,30,0; bl _s80256F1C_0; cmpwi 3,0; beq 1f; lwz 0,0x20(31); cmpwi 0,0; bne 1f; addi 3,30,0; li 4,0; addi 5,1,12; bl _s80256F1C_1; cmpwi 3,0; beq 0f; li 3,1; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 2f; li 3,1; b 4f; 2:; rlwinm 0,30,2,0,29; lis 3,-32768; addi 3,3,12480; lwzx 0,3,0; cmpwi 0,0; beq 3f; li 3,0; b 4f; 3:; li 3,-1; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80256F1C_0();
extern "C" void _s80256F1C_1();
extern "C" void f_80256F1C() {}
