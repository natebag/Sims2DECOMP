// 0x800EAD18 cXObjectImpl::IsPortal(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,8; bne 2f; cmpwi 31,0; beq 0f; lwz 9,0x4(31); li 4,6; lwz 3,0x0(9); bl _s800EAD18_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 2f; li 30,1; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800EAD18_0();
extern "C" void f_800EAD18() {}
