// 0x801885AC HUDTarget::UpdateClock(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,-21496(13); cmpwi 31,0; beq 4f; lwz 9,0x0(31); li 4,5; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; mr 4,3; lis 3,-32705; addi 3,3,-19532; bl _s801885AC_0; lwz 9,0x0(31); li 4,6; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; mr 4,3; lis 3,-32705; addi 3,3,-19524; bl _s801885AC_1; lwz 9,0x0(31); li 4,0; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; mr 31,3; lis 3,-32705; mr 4,31; addi 3,3,-19516; bl _s801885AC_2; cmplwi 31,11; ble 0f; lis 3,-32705; lis 4,-32705; addi 3,3,-19508; addi 4,4,-19496; bl _s801885AC_3; b 1f; 0:; lis 3,-32705; lis 4,-32705; addi 3,3,-19508; addi 4,4,-19488; bl _s801885AC_4; 1:; cmplwi 31,12; ble 2f; addi 31,31,-12; 2:; cmpwi 31,0; bne 3f; li 31,12; 3:; lis 3,-32705; mr 4,31; addi 3,3,-19480; bl _s801885AC_5; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801885AC_0();
extern "C" void _s801885AC_1();
extern "C" void _s801885AC_2();
extern "C" void _s801885AC_3();
extern "C" void _s801885AC_4();
extern "C" void _s801885AC_5();

struct HUDTarget {
    void UpdateClock();
};

void HUDTarget::UpdateClock() {
}
