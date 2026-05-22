// 0x80385470 CARDRand (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,16838; lwz 4,-25328(13); addi 0,3,20077; mullw 3,4,0; addi 0,3,12345; stw 0,-25328(13); lwz 0,-25328(13); rlwinm 3,0,16,17,31"
extern "C" void f_80385470() {}
