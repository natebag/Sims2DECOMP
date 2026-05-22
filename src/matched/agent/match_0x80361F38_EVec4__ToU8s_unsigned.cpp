// 0x80361F38 EVec4::ToU8s(unsigned (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 0,4; lis 11,-32702; lis 9,-32702; mtspr 9,0; lfs f11,0x2eb4(11); li 8,0; lfs f12,0x2eb0(9); li 11,0; li 10,255; 0:; lfs f0,0x0(3); addi 3,3,4; fmuls f13,f0,f12; fcmpu 0,f13,f11; fcmpu 7,f13,f12; bge 1f; stbx 8,4,11; b 3f; 1:; ble cr7,2f; stbx 10,4,11; b 3f; 2:; fmr f0,f13; fctiwz f0,f0; stfd f0,0x8(1); lwz 0,0xc(1); stbx 0,4,11; 3:; addi 11,11,1; bdnz 0b; addi 1,1,16"
extern "C" void f_80361F38() {}
