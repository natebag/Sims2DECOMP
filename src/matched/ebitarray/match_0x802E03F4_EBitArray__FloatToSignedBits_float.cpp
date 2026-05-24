// 0x802E03F4 EBitArray::FloatToSignedBits(float, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); addi 4,4,-1; li 9,1; slw 9,9,4; addi 9,9,-1; lis 0,17200; xoris 9,9,32768; lis 10,-32702; stw 9,0xc(1); lis 8,-32702; lfd f13,-6416(10); stw 0,0x8(1); lfs f12,-6408(8); lfd f0,0x8(1); fsub f0,f0,f13; frsp f13,f0; fmuls f1,f1,f13; fcmpu 0,f1,f12; bge 0f; lis 9,-32702; lfs f0,-6404(9); fsubs f1,f1,f0; b 1f; 0:; lis 9,-32702; lfs f0,-6404(9); fadds f1,f1,f0; 1:; fneg f0,f13; fcmpu 0,f1,f0; blt 2f; fmr f0,f1; fcmpu 0,f1,f13; ble 2f; fmr f0,f13; 2:; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); addi 1,1,16"

struct EBitArray {
    void FloatToSignedBits();
};

void EBitArray::FloatToSignedBits() {
}
