// 0x802E47D4 setClipPlaneOffsets(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,3; lis 9,-32702; mtspr 9,0; lfs f13,-5076(9); li 11,0; li 8,12; li 10,12; li 9,0; 0:; lfsx f0,9,5; fcmpu 0,f0,f13; cror 3,2,1; bns 1f; stbx 9,3,11; stbx 10,4,11; b 2f; 1:; stbx 8,3,11; stbx 9,4,11; 2:; addi 8,8,4; addi 10,10,4; addi 9,9,4; addi 11,11,1; bdnz 0b"
extern "C" void f_802E47D4() {}
