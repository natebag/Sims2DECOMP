// 0x8031B214 ERModel::Construct(ERModel (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; li 3,384; bl _s8031B214_0; bl _s8031B214_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8031B214_0();
extern "C" void _s8031B214_1();
extern "C" void f_8031B214() {}
