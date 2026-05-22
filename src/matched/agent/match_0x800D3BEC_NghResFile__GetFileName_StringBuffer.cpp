// 0x800D3BEC NghResFile::GetFileName(StringBuffer (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 0,3,40; mr 3,4; mr 4,0; bl _s800D3BEC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800D3BEC_0();
extern "C" void f_800D3BEC() {}
