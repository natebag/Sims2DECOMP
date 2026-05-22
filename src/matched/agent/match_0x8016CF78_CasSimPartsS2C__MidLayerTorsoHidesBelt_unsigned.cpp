// 0x8016CF78 CasSimPartsS2C::MidLayerTorsoHidesBelt(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); extsb 5,5; cmpwi 0,0; beq 2f; cmpwi 6,2; bne 1f; 0:; li 3,0; blr; 1:; cmplwi 4,19; bge 0b; mulli 0,4,6; lis 9,-32706; addi 9,9,5255; li 3,1; add 0,5,0; lbzx 11,9,0; cmpwi 11,0; bnelr; li 3,0; blr; 2:; cmplwi 4,22; bge 0b; mulli 0,4,6; lis 9,-32706; addi 9,9,5123; li 3,1; add 0,5,0; lbzx 11,9,0; cmpwi 11,0; bnelr; li 3,0"
extern "C" int f_8016CF78() {}
