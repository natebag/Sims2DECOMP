// 0x8031770C __static_initialization_and_destruction_0 (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 9,-32702; addi 11,13,-22640; lfs f0,0x7e4(9); lis 3,-32688; lis 4,-32719; lis 5,-32719; lis 6,-32719; lis 8,-32702; lis 9,-32688; stfs f0,0x4(11); addi 3,3,-12624; addi 4,4,30608; addi 5,5,30648; addi 6,6,30692; addi 8,8,1648; addi 9,9,-13000; stfs f0,0x0(11); li 7,0; bl _s8031770C_0; stw 3,-22632(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8031770C_0();
extern "C" void f_8031770C() {}
