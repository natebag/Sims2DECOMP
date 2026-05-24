// 0x800B6104 FamilyImpl::CreateFamilyInLot(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; li 30,0; lwz 9,0x0(31); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; addi 11,31,36; lwz 9,0x24(31); lwz 0,0x4(11); lwz 29,-21484(13); subf 0,9,0; srawi. 9,0,2; ble 1f; mr 27,11; li 28,0; 0:; lwz 10,-21476(13); addi 30,30,1; lwz 9,0x24(31); lwz 11,0x0(10); lwzx 4,9,28; lwz 0,0xc4(11); addi 28,28,4; lha 3,0xc0(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x0(29); mr 4,3; lwz 0,0x274(9); lha 3,0x270(9); mtspr 8,0; add 3,29,3; blrl; lwz 0,0x4(27); lwz 9,0x24(31); subf 0,9,0; srawi 0,0,2; cmpw 30,0; blt 0b; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

struct FamilyImpl {
    void CreateFamilyInLot();
};

void FamilyImpl::CreateFamilyInLot() {
}
