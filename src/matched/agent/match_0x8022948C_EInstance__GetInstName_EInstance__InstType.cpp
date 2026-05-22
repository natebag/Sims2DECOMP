// 0x8022948C EInstance::GetInstName(EInstance::InstType (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; lis 3,-32704; stw 0,0x0(4); addi 3,3,-6332"
extern "C" void f_8022948C() {}
