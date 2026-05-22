// 0x80199BAC CASSelectionTarget::ScrollPageLeft(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x548(31); cmpwi 0,1; beq 0f; li 4,12; li 5,15; bl _s80199BAC_0; mr 3,31; bl _s80199BAC_1; lwz 9,0x548(31); mr 3,31; addi 9,9,-1; stw 9,0x548(31); bl _s80199BAC_2; mr 3,31; li 4,0; li 5,3; bl _s80199BAC_3; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80199BAC_0();
extern "C" void _s80199BAC_1();
extern "C" void _s80199BAC_2();
extern "C" void _s80199BAC_3();
extern "C" void f_80199BAC() {}
