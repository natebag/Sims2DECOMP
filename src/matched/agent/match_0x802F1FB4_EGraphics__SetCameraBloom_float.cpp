// 0x802F1FB4 EGraphics::SetCameraBloom(float, (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32702; mr 11,3; lfs f0,-3952(9); li 0,0; stfs f1,0x2ac(11); stfs f2,0x2b0(11); fcmpu 0,f1,f0; stfs f3,0x2b4(11); stfs f4,0x2b8(11); bne 0f; fcmpu 0,f2,f0; bne 0f; fcmpu 0,f3,f0; bne 0f; fcmpu 0,f4,f0; beq 1f; 0:; li 0,1; 1:; stw 0,0x2a8(11); lwz 9,0x0(11); lha 3,0x230(9); lwz 0,0x234(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802F1FB4() {}
