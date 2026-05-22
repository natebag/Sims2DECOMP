// 0x80375A74 ARClear (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 3,1; stw 0,0x4(1); stwu 1,-8(1); beq 2f; bge 0f; cmpwi 3,0; bge 1f; b 4f; 0:; cmpwi 3,3; bge 4f; b 3f; 1:; lwz 4,-22360(13); cmplwi 4,0; beq 4f; li 3,0; bl _s80375A74_0; b 4f; 2:; lwz 4,-22360(13); cmplwi 4,0; beq 4f; li 3,16384; addi 4,4,-16384; bl _s80375A74_1; b 4f; 3:; lwz 3,-22360(13); cmplwi 3,0; beq 4f; lwz 4,-22356(13); cmplwi 4,0; beq 4f; bl _s80375A74_2; 4:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80375A74_0();
extern "C" void _s80375A74_1();
extern "C" void _s80375A74_2();
extern "C" void f_80375A74() {}
