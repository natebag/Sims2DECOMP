// 0x801B4460 FCMTarget::SetMeterHeight(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; bge 0f; li 0,0; stw 0,0xa0(3); blr; 0:; cmpwi 4,100; ble 1f; li 0,100; stw 0,0xa0(3); blr; 1:; stw 4,0xa0(3)"
extern "C" void f_801B4460() {}
