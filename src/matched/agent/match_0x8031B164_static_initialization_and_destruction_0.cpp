// 0x8031B164 __static_initialization_and_destruction_0 (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 9,-32702; lis 11,-32702; lfs f0,0x8f4(9); lis 3,-32688; lfs f13,0x8f8(11); lis 4,-32718; lis 5,-32718; lis 6,-32718; fmuls f0,f0,f13; lis 8,-32702; lis 9,-32688; stfs f0,-22628(13); addi 3,3,-12584; addi 4,4,-19988; addi 5,5,-19948; addi 6,6,-19904; addi 8,8,2136; addi 9,9,-13000; li 7,4; bl _s8031B164_0; stw 3,-22624(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8031B164_0();
extern "C" void f_8031B164() {}
