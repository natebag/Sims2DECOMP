// 0x802AB1E4 AptRenderingContext::pushColourTransform(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x3b8(3); li 8,24; addi 7,3,952; mr 11,3; rlwinm 9,10,5,0,26; add 9,9,3; addi 9,9,56; 0:; lwz 0,0x0(11); addic. 8,8,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(11); addi 10,10,1; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); stw 10,0x0(7)"

struct AptRenderingContext {
    void pushColourTransform();
};

void AptRenderingContext::pushColourTransform() {
}
