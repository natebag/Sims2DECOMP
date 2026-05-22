// 0x8023FAB4 InitReadCounts (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 5,-32694; lis 0,1; lwz 9,-26480(5); ori 0,0,64512; lis 6,1; cmplw 9,0; ori 6,6,64512; bgt 0f; lis 9,-32694; lwz 6,-26480(9); 0:; lwz 0,-26480(5); lis 8,-32700; li 10,2; lis 7,-32694; subf 0,6,0; rlwinm 11,6,22,10,31; stw 0,-26480(5); lis 9,-32694; stw 10,-23472(8); rlwinm 0,6,0,22,31; stw 11,-26488(7); stw 0,-26484(9)"
extern "C" void f_8023FAB4() {}
