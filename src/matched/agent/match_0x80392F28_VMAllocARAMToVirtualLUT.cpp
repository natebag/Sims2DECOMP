// 0x80392F28 __VMAllocARAMToVirtualLUT (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s80392F28_0; stw 3,-21856(13); addi 3,3,16384; bl _s80392F28_1; li 0,512; li 5,0; li 4,0; mtspr 9,0; 0:; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21856(13); stwx 4,3,5; addi 5,5,4; bdnz 0b; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392F28_0();
extern "C" void _s80392F28_1();
extern "C" void f_80392F28() {}
