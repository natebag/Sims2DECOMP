// 0x801F119C INVTarget::ClearAllObjRelatedCheatStrings(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,0; li 5,2048; addi 3,30,4491; bl _s801F119C_0; li 4,0; li 5,2048; addi 3,30,6539; bl _s801F119C_1; addi 3,30,8587; li 4,0; li 5,2048; bl _s801F119C_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F119C_0();
extern "C" void _s801F119C_1();
extern "C" void _s801F119C_2();
extern "C" void f_801F119C() {}
