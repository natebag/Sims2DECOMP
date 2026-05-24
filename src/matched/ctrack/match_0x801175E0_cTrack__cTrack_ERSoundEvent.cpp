// 0x801175E0 cTrack::cTrack(ERSoundEvent (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; lis 9,-32698; stw 30,0xc(31); addi 9,9,9032; stw 30,0x14(31); stw 30,0x18(31); mr 29,4; stw 9,0x94(31); addi 3,31,28; bl _s801175E0_0; addi 3,31,36; bl _s801175E0_1; addi 3,31,44; bl _s801175E0_2; li 9,1024; li 0,512; li 11,-1; stw 30,0x34(31); stw 30,0x38(31); li 4,0; stw 30,0x50(31); li 5,32; stw 30,0x7c(31); addi 3,31,84; stw 30,0x80(31); stw 30,0x84(31); stw 30,0x88(31); stw 30,0x8c(31); stw 30,0x90(31); stw 30,0x8(31); stw 30,0x4(31); stw 9,0x74(31); stw 0,0x78(31); stw 11,0x48(31); bl _s801175E0_3; mr 3,29; bl _s801175E0_4; lis 9,-32706; stw 30,0xc(31); lfs f0,-15080(9); stw 29,0x0(31); stfs f0,0x4c(31); stw 30,0x10(31); lwz 0,0x28(29); cmpwi 0,0; ble 0f; lwz 0,0x24(29); stw 0,0x10(31); 0:; lwz 9,0x10(31); cmpwi 9,0; beq 1f; lwz 0,0x4(9); cmpwi 0,0; ble 1f; lwz 0,0x0(9); stw 0,0x7c(31); 1:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801175E0_0();
extern "C" void _s801175E0_1();
extern "C" void _s801175E0_2();
extern "C" void _s801175E0_3();
extern "C" void _s801175E0_4();

struct cTrack {
    void cTrack_ERSoundEvent();
};

void cTrack::cTrack_ERSoundEvent() {
}
