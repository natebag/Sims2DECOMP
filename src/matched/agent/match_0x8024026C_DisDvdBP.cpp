// 0x8024026C DisDvdBP (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); li 0,0; stw 0,0x8(1); lwz 3,0x8(1); mtspr 1013,3; isync; addi 1,1,16"
extern "C" void f_8024026C() {}
