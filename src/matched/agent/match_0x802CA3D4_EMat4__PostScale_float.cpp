// 0x802CA3D4 EMat4::PostScale(float) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 11,0; 0:; rlwinm 9,11,4,0,27; addi 0,11,1; li 11,3; mtspr 9,11; 1:; lfsx f0,9,3; fmuls f0,f0,f1; stfsx f0,9,3; addi 9,9,4; bdnz 1b; mr 11,0; cmpwi 11,3; ble 0b"
extern "C" void f_802CA3D4() {}
