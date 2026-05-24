// 0x80105DD4 cXObjectImpl::TryRandom(StackElem (384 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); lwz 29,0x0(5); lwz 30,0x4(5); addi 6,1,12; mr 28,3; mr 27,6; extsh 4,29; srawi 5,29,16; addi 7,1,16; li 8,0; bl _s80105DD4_0; cmpwi 3,-1; bne 0f; cmpwi 4,-1; beq 5f; 0:; mr 3,28; extsh 4,30; srawi 5,30,16; li 6,0; li 7,0; addi 8,1,8; bl _s80105DD4_1; cmpwi 3,-1; bne 1f; cmpwi 4,-1; beq 5f; 1:; lha 31,0x8(1); cmpwi 31,0; bne 2f; lwz 11,0x0(28); li 0,1; stw 0,-24512(13); li 9,4; sth 9,0x34(11); li 4,4; b 4f; 2:; lwz 0,0xc(1); cmpwi 0,0; beq 3f; bl _s80105DD4_2; mr 7,3; srawi 5,29,16; divwu 0,7,31; extsh 4,29; mr 3,28; mr 6,27; mullw 0,0,31; subf 7,0,7; extsh 7,7; bl _s80105DD4_3; b 7f; 3:; lwz 0,0x10(1); cmpwi 0,0; bne 6f; lwz 11,0x0(28); li 0,1; stw 0,-24512(13); li 9,19; sth 9,0x34(11); li 4,19; 4:; lwz 11,0x4(28); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; 5:; li 3,-1; li 4,-1; b 8f; 6:; bl _s80105DD4_4; divwu 0,3,31; lis 10,17200; lis 9,-32706; lfd f13,-15944(9); lwz 8,0x10(1); mullw 0,0,31; subf 3,0,3; extsh 3,3; xoris 3,3,32768; stw 3,0x24(1); stw 10,0x20(1); lfd f0,0x20(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x0(8); 7:; li 3,0; li 4,1; 8:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"

extern "C" void _s80105DD4_0();
extern "C" void _s80105DD4_1();
extern "C" void _s80105DD4_2();
extern "C" void _s80105DD4_3();
extern "C" void _s80105DD4_4();

struct cXObjectImpl {
    void TryRandom_StackElem();
};

void cXObjectImpl::TryRandom_StackElem() {
}
