// 0x80345220 ENgcRenderer::ZTest(EDLEntry (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x1(4); li 6,0; lbz 8,0x3(4); lbz 10,0x2(4); cmpwi 0,0; stb 0,0x4644(3); stb 10,0x4645(3); stb 8,0x4646(3); beq 0f; li 6,1; 0:; lwz 11,0x4d8(3); lis 9,-32702; subfic 7,8,0; adde 8,7,8; addi 9,9,7688; lwz 0,0x6cc(11); rlwinm 10,10,2,0,29; lwzx 7,9,10; oris 0,0,32768; stb 8,0x3b4(11); ori 0,0,64; stb 6,0x3ac(11); stw 0,0x6cc(11); stw 7,0x3b0(11)"
extern "C" void f_80345220() {}
