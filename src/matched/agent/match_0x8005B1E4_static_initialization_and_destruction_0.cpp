// 0x8005B1E4 __static_initialization_and_destruction_0 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32696; addi 3,3,21920; bl _s8005B1E4_0; b 1f; 0:; lis 9,-32698; lis 11,-32696; addi 9,9,-13768; stw 9,0x5600(11); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8005B1E4_0();
extern "C" void f_8005B1E4() {}
