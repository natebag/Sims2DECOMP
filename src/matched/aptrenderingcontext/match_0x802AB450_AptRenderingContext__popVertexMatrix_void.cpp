// 0x802AB450 AptRenderingContext::popVertexMatrix(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; lis 5,-32694; lwz 11,0x3bc(10); addi 8,10,32; mr 3,8; addi 11,11,-1; mulli 9,11,24; stw 11,0x3bc(10); add 9,9,10; lwz 6,0x238(9); addi 9,9,568; lwz 0,0x4(9); lwz 11,0x8(9); lwz 7,0xc(9); stw 6,0x20(10); stw 0,0x4(8); stw 11,0x8(8); stw 7,0xc(8); lwz 0,0x14(9); lwz 11,0x10(9); stw 0,0x14(8); stw 11,0x10(8); lwz 0,-16168(5); mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct AptRenderingContext {
    void popVertexMatrix();
};

void AptRenderingContext::popVertexMatrix() {
}
