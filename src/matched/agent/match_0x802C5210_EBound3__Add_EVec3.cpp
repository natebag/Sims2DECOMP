// 0x802C5210 EBound3::Add(EVec3 (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,0; cmpw 9,5; bgelr; 0:; mulli 10,9,12; addi 0,9,1; li 9,3; mtspr 9,9; li 11,0; add 10,10,4; 1:; lfsx f13,11,10; lfsx f0,11,3; fcmpu 0,f13,f0; bge 2f; stfsx f13,11,3; b 3f; 2:; addi 9,3,12; lfsx f0,9,11; fcmpu 0,f13,f0; ble 3f; stfsx f13,9,11; 3:; addi 11,11,4; bdnz 1b; mr 9,0; cmpw 9,5; blt 0b"
extern "C" void f_802C5210() {}
