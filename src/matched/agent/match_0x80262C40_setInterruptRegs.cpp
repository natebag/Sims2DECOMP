// 0x80262C40 setInterruptRegs (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 5,0x18(3); srawi 4,5,1; addze 4,4; srawi 0,5,1; addze 0,0; rlwinm 0,0,1,0,30; subfc 0,0,5; rlwinm. 0,0,0,16,31; rlwinm 4,4,0,16,31; beq 0f; lhz 3,0x1a(3); b 1f; 0:; li 3,0; 1:; addi 0,3,1; lis 3,-32694; addi 5,3,-16744; sth 0,0x32(5); addi 0,4,1; ori 0,0,4096; lwz 3,-23240(13); lwz 4,-23236(13); ori 3,3,64; stw 4,-23236(13); stw 3,-23240(13); sth 0,0x30(5); lwz 0,-23240(13); lwz 3,-23236(13); ori 0,0,128; stw 3,-23236(13); stw 0,-23240(13)"
extern "C" void f_80262C40() {}
