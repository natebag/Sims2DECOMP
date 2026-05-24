// 0x800FE068 cXObjectImpl::TryFind5WorstMotives(StackElem (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); lis 9,-32706; addi 11,1,8; lhz 8,0x4(5); mr 27,11; lhz 28,0x6(5); mr 31,3; addi 9,9,-16224; li 10,24; 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); cmpwi 8,1; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); beq 2f; ble 1f; cmpwi 8,2; beq 4f; 1:; cmpwi 31,0; beq 4f; lwz 9,0x4(31); li 4,2; lwz 3,0x0(9); b 3f; 2:; lwz 9,0x0(31); lwz 29,0x4(31); lwz 11,0x0(9); lwz 30,0x4(29); lwz 9,0x18(11); lha 0,0x488(30); lha 3,0x48(9); addi 30,30,1160; lwz 9,0x4c(9); add 29,29,0; add 3,11,3; mtspr 8,9; blrl; lwz 0,0x4(30); lha 4,0x4(3); mr 3,29; mtspr 8,0; blrl; mr. 3,3; beq 4f; lwz 3,0x0(3); li 4,2; 3:; bl _s800FE068_0; mr 30,3; b 5f; 4:; li 30,0; 5:; cmpwi 30,0; beq 6f; lwz 3,0x0(30); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,2; beq 7f; 6:; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,10; sth 9,0x34(11); li 4,10; b 8f; 7:; cmpwi 28,2; ble 9f; lwz 11,0x0(31); li 0,1; stw 0,-24512(13); li 9,30; sth 9,0x34(11); li 4,30; 8:; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 11f; 9:; lwz 9,0x4(30); li 4,0; lwz 0,0x64(9); lha 3,0x60(9); mtspr 8,0; add 3,30,3; blrl; stw 3,-31824(13); lis 6,-32752; mr 3,27; addi 6,6,-8172; li 4,8; li 5,4; bl _s800FE068_1; li 0,5; addi 9,31,22; mtspr 9,0; addi 3,27,2; 10:; lhz 0,0x0(3); addi 3,3,4; sth 0,0x0(9); addi 9,9,2; bdnz 10b; li 3,0; li 4,1; 11:; lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"

extern "C" void _s800FE068_0();
extern "C" void _s800FE068_1();

struct cXObjectImpl {
    void TryFind5WorstMotives_StackElem();
};

void cXObjectImpl::TryFind5WorstMotives_StackElem() {
}
