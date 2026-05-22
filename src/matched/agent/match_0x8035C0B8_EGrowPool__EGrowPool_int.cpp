// 0x8035C0B8 EGrowPool::EGrowPool(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8035C0B8_0; cmpwi 30,4; bge 0f; li 30,4; 0:; stw 30,0x8(31); mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035C0B8_0();
extern "C" void f_8035C0B8() {}
