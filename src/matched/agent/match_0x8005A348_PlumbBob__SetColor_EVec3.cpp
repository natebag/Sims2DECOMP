// 0x8005A348 PlumbBob::SetColor(EVec3 (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lwz 11,0x0(4); addi 9,3,64; lwz 0,0x8(4); lis 8,-32696; lwz 10,0x4(4); addi 7,1,8; stw 11,0x40(3); addi 6,3,48; stw 0,0x8(9); stw 10,0x4(9); lfs f11,0x55c4(8); lfs f0,0x0(4); lfs f13,0x8(4); lfs f12,0x4(4); fmuls f0,f0,f11; stfs f0,0x8(1); fmuls f13,f13,f11; fmuls f12,f12,f11; stfs f13,0x10(1); stfs f12,0xc(1); lwz 0,0x8(1); lwz 9,0x8(7); lwz 11,0x4(7); stw 0,0x30(3); stw 9,0x8(6); stw 11,0x4(6); addi 1,1,24"
extern "C" void f_8005A348() {}
