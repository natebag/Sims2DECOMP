// 0x80204FD8 InteractorModule::DirectInteractor::CheckCancelTimer(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; lwz 0,0x84(11); cmpwi 0,1; bne 0f; lfs f0,0x88(11); lis 9,-32704; lfs f12,-26800(13); li 3,1; lfs f13,-13528(9); fadds f0,f0,f12; fcmpu 0,f0,f13; stfs f0,0x88(11); bgtlr; 0:; li 3,0"
extern "C" void f_80204FD8() {}
