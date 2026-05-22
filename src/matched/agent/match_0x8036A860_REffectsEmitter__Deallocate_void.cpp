// 0x8036A860 REffectsEmitter::Deallocate(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x18(31); cmpwi 0,0; beq 0f; bl _s8036A860_0; lwz 4,0x18(31); bl _s8036A860_1; li 0,0; stw 0,0x18(31); stw 0,0x14(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8036A860_0();
extern "C" void _s8036A860_1();
extern "C" void f_8036A860() {}
