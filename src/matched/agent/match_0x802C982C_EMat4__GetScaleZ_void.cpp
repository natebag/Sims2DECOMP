// 0x802C982C EMat4::GetScaleZ(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); li 4,2; addi 5,1,8; bl _s802C982C_0; addi 3,1,8; bl _s802C982C_1; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s802C982C_0();
extern "C" void _s802C982C_1();
extern "C" void f_802C982C() {}
