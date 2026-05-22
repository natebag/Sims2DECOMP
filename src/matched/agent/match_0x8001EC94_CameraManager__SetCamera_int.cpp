// 0x8001EC94 CameraManager::SetCamera(int, (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; stwx 5,3,4"
extern "C" void f_8001EC94() {}
