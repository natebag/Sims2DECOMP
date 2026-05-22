// 0x801249F4 cXPersonImpl::TryReach(StackElem (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,5; addi 6,1,8; addi 7,1,12; addi 8,1,16; addi 9,1,20; bl _s801249F4_0; or. 0,3,4; beq 0f; lha 0,0x2(31); subfic 9,0,0; adde 0,9,0; mr 4,0; li 3,0; 0:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s801249F4_0();
extern "C" void f_801249F4() {}
