// 0x802B8420 AptScriptFunctionBase::GetRegisterValue(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-26972(13); rlwinm 3,3,2,0,29; lwzx 3,3,9"
extern "C" int f_802B8420() {}
