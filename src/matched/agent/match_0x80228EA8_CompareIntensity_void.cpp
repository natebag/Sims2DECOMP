// 0x80228EA8 CompareIntensity(void (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f13,0x4(3); lfs f0,0x4(4); fcmpu 0,f13,f0; bge 0f; li 3,1; blr; 0:; ble 1f; li 3,-1; blr; 1:; lfs f13,0x2c(3); lfs f0,0x2c(4); fcmpu 0,f13,f0; bgt 2f; li 3,-1; bltlr; li 3,0; blr; 2:; li 3,1"
extern "C" float f_80228EA8() {}
