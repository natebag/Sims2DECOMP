// 0x80361FB0 EVec4::FromU8s(unsigned (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 0,4; lis 11,-32702; lis 9,-32702; mtspr 9,0; lfs f12,0x2ec0(11); lis 10,17200; lfd f13,0x2eb8(9); li 11,0; 0:; lbzx 0,4,11; addi 11,11,1; stw 0,0xc(1); stw 10,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x0(3); addi 3,3,4; bdnz 0b; addi 1,1,16"
extern "C" void f_80361FB0() {}
