// 0x8001E68C CameraDirector::ForceDisableHud(bool) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,1; bne 0f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; bne 0f; stw 4,0x16c(3); blr; 0:; li 0,0; stw 0,0x16c(3)"
extern "C" void f_8001E68C() {}
