// 0x800A7C60 QuickStringSet::LoadFromDataID(ObjectDataID (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 5,0x4(4); lha 0,0xe8(9); lwz 9,0xec(9); add 3,3,0; lwz 4,0x0(4); mtspr 8,9; blrl; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800A7C60() {}
