// 0x80364EE8 ERenderSurface::GetOutputRect(TRect<float> (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 9,0x0(3); lwz 11,0x4(3); lis 0,17200; addi 9,9,-1; mr 8,10; xori 9,9,32768; addi 11,11,-1; stw 9,0xc(1); xori 11,11,32768; lis 7,-32702; lis 9,-32702; stw 0,0x8(1); lfd f12,0x3108(7); lfd f13,0x8(1); stw 11,0xc(1); lfs f11,0x3110(9); fsub f13,f13,f12; stw 0,0x8(1); frsp f13,f13; stfs f11,0x4(4); lfd f0,0x8(1); stfs f13,0x8(4); fsub f0,f0,f12; stfs f11,0x0(4); frsp f0,f0; stfs f0,0xc(4); addi 1,1,16"
extern "C" void f_80364EE8() {}
