// 0x80069A14 SAnimator2::defaultVelocity(int) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 3,0x8(3); mr 31,4; bl _s80069A14_0; cmpwi 3,0; beq 0f; cmpwi 31,1; beq 1f; cmpwi 31,8; beq 1f; lis 9,-32707; lfs f1,0x4c54(9); b 3f; 0:; cmpwi 31,1; beq 1f; cmpwi 31,8; bne 2f; 1:; lis 9,-32707; lfs f1,0x4c50(9); b 3f; 2:; lis 9,-32707; lfs f1,0x4c58(9); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80069A14_0();
extern "C" void f_80069A14() {}
