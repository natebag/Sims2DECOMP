// 0x801897EC HUDTarget::GetHUDData(short, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,5; cmpwi 4,5; bne 0f; lwz 0,0xa0(3); cmpwi 0,0; beq 0f; bl _s801897EC_0; sth 3,0x0(31); b 2f; 0:; rlwinm 0,4,0,16,31; cmplwi 0,5; ble 1f; li 3,0; b 3f; 1:; lwz 0,0x104(3); addi 11,3,164; mulli 0,0,6; add 0,4,0; lbzx 9,11,0; sth 9,0x0(31); 2:; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801897EC_0();

struct HUDTarget {
    void GetHUDData_short();
};

void HUDTarget::GetHUDData_short() {
}
