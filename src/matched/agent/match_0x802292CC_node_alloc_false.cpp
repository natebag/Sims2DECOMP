// 0x802292CC __node_alloc<false, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 6,6,-27844; addi 8,8,-6344; addi 9,9,-13320; li 7,1; bl _s802292CC_0; stw 3,-23800(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,124; bl _s802292CC_1; bl _s802292CC_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802292CC_0();
extern "C" void _s802292CC_1();
extern "C" void _s802292CC_2();
extern "C" void f_802292CC() {}
