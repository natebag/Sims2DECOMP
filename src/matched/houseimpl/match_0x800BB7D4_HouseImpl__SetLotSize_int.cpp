// 0x800BB7D4 HouseImpl::SetLotSize(int, (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-21488(13); mr 29,3; mr 31,4; mr 30,5; lwz 11,0x0(9); lha 3,0x30(11); lwz 0,0x34(11); add 3,9,3; mtspr 8,0; blrl; cmpw 31,3; bne 0f; lwz 3,-21488(13); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; cmpw 30,3; beq 1f; 0:; lwz 11,-21484(13); li 4,0; li 5,0; mr 6,31; lwz 9,0x0(11); mr 7,30; lwz 0,0x74(9); lha 3,0x70(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); mr 4,31; mr 5,30; li 6,1; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lwz 9,0x0(29); lha 3,0x20(9); lwz 0,0x24(9); add 3,29,3; mtspr 8,0; blrl; li 3,257; li 4,0; bl _s800BB7D4_0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800BB7D4_0();

struct HouseImpl {
    void SetLotSize();
};

void HouseImpl::SetLotSize() {
}
