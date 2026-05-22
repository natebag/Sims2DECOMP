// 0x802CA5DC EMat4::Clamp(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; li 11,0; lfs f11,-7468(9); lis 10,-32702; 0:; rlwinm 9,11,4,0,27; addi 0,11,1; li 11,4; mtspr 9,11; 1:; lfsx f0,9,3; fcmpu 0,f0,f11; bge 2f; fmr f12,f11; b 3f; 2:; lfs f13,-7464(10); fmr f12,f0; fcmpu 0,f0,f13; ble 3f; fmr f12,f13; 3:; stfsx f12,9,3; addi 9,9,4; bdnz 1b; mr 11,0; cmpwi 11,3; ble 0b"
extern "C" void f_802CA5DC() {}
