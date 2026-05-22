// 0x801EC0D0 StaticConvertTabToCategory(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,1; beq 2f; bgt 0f; cmpwi 3,0; beq 1f; b 4f; 0:; cmpwi 3,2; beq 3f; b 4f; 1:; li 3,1; blr; 2:; li 3,2; blr; 3:; li 3,3; blr; 4:; li 3,0"
extern "C" int f_801EC0D0() {}
