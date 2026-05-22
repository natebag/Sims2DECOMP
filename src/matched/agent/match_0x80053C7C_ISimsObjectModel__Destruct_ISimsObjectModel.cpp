// 0x80053C7C ISimsObjectModel::Destruct(ISimsObjectModel (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,2; bl _s80053C7C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80053C7C_0();
extern "C" void f_80053C7C() {}
