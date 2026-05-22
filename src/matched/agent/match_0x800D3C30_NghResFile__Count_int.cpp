// 0x800D3C30 NghResFile::Count(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800D3C30_0; lwz 3,0x0(3); li 9,0; cmpwi 3,0; beq 1f; 0:; lwz 3,0x0(3); addi 9,9,1; cmpwi 3,0; bne 0b; 1:; extsh 3,9; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800D3C30_0();
extern "C" void f_800D3C30() {}
