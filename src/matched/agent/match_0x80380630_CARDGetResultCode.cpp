// 0x80380630 CARDGetResultCode (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; blt 0f; cmpwi 3,2; blt 1f; 0:; li 3,-128; blr; 1:; mulli 4,3,272; lis 3,-32688; addi 0,3,-24000; add 3,0,4; lwz 3,0x4(3)"
extern "C" int f_80380630() {}
