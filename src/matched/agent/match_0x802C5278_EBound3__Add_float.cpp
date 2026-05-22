// 0x802C5278 EBound3::Add(float (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); li 11,0; cmpw 11,5; bge 4f; addi 10,1,8; 0:; rlwinm 9,11,4,0,27; addi 0,11,1; lfsx f13,9,4; li 11,0; add 9,9,4; lfs f12,0x8(9); lfs f0,0x4(9); li 9,3; stfs f13,0x8(1); mtspr 9,9; stfs f0,0x4(10); stfs f12,0x8(10); 1:; lfsx f13,11,10; lfsx f0,11,3; fcmpu 0,f13,f0; bge 2f; stfsx f13,11,3; b 3f; 2:; addi 9,3,12; lfsx f0,9,11; fcmpu 0,f13,f0; ble 3f; stfsx f13,9,11; 3:; addi 11,11,4; bdnz 1b; mr 11,0; cmpw 11,5; blt 0b; 4:; addi 1,1,24"
extern "C" void f_802C5278() {}
