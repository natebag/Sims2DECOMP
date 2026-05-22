// 0x80262E10 setScalingRegs (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,0; lis 5,-32694; addi 5,5,-16744; beq 0f; rlwinm 0,3,1,15,30; b 1f; 0:; rlwinm 0,3,0,16,31; 1:; rlwinm 6,0,0,16,31; rlwinm 4,4,0,16,31; cmplw 6,4; bge 2f; rlwinm 3,6,8,0,23; addi 0,3,-1; add 0,4,0; divwu 0,0,4; ori 0,0,4096; sth 0,0x4a(5); lis 0,1024; lwz 3,-23240(13); lwz 4,-23236(13); or 0,4,0; stw 0,-23236(13); stw 3,-23240(13); sth 6,0x70(5); lwz 3,-23240(13); lwz 0,-23236(13); ori 0,0,128; stw 0,-23236(13); stw 3,-23240(13); blr; 2:; li 0,256; sth 0,0x4a(5); lis 0,1024; lwz 3,-23240(13); lwz 4,-23236(13); or 0,4,0; stw 0,-23236(13); stw 3,-23240(13)"
extern "C" void f_80262E10() {}
