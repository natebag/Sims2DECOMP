// 0x801ECC58 StaticGetShaderId(InteractorModule::WallPaperData (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; beq 0f; lwz 9,0x0(3); lwz 3,0x8(9); blr; 0:; lis 3,-10852; ori 3,3,31669"
extern "C" int f_801ECC58() {}
