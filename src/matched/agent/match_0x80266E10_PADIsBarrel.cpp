// 0x80266E10 PADIsBarrel (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; blt 0f; cmpwi 3,4; blt 1f; 0:; li 3,0; blr; 1:; lis 0,-32768; lwz 4,-23156(13); srw 0,0,3; and. 0,4,0; beq 2f; li 3,1; blr; 2:; li 3,0"
extern "C" int f_80266E10() {}
