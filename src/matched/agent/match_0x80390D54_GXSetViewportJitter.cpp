// 0x80390D54 GXSetViewportJitter (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmplwi 3,0; stw 0,0x4(1); stwu 1,-8(1); bne 0f; lfs f0,-17344(13); fsubs f2,f2,f0; 0:; lwz 3,-17720(13); stfs f1,0x4f4(3); stfs f2,0x4f8(3); stfs f3,0x4fc(3); stfs f4,0x500(3); stfs f5,0x504(3); stfs f6,0x508(3); bl _s80390D54_0; lwz 3,-17720(13); li 0,1; sth 0,0x2(3); lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80390D54_0();
extern "C" void f_80390D54() {}
