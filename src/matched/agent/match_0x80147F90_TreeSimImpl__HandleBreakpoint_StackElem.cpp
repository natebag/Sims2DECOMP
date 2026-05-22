// 0x80147F90 TreeSimImpl::HandleBreakpoint(StackElem (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 31,4; beq 0f; mr 3,31; li 4,0; bl _s80147F90_0; 0:; mr 3,30; mr 4,31; bl _s80147F90_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80147F90_0();
extern "C" void _s80147F90_1();
extern "C" void f_80147F90() {}
