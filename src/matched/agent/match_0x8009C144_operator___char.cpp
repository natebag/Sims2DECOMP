// 0x8009C144 operator==(char (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,3; li 5,0; mr 3,4; mr 4,0; bl _s8009C144_0; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8009C144_0();
extern "C" void f_8009C144() {}
