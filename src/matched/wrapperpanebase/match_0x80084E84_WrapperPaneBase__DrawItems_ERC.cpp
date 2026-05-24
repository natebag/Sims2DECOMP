// 0x80084E84 WrapperPaneBase::DrawItems(ERC (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,4; lwz 0,0x4(30); mr 28,5; andi. 9,0,1; beq 2f; lis 9,-32707; lfs f13,0x30(30); lfs f0,0x729c(9); fcmpu 0,f13,f0; beq 2f; addi 9,30,8; lwz 31,0x8(30); lwz 0,0x4(9); mr 29,9; cmpw 31,0; beq 2f; 0:; lwz 11,0x0(31); lwz 0,0x4(11); rlwinm 0,0,29,31,31; cmpw 28,0; bne 1f; lwz 9,0x1c(11); mr 4,27; lfs f1,0x30(30); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x4(29); addi 31,31,4; cmpw 31,0; bne 0b; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

struct WrapperPaneBase {
    void DrawItems();
};

void WrapperPaneBase::DrawItems() {
}
