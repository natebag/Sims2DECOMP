// 0x80109BEC cXObjectImpl::TryKillSounds(StackElem (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lha 0,0x0(5); cmpwi 0,0; beq 0f; lha 4,0x4(4); b 1f; 0:; lha 4,0x64(3); 1:; lwz 3,-21492(13); bl _s80109BEC_0; li 3,0; li 4,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80109BEC_0();
extern "C" void f_80109BEC() {}
