// 0x8001ECA0 CameraManager::GetCamera(int) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; lwzx 3,3,4"
extern "C" int f_8001ECA0() {}
