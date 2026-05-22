// 0x802513C0 OSGetResetCode (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32694; addi 3,3,-24816; lwz 0,0x0(3); cmpwi 0,0; beq 0f; lwz 0,0x4(3); oris 3,0,32768; b 1f; 0:; lis 3,-13312; addi 3,3,12288; lwz 0,0x24(3); rlwinm 0,0,0,0,28; rlwinm 3,0,29,3,31; 1:"
extern "C" int f_802513C0() {}
