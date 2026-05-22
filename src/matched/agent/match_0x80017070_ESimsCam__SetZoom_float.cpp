// 0x80017070 ESimsCam::SetZoom(float) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32707; stfs f1,0x448(3); lfs f1,-7368(9); bl _s80017070_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80017070_0();
extern "C" void f_80017070() {}
