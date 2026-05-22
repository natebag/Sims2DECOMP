// 0x8036A4E4 __static_initialization_and_destruction_0 (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 0f; cmpwi 3,0; beq 0f; lis 3,-32688; lis 4,-32713; lis 5,-32713; lis 6,-32713; lis 8,-32702; lis 9,-32688; addi 3,3,-10124; addi 4,4,-23212; addi 5,5,-23164; addi 6,6,-23132; addi 8,8,13208; addi 9,9,-13000; li 7,1; bl _s8036A4E4_0; stw 3,-22412(13); 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8036A4E4_0();
extern "C" void f_8036A4E4() {}
