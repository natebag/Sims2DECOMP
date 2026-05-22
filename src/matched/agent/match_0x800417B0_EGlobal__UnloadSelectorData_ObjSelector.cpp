// 0x800417B0 EGlobal::UnloadSelectorData(ObjSelector (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; li 5,1; addi 3,3,14696; bl _s800417B0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800417B0_0();
extern "C" void f_800417B0() {}
