// 0x80024F98 EHouse::UpdateRoomLights(void) (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 25,0x1c(1); stw 0,0x44(1); mr 26,3; lwz 9,0x1c(26); addis 11,9,3; lwz 0,-25232(11); cmpwi 0,0; beq 0f; lis 9,-32695; lwz 0,-29788(9); xori 0,0,1; stw 0,-25232(11); 0:; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; addi 3,3,-7; cmplwi 3,11; ble 1f; lis 9,-32707; lfs f31,0x9c8(9); b 2f; 1:; lis 9,-32707; lfs f31,0x9cc(9); 2:; lwz 27,-21472(13); addi 28,1,8; li 25,0; lwz 9,0x4(27); lwz 29,0x8(9); b 6f; 3:; lwz 31,0x14(29); cmpwi 31,0; beq 5f; stfs f31,0x48(31); mr 3,27; lhz 4,0x2(31); bl _s80024F98_0; lwz 0,0x34(31); mr 30,3; cmpwi 0,0; beq 5f; cmpwi 30,0; beq 5f; lwz 0,0x44(30); cmpwi 0,0; beq 5f; lhz 0,0x0(30); addi 7,30,56; cmpwi 0,0; bne 4f; lwz 9,0x1c(26); lwz 10,0x38(30); lwz 8,0x4(7); addis 9,9,3; lwz 0,0x8(7); addi 11,9,-7284; stw 10,-7284(9); stw 0,0x8(11); stw 8,0x4(11); 4:; lfs f0,0x38(30); mr 5,28; lwz 3,0x1c(26); stfs f0,0x8(1); lfs f13,0x4(7); stfs f13,0x4(28); lfs f0,0x8(7); stfs f0,0x8(28); lhz 4,0x0(30); bl _s80024F98_1; stw 25,0x44(30); 5:; mr 3,29; bl _s80024F98_2; mr 29,3; 6:; lwz 0,0x4(27); li 9,1; cmpw 29,0; bne 7f; li 9,0; 7:; cmpwi 9,0; bne 3b; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x1c(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s80024F98_0();
extern "C" void _s80024F98_1();
extern "C" void _s80024F98_2();

struct EHouse {
    void UpdateRoomLights();
};

void EHouse::UpdateRoomLights() {
}
