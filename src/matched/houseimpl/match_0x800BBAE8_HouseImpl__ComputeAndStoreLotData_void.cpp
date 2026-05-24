// 0x800BBAE8 HouseImpl::ComputeAndStoreLotData(void) (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lwz 11,-21484(13); mr 31,3; addi 4,1,8; addi 5,1,12; lwz 9,0x0(11); addi 6,1,16; addi 7,1,20; addi 8,1,24; lwz 0,0x204(9); addi 30,1,28; lha 3,0x200(9); mr 29,30; mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 4,30; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x1c(1); mr 30,3; cmpwi 0,0; bne 0f; lwz 0,0x18(1); cmpwi 0,0; 0:; lwz 11,0x14(31); li 0,1; stw 0,0x1c(1); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lwz 4,0x10(1); lwz 0,0x104(9); lha 3,0x100(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x14(31); lwz 4,0x14(1); lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 11,-21496(13); lwz 4,0x8(1); lwz 9,0x0(11); lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); lwz 4,0xc(1); lwz 9,0x0(11); add 4,30,4; lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); li 4,22; lhz 5,0x2(29); lwz 9,0x0(11); extsh 5,5; lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"

struct HouseImpl {
    void ComputeAndStoreLotData();
};

void HouseImpl::ComputeAndStoreLotData() {
}
