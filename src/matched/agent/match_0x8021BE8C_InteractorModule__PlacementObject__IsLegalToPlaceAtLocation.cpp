// 0x8021BE8C InteractorModule::PlacementObject::IsLegalToPlaceAtLocation(FTilePt (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x0(31); mr 30,5; li 3,0; cmpwi 0,0; beq 0f; mr 3,31; bl _s8021BE8C_0; lwz 3,0x0(31); mr 4,29; mr 5,30; bl _s8021BE8C_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8021BE8C_0();
extern "C" void _s8021BE8C_1();
extern "C" void f_8021BE8C() {}
