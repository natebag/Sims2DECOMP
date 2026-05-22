// 0x80054068 ISimsMultiTileObjectModel::Construct(ISimsMultiTileObjectModel (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s80054068_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80054068_0();
extern "C" void f_80054068() {}
