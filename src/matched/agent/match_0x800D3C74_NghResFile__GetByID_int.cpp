// 0x800D3C74 NghResFile::GetByID(int, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,5; bl _s800D3C74_0; b 1f; 0:; lhz 0,0x8(3); cmpw 0,31; bne 1f; lwz 3,0x4(3); b 2f; 1:; lwz 3,0x0(3); cmpwi 3,0; bne 0b; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800D3C74_0();
extern "C" void f_800D3C74() {}
