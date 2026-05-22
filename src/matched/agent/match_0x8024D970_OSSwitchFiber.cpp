// 0x8024D970 OSSwitchFiber (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; mr 5,1; stwu 5,-8(4); mr 1,4; stw 0,0x4(5); mtspr 8,3; blrl; lwz 5,0x0(1); lwz 0,0x4(5); mtspr 8,0; mr 1,5"
extern "C" void f_8024D970() {}
