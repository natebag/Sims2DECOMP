// 0x800889A4 EmitterGeom3d::~EmitterGeom3d(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,30; li 4,2; bl _s800889A4_0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800889A4_0();
extern "C" int f_800889A4() {}
