// 0x8007E0FC DlgWrapper::DialogPaneHide(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lis 4,-32707; lwz 9,0xb8(30); addi 4,4,27084; addi 9,9,-1; stw 9,0xb8(30); bl _s8007E0FC_0; lis 9,-32697; li 4,1; lwz 3,0x5e80(9); bl _s8007E0FC_1; li 0,0; lwz 3,0xac(30); stw 0,0xb4(30); bl _s8007E0FC_2; lwz 9,0xac(30); lwz 0,0x4(9); mr 3,9; rlwinm 0,0,0,0,30; stw 0,0x4(9); bl _s8007E0FC_3; lwz 3,0xac(30); bl _s8007E0FC_4; mr 3,30; bl _s8007E0FC_5; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8007E0FC_0();
extern "C" void _s8007E0FC_1();
extern "C" void _s8007E0FC_2();
extern "C" void _s8007E0FC_3();
extern "C" void _s8007E0FC_4();
extern "C" void _s8007E0FC_5();

struct DlgWrapper {
    void DialogPaneHide();
};

void DlgWrapper::DialogPaneHide() {
}
