// 0x80208080 InteractorModule::FloorPainter::GetSelectedRectPoints(int (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lfs f13,0x24(3); lfs f0,0x68(3); fcmpu 0,f13,f0; bge 0f; fmr f0,f13; b 0f; 0:; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); stw 0,0x0(4); lfs f13,0x20(3); lfs f0,0x64(3); fcmpu 0,f13,f0; bge 1f; fmr f0,f13; b 1f; 1:; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); stw 0,0x0(5); lfs f13,0x24(3); lfs f0,0x68(3); fcmpu 0,f13,f0; ble 2f; fmr f0,f13; b 2f; 2:; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); stw 0,0x0(6); lfs f13,0x64(3); lfs f0,0x20(3); fcmpu 0,f0,f13; ble 3f; b 4f; 3:; fmr f0,f13; 4:; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); stw 0,0x0(7); addi 1,1,16"
extern "C" void f_80208080() {}
