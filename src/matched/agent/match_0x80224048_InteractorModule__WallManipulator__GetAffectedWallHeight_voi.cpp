// 0x80224048 InteractorModule::WallManipulator::GetAffectedWallHeight(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc4(3); andi. 9,0,256; lfs f1,-21092(13); bnelr; lfs f1,-21096(13)"
extern "C" float f_80224048() {}
