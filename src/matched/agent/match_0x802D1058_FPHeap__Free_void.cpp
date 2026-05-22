// 0x802D1058 FPHeap::Free(void (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 31,4; beq 1f; lwz 3,-21320(13); mr 4,31; bl _s802D1058_0; mr. 3,3; beq 0f; lis 0,17733; ori 0,0,21062; stw 0,0x0(31); lwz 9,0x4(3); stw 9,0x4(31); stw 31,0x4(3); b 1f; 0:; mr 3,30; mr 4,31; bl _s802D1058_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D1058_0();
extern "C" void _s802D1058_1();
extern "C" void f_802D1058() {}
