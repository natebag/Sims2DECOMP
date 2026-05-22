// 0x801453EC SpriteSlot::GetSelector(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x18(3); cmpwi 0,-1; beq 0f; li 3,0; blr; 0:; lwz 3,0x28(3)"
extern "C" int f_801453EC() {}
