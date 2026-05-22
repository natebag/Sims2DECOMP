// 0x80307690 ETweak::Update(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x18(3); lbz 0,0x0(9); cmpwi 0,0; bne 0f; li 3,0; b 3f; 0:; lis 9,-32702; lfs f12,0x4(3); lfs f11,-1272(9); li 31,0; fcmpu 0,f12,f11; beq 1f; lfs f0,0x0(3); lfs f13,-26800(13); fadds f0,f0,f13; fcmpu 0,f0,f12; stfs f0,0x0(3); ble 1f; stfs f11,0x0(3); li 31,1; 1:; cmpwi 31,0; beq 2f; bl _s80307690_0; 2:; mr 3,31; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80307690_0();
extern "C" void f_80307690() {}
