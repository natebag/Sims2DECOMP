// 0x80138E30 SpacePartition::GetNode(int) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; blt 0f; lwz 11,0x4c(3); lis 9,-17874; lwz 0,0x50(3); ori 9,9,35747; subf 0,11,0; mullw 0,0,9; srawi 0,0,2; cmplw 4,0; blt 1f; 0:; li 3,0; blr; 1:; mulli 3,4,44; add 3,11,3"
extern "C" int f_80138E30() {}
