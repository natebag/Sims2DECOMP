// 0x80345284 ENgcRenderer::AlphaTest(EDLEntry (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 10,0x1(4); lwz 8,0x4d8(3); lbz 7,0x3(4); cmpwi 10,0; lbz 0,0x2(4); beq 0f; lwz 11,0x6cc(8); lis 9,-32702; addi 9,9,7716; rlwinm 0,0,2,0,29; lwzx 10,9,0; oris 11,11,32768; li 0,0; ori 11,11,64; li 9,7; stb 0,0x3c9(8); stw 10,0x3b8(8); stb 7,0x3bc(8); stw 9,0x3c4(8); stw 11,0x6cc(8); stw 0,0x3c0(8); stb 0,0x3c8(8); blr; 0:; lwz 0,0x6cc(8); li 9,7; li 11,1; stw 9,0x3c4(8); oris 0,0,32768; stb 11,0x3c9(8); ori 0,0,64; stb 10,0x3c8(8); stw 0,0x6cc(8); stw 9,0x3b8(8); stb 10,0x3bc(8); stw 11,0x3c0(8)"

struct ENgcRenderer {
    void AlphaTest_EDLEntry();
};

void ENgcRenderer::AlphaTest_EDLEntry() {
}
