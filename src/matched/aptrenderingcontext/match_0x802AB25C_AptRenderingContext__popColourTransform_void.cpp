// 0x802AB25C AptRenderingContext::popColourTransform(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x3b8(3); li 8,24; mr 10,3; addi 11,11,-1; rlwinm 9,11,5,0,26; stw 11,0x3b8(3); add 9,9,3; addi 9,9,56; 0:; lwz 0,0x0(9); addic. 8,8,-24; stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10); lwz 0,0x8(9); stw 0,0x8(10); lwz 0,0xc(9); stw 0,0xc(10); lwz 0,0x10(9); stw 0,0x10(10); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(10); addi 10,10,24; bne 0b; lwz 0,0x0(9); stw 0,0x0(10); lwz 0,0x4(9); stw 0,0x4(10)"

struct AptRenderingContext {
    void popColourTransform();
};

void AptRenderingContext::popColourTransform() {
}
