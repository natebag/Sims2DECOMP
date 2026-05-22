// 0x8039E970 void (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 0,0x24(1); lwz 0,0x0(5); addi 7,1,24; lwz 6,-4(4); addi 5,4,-4; lwz 9,0x0(3); subf 5,3,5; stw 0,0x18(1); srawi 5,5,2; stw 9,-4(4); stw 0,0x8(1); li 4,0; stw 0,0x10(1); bl _s8039E970_0; lwz 0,0x24(1); mtspr 8,0; addi 1,1,32"
extern "C" void _s8039E970_0();
extern "C" void f_8039E970() {}
