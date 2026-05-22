// 0x80262CBC setPicConfig (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 3,3,0,16,31; addi 0,3,15; srawi 0,0,4; addze 0,0; cmpwi 4,0; stb 0,0x0(7); bne 0f; lbz 0,0x0(7); b 1f; 0:; lbz 0,0x0(7); rlwinm 0,0,1,24,30; 1:; rlwinm 3,5,0,16,31; stb 0,0x0(8); srawi 0,3,4; addze 0,0; rlwinm 0,0,4,0,27; subfc 0,0,3; stb 0,0x0(10); rlwinm 4,6,0,16,31; lis 3,-32694; lbz 5,0x0(10); addi 0,4,15; addi 3,3,-16744; add 0,5,0; srawi 0,0,4; addze 0,0; stb 0,0x0(9); lis 0,2048; lbz 4,0x0(9); lbz 5,0x0(8); rlwimi 5,4,8,16,23; sth 5,0x48(3); lwz 3,-23240(13); lwz 4,-23236(13); or 0,4,0; stw 0,-23236(13); stw 3,-23240(13)"
extern "C" void f_80262CBC() {}
