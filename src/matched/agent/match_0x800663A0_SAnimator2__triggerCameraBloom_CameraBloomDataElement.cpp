// 0x800663A0 SAnimator2::triggerCameraBloom(CameraBloomDataElement (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-26392(13); lfs f4,0xc(4); lwz 9,0x0(11); lfs f1,0x0(4); lha 3,0x1a8(9); lwz 0,0x1ac(9); add 3,11,3; lfs f2,0x4(4); lfs f3,0x8(4); mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800663A0() {}
