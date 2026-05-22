// 0x80087F0C WrapperPaneBase::SetButtonItemStyle(int, (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 6,5; mr 5,4; li 4,2; bl _s80087F0C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80087F0C_0();
extern "C" void f_80087F0C() {}
