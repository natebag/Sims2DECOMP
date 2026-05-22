// 0x801E70FC EYETarget::EyeToyUnplugCallback(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-28712(13); cmplwi 9,0; beqlr; li 0,1; stw 0,0xb0(9)"
extern "C" void f_801E70FC() {}
