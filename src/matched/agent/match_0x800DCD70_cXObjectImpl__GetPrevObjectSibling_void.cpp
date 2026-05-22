// 0x800DCD70 cXObjectImpl::GetPrevObjectSibling(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 4,14; addi 3,31,40; bl _s800DCD70_0; lha 0,0x0(3); li 3,0; cmpwi 0,0; bne 0f; mr 3,31; bl _s800DCD70_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800DCD70_0();
extern "C" void _s800DCD70_1();
extern "C" void f_800DCD70() {}
