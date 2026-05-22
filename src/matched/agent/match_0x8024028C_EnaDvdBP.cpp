// 0x8024028C EnaDvdBP (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 0,-13312; ori 0,0,24606; stw 0,0x8(1); lwz 3,0x8(1); mtspr 1013,3; isync; addi 1,1,16"
extern "C" void f_8024028C() {}
