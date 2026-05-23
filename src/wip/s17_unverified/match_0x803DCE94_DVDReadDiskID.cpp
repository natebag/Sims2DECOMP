// 0x803DCE94 DVDReadDiskID (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_81AC42D8" lines="oris 0,8,0; rlwinm. 14,11,13,25,16; xoris 5,11,25632; xori 14,11,29556; subfic 3,20,31088; oris 0,8,0; sc; xoris 5,11,18798; andi. 20,27,24942; ori 5,27,0; sc; ori 20,11,26979; .long 0x4D6F6465; xoris 0,0,0; sc; xoris 21,27,29283; oris 0,8,0; .long 0x4E2F4100; sc; ori 18,11,24931; andis. 5,3,29184; sc; andis. 3,2,26721; andi. 1,19,25460; oris 18,11,0; sc; andis. 16,2,24935; oris 0,8,0; sc; andis. 19,2,27002; oris 0,8,0; sc; andis. 4,2,24948; ori 0,8,0; sc; xoris 20,19,0; ori 1,19,29541; subfic 3,20,25971; andis. 10,0,0; sc; ori 4,11,25970; .long 0x00000000; sc; oris 5,3,27648; sc; xoris 14,10,28516; oris 4,10,24948; ori 16,10,28531; .long 0x00000000; sc; xori 13,11,0; bl _s803DCE94_0"
extern "C" void _s803DCE94_0();
extern "C" void f_81AC42D8();
extern "C" void f_803DCE94() {}
