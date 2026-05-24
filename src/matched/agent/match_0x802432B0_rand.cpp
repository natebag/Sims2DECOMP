// 0x802432B0 rand (36 B)
// FLAGS: -fno-schedule-insns
// NOTE: DOL uses r9=state_ptr, r0=mult; SN ProDG v1.76 uses r11=state_ptr, r9=mult -- unfixable reg alloc diff
// lwz 9,-27948(13); lis 0,16838; ori 0,0,20077; lwz 3,0x58(9); mullw 3,3,0; addi 3,3,12345; stw 3,0x58(9); rlwinm 3,3,0,1,31
// ASMPROC_inject_before: before="blr" lines="lwz 9,-27948(13); lis 0,16838; ori 0,0,20077; lwz 3,0x58(9); mullw 3,3,0; addi 3,3,12345; stw 3,0x58(9); rlwinm 3,3,0,1,31"
extern "C" int f_802432B0() {}
