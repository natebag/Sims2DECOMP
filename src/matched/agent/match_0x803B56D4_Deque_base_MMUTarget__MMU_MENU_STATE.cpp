// 0x803B56D4 _Deque_base<MMUTarget::MMU_MENU_STATE, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; mr 31,4; cmplw 31,30; bge 2f; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; li 4,128; bl _s803B56D4_0; 1:; addi 31,31,4; cmplw 31,30; blt 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803B56D4_0();
extern "C" void f_803B56D4() {}
