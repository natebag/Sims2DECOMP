// 0x801388B4 __static_initialization_and_destruction_0 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; addi 3,13,-24088; li 4,3; bl _s801388B4_0; lis 9,-32698; addi 9,9,17632; stw 9,-24088(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801388B4_0();
extern "C" void f_801388B4() {}
