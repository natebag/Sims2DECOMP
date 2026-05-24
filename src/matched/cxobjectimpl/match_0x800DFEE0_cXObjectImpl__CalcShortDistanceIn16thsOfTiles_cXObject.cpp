// 0x800DFEE0 cXObjectImpl::CalcShortDistanceIn16thsOfTiles(cXObject (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 9,0x68(31); lwz 10,0x6c(31); lwz 8,0x4(31); stw 9,0x8(1); stw 10,0xc(1); lwz 11,0x4(8); lha 3,0x2d0(11); lwz 0,0x2d4(11); add 3,8,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x4(11); addi 31,1,8; lha 3,0x318(9); lwz 0,0x31c(9); add 3,11,3; mtspr 8,0; b 1f; 0:; lwz 3,0x4(31); addi 31,1,8; lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; 1:; blrl; cmpwi 3,2; beq 2f; lwz 9,0x4(31); addi 9,9,8; stw 9,0x4(31); lwz 9,0x8(1); addi 9,9,8; stw 9,0x8(1); 2:; lwz 9,0x4(30); lwz 0,0x344(9); lha 3,0x340(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(3); lwz 10,0x4(3); lwz 11,0x4(30); stw 9,0x10(1); stw 10,0x14(1); lha 3,0x2d0(11); lwz 0,0x2d4(11); add 3,30,3; mtspr 8,0; blrl; mr. 11,3; beq 3f; lwz 9,0x4(11); lha 3,0x318(9); lwz 0,0x31c(9); add 3,11,3; b 4f; 3:; lwz 9,0x4(30); lha 3,0x318(9); lwz 0,0x31c(9); add 3,30,3; 4:; mtspr 8,0; blrl; cmpwi 3,2; addi 10,1,16; beq 5f; lwz 9,0x4(10); addi 9,9,8; stw 9,0x4(10); lwz 9,0x10(1); addi 9,9,8; stw 9,0x10(1); 5:; lwz 7,0x4(10); lwz 0,0x4(31); lis 6,17200; lwz 9,0x8(1); lis 10,-32706; lwz 8,0x10(1); subf 0,7,0; mullw 0,0,0; lfd f0,-20768(10); subf 9,8,9; mullw 9,9,9; add 0,0,9; xoris 0,0,32768; stw 0,0x1c(1); stw 6,0x18(1); lfd f1,0x18(1); fsub f1,f1,f0; frsp f1,f1; bl _s800DFEE0_0; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s800DFEE0_0();

struct cXObjectImpl {
    void CalcShortDistanceIn16thsOfTiles_cXObject();
};

void cXObjectImpl::CalcShortDistanceIn16thsOfTiles_cXObject() {
}
