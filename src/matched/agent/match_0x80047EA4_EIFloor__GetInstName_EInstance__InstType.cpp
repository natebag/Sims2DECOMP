// 0x80047EA4 EIFloor::GetInstName(EInstance::InstType (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,2; lis 3,-32707; stw 0,0x0(4); addi 3,3,11844"
extern "C" void f_80047EA4() {}
