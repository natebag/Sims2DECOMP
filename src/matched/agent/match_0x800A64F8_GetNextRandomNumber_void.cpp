// 0x800A64F8 GetNextRandomNumber(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-24584(13); lis 0,16838; ori 0,0,20077; rlwinm 11,9,0,16,31; rlwinm 10,9,16,16,31; mulli 3,11,20077; mullw 9,9,0; mulli 0,10,16838; addi 3,3,12345; rlwinm 3,3,16,16,31; mulli 11,11,16838; addi 9,9,12345; stw 9,-24584(13); mulli 10,10,20077; rlwinm 0,0,16,0,15; add 3,3,11; add 3,3,10; add 3,3,0"
extern "C" void f_800A64F8() {}
