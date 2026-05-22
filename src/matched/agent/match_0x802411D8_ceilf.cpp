// 0x802411D8 ceilf (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); fmr f0,f1; stfs f0,0x8(1); lwz 0,0x8(1); mr 11,0; rlwinm 9,11,9,24,31; addi 9,9,-127; cmpwi 9,22; bgt 3f; cmpwi 9,0; bge 1f; lfs f0,-28228(13); lfs f13,-28224(13); fadds f0,f1,f0; fcmpu 0,f0,f13; ble 4f; cmpwi 11,0; bge 0f; lis 11,-32768; b 4f; 0:; beq 4f; lis 11,16256; b 4f; 1:; lis 0,127; ori 0,0,65535; sraw 10,0,9; and. 0,11,10; beq 5f; lfs f0,-28228(13); lfs f13,-28224(13); fadds f0,f1,f0; fcmpu 0,f0,f13; ble 4f; cmpwi 11,0; ble 2f; lis 0,128; sraw 0,0,9; add 11,11,0; 2:; andc 11,11,10; b 4f; 3:; cmpwi 9,128; bne 5f; fadds f1,f1,f1; b 5f; 4:; stw 11,0x8(1); lfs f0,0x8(1); fmr f1,f0; 5:; addi 1,1,16"
extern "C" void f_802411D8() {}
