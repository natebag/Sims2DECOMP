// 0x800F5668 ObjectModuleImpl::KillObject(short) (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; mfcr 12; stmw 27,0xc(1); stw 0,0x24(1); stw 12,0x8(1); mr 29,3; mr 28,4; lwz 9,0x0(29); lha 3,0x90(9); lwz 0,0x94(9); add 3,29,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 1f; 0:; li 30,0; 1:; cmpwi 30,0; beq 7f; addi 3,30,40; li 4,7; bl _s800F5668_0; li 31,1; lha 0,0x0(3); cmpwi 0,0; bne 2f; li 31,0; 2:; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x30c(9); lha 3,0x308(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,0x4(30); extsh 27,3; lwz 9,0x4(11); lha 3,0x390(9); lwz 0,0x394(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 4f; lwz 9,0x4(30); li 4,3; cmpwi 4,31,0; lwz 3,0x0(9); bl _s800F5668_1; mr 31,3; lwz 9,0x4(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; mr 31,3; 3:; lwz 11,0x0(31); lwz 9,0x4(11); lwz 0,0x2f4(9); lha 3,0x2f0(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x4(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; mr. 31,3; bne 3b; b 5f; 4:; lwz 3,0x4(30); cmpwi 4,31,0; lwz 9,0x4(3); lha 0,0x2f0(9); lwz 9,0x2f4(9); add 3,3,0; mtspr 8,9; blrl; 5:; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x12c(9); lha 3,0x128(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x208c(29); cmpwi 0,0; bne 6f; lwz 11,0x4(30); lwz 9,0x4(11); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,11,3; blrl; lhz 0,0xb6(3); rlwinm 0,0,0,29,30; cmpwi 0,0; beq 6f; lis 9,-32697; lwz 3,0x5e94(9); cmpwi 3,0; beq 6f; bl _s800F5668_2; 6:; mr 4,28; mr 3,29; li 5,0; bl _s800F5668_3; beq cr4,7f; lwz 0,0x208c(29); cmpwi 0,0; bne 7f; mr 4,27; li 3,239; bl _s800F5668_4; 7:; lwz 0,0x24(1); lwz 12,0x8(1); mtspr 8,0; lmw 27,0xc(1); mtcrf 8,12; addi 1,1,32"

extern "C" void _s800F5668_0();
extern "C" void _s800F5668_1();
extern "C" void _s800F5668_2();
extern "C" void _s800F5668_3();
extern "C" void _s800F5668_4();

struct ObjectModuleImpl {
    void KillObject_short();
};

void ObjectModuleImpl::KillObject_short() {
}
