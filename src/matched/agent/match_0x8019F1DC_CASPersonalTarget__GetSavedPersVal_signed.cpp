// 0x8019F1DC CASPersonalTarget::GetSavedPersVal(signed (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,140; lbzx 3,3,4; extsb 3,3"
extern "C" int f_8019F1DC() {}
