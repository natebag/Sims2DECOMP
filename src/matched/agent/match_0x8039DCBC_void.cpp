// 0x8039DCBC void (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x0(3); addi 0,4,-4; lwz 6,-4(4); mr 7,5; subf 0,3,0; stw 9,-4(4); srawi 5,0,2; li 4,0; bl _s8039DCBC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8039DCBC_0();
extern "C" void f_8039DCBC() {}
