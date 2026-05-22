// 0x8022F694 __static_initialization_and_destruction_0 (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 3,-32688; lis 4,-32733; lis 5,-32733; lis 6,-32733; lis 8,-32704; lis 9,-32688; addi 9,9,-18528; addi 3,3,-13120; addi 4,4,-2272; addi 5,5,-2232; addi 6,6,-2188; addi 8,8,-4236; li 7,0; bl _s8022F694_0; lis 9,-32704; lis 11,-32696; lfs f0,-4180(9); addi 10,11,32320; stw 3,-23776(13); stfs f0,0x7e40(11); stfs f0,0x4(10); stfs f0,0x8(10); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8022F694_0();
extern "C" void f_8022F694() {}
