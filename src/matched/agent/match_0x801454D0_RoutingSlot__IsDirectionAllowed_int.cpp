// 0x801454D0 RoutingSlot::IsDirectionAllowed(int) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x1c(3); li 3,1; sraw 0,0,4; andi. 9,0,1; bnelr; li 3,0"
extern "C" int f_801454D0() {}
