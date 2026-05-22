// 0x800F9988 ObjectModuleImpl::GetPeople(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x2058(3); rlwinm 4,4,2,0,29; li 3,0; lwzx 9,9,4; cmplwi 9,0; beqlr; lwz 3,0x4(9)"
extern "C" int f_800F9988() {}
