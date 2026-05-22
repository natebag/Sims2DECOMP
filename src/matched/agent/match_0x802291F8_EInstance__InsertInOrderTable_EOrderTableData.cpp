// 0x802291F8 EInstance::InsertInOrderTable(EOrderTableData (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x4(3); bl _s802291F8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802291F8_0();
extern "C" void f_802291F8() {}
