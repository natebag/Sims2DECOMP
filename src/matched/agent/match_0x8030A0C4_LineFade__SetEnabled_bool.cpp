// 0x8030A0C4 LineFade::SetEnabled(bool) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; lwz 0,0x3c(9); cmpw 0,4; beq 0f; stw 4,0x3c(9); mr 4,3; addi 5,3,12; bl _s8030A0C4_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8030A0C4_0();
extern "C" void f_8030A0C4() {}
