// 0x80099708 TheSimsStateMachine::Update(float) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; lis 30,-32697; fmr f31,f1; addi 3,30,23428; bl _s80099708_0; cmpwi 3,0; beq 0f; mr 3,31; fmr f1,f31; bl _s80099708_1; 0:; addi 3,30,23428; bl _s80099708_2; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80099708_0();
extern "C" void _s80099708_1();
extern "C" void _s80099708_2();
extern "C" void f_80099708() {}
