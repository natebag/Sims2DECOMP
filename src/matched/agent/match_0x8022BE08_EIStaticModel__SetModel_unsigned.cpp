// 0x8022BE08 EIStaticModel::SetModel(unsigned (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; li 0,0; stw 4,0x110(9); stw 5,0x124(9); mr 4,6; stw 0,0x14(9); mr 5,7; bl _s8022BE08_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8022BE08_0();
extern "C" void f_8022BE08() {}
