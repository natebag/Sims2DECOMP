// 0x803B4ED4 _Deque_base<FAMTarget::FAM_STATE, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; mr 31,4; cmplw 31,30; bge 1f; 0:; li 3,128; bl _s803B4ED4_0; stw 3,0x0(31); addi 31,31,4; cmplw 31,30; blt 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803B4ED4_0();
extern "C" void f_803B4ED4() {}
