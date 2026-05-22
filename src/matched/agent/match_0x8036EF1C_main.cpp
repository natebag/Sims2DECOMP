// 0x8036EF1C __main (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32690; lwz 0,-3968(9); cmpwi 0,0; bne 0f; li 0,1; stw 0,-3968(9); bl _s8036EF1C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036EF1C_0();
extern "C" void f_8036EF1C() {}
