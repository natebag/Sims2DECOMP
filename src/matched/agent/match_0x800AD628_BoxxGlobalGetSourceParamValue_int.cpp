// 0x800AD628 BoxxGlobalGetSourceParamValue(int, (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 0,3; mr 31,5; cmpwi 4,20; li 3,0; bgt 0f; mr 3,0; bl _s800AD628_0; stw 3,0x0(31); li 3,1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800AD628_0();
extern "C" void f_800AD628() {}
