// 0x8034FDA0 ENgcTextureBase::FlushImageMemoryRange(bool) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lhz 0,0x16(31); li 4,1; cmplwi 0,1; ble 0f; mr 4,0; 0:; mr 3,31; addi 5,1,8; addi 6,1,12; bl _s8034FDA0_0; mr 4,3; cmpwi 30,0; beq 1f; lwz 3,0x74(31); bl _s8034FDA0_1; b 2f; 1:; lwz 3,0x74(31); bl _s8034FDA0_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8034FDA0_0();
extern "C" void _s8034FDA0_1();
extern "C" void _s8034FDA0_2();
extern "C" void f_8034FDA0() {}
