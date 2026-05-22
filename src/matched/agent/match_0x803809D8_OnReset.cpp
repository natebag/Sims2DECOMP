// 0x803809D8 OnReset (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 3,0; stw 0,0x4(1); stwu 1,-8(1); bne 1f; li 3,0; bl _s803809D8_0; cmpwi 3,-1; beq 0f; li 3,1; bl _s803809D8_1; cmpwi 3,-1; bne 1f; 0:; li 3,0; b 2f; 1:; li 3,1; 2:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s803809D8_0();
extern "C" void _s803809D8_1();
extern "C" void f_803809D8() {}
