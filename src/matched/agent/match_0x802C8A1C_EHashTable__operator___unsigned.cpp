// 0x802C8A1C EHashTable::operator[](unsigned (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); addi 5,1,8; bl _s802C8A1C_0; lwz 3,0x8(1); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s802C8A1C_0();
extern "C" void f_802C8A1C() {}
