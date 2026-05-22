// 0x80337FF4 ClampGenericTrigger(unsigned (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); cmplw 0,4; bgt 0f; li 0,0; stb 0,0x0(3); blr; 0:; cmplw 0,5; ble 1f; stb 5,0x0(3); 1:; lbz 0,0x0(3); subf 0,4,0; stb 0,0x0(3)"
extern "C" void f_80337FF4() {}
