// 0x801446A0 ObjectDataSlotDescList::GetResourceName(StringBuffer (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 31,3,4; mr 30,4; mr 3,31; bl _s801446A0_0; cmpwi 3,0; beq 0f; mr 3,30; mr 4,31; bl _s801446A0_1; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801446A0_0();
extern "C" void _s801446A0_1();
extern "C" void f_801446A0() {}
