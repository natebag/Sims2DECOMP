// 0x800B70B8 FloatConstantsQuickData::LoadFromDataID(ObjectDataID (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); lha 5,0x4(4); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; lwz 4,0x0(4); mtspr 8,9; blrl; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800B70B8() {}
