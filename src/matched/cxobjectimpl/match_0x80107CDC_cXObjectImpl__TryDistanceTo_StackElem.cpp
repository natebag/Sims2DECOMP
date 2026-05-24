// 0x80107CDC cXObjectImpl::TryDistanceTo(StackElem (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lwz 0,0x0(5); addi 9,1,8; lhz 11,0x4(5); mr 30,3; stw 0,0x8(1); mr 28,4; sth 11,0x4(9); lhz 0,0x8(1); cmplwi 0,7; mr 29,9; ble 0f; lwz 11,0x0(30); li 0,1; stw 0,-24512(13); li 9,2; sth 9,0x34(11); li 4,2; lwz 11,0x4(30); lwz 9,0x4(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; b 5f; 0:; lbz 0,0x2(29); andi. 9,0,1; bne 1f; li 4,3; b 2f; 1:; lbz 0,0x3(29); mr 4,0; 2:; lbz 0,0x2(29); extsh 4,4; andi. 9,0,1; bne 3f; li 0,11; b 4f; 3:; lhz 0,0x4(29); 4:; extsh 5,0; mr 3,30; li 6,0; li 7,0; addi 8,1,16; bl _s80107CDC_0; cmpwi 3,-1; bne 6f; cmpwi 4,-1; bne 6f; 5:; li 3,-1; li 4,-1; b 11f; 6:; lwz 3,0x4(30); lha 4,0x10(1); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 7f; lwz 3,0x4(30); lha 4,0x4(28); lwz 9,0x4(3); lha 0,0x488(9); lwz 9,0x48c(9); add 3,3,0; mtspr 8,9; blrl; mr. 3,3; bne 8f; 7:; lha 0,0x8(1); addi 11,30,22; li 9,-1; li 3,0; add 0,0,0; li 4,1; sthx 9,11,0; b 11f; 8:; lbz 0,0x2(29); andi. 9,0,2; beq 9f; lwz 9,0x4(31); mr 4,3; lwz 0,0x3c(9); lha 3,0x38(9); b 10f; 9:; lwz 9,0x4(31); mr 4,3; lwz 0,0x24(9); lha 3,0x20(9); 10:; mtspr 8,0; add 3,31,3; blrl; fctiwz f0,f1; lha 0,0x8(1); stfd f0,0x18(1); addi 11,30,22; add 0,0,0; lwz 9,0x1c(1); sthx 9,11,0; li 3,0; li 4,1; 11:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"

extern "C" void _s80107CDC_0();

struct cXObjectImpl {
    void TryDistanceTo_StackElem();
};

void cXObjectImpl::TryDistanceTo_StackElem() {
}
