// 0x80086994 Wrapper::WrapperDraw(ERC (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 26,0x8(1); stw 0,0x2c(1); mr 29,4; mr 28,3; lwz 9,0x70(29); li 4,0; li 5,2; li 6,0; lwz 0,0x1cc(9); li 7,0; lha 3,0x1c8(9); li 27,0; mtspr 8,0; add 3,29,3; blrl; addi 11,28,140; lwz 30,0x8c(28); lwz 0,0x4(11); cmpw 30,0; beq 2f; lis 9,-32707; mr 26,11; lfs f31,0x7304(9); 0:; lwz 31,0x0(30); lfs f0,0x30(31); fcmpu 0,f0,f31; ble 1f; lwz 9,0x5c(31); mr 4,29; li 27,1; lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x5c(31); mr 4,29; li 5,1; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x4(26); addi 30,30,4; cmpw 30,0; bne 0b; 2:; cmpwi 27,0; beq 5f; lwz 0,0xa0(28); cmpwi 0,0; beq 5f; addi 9,28,140; lwz 30,0x8c(28); lwz 0,0x4(9); mr 31,9; cmpw 30,0; beq 5f; lis 9,-32707; lfs f31,0x7304(9); 3:; lwz 11,0x0(30); lfs f0,0x30(11); fcmpu 0,f0,f31; ble 4f; lwz 9,0x5c(11); mr 4,29; li 5,0; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 4:; lwz 0,0x4(31); addi 30,30,4; cmpw 30,0; bne 3b; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x8(1); lfd f31,0x20(1); addi 1,1,40"

struct Wrapper {
    void WrapperDraw();
};

void Wrapper::WrapperDraw() {
}
