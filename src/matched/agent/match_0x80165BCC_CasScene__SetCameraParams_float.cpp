// 0x80165BCC CasScene::SetCameraParams(float, (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f3,0xb14(3); stfs f1,0xabc(3); stfs f2,0xb10(3)"
extern "C" void f_80165BCC() {}
