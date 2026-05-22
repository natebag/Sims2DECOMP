// 0x802CFE0C ERTQuantize::NodeToIndex(ERTQNode (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 0f; lwz 9,0x108c(3); lis 0,-18725; ori 0,0,28087; subf 9,9,4; mullw 9,9,0; rlwinm 3,9,29,16,31; blr; 0:; li 3,0"
extern "C" int f_802CFE0C() {}
