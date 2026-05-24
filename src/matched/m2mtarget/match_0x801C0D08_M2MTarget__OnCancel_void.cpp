// 0x801C0D08 M2MTarget::OnCancel(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x11c(31); cmpwi 0,11; blt 1f; cmpwi 0,12; ble 0f; cmpwi 0,15; bne 1f; 0:; mr 3,31; bl _s801C0D08_0; b 3f; 1:; lwz 0,0x10c(31); cmpwi 0,255; bne 2f; li 30,1; mr 3,31; stw 30,0x11c(31); bl _s801C0D08_1; stw 30,0x180(31); b 3f; 2:; lwz 0,0x110(31); cmpwi 0,255; bne 3f; stw 0,0x10c(31); mr 3,31; bl _s801C0D08_2; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801C0D08_0();
extern "C" void _s801C0D08_1();
extern "C" void _s801C0D08_2();

struct M2MTarget {
    void OnCancel();
};

void M2MTarget::OnCancel() {
}
