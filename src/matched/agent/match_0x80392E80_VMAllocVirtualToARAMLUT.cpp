// 0x80392E80 __VMAllocVirtualToARAMLUT (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); bl _s80392E80_0; mr 4,3; addis 3,4,1; stw 4,-21852(13); addi 3,3,-32768; bl _s80392E80_1; li 0,1024; li 5,0; li 4,0; mtspr 9,0; 0:; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; lwz 3,-21852(13); stwx 4,3,5; addi 5,5,4; bdnz 0b; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392E80_0();
extern "C" void _s80392E80_1();
extern "C" void f_80392E80() {}
