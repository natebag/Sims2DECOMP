// 0x802379B4 ERLevel::GetLightsAtLocation(EVec3 (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,6; addi 3,30,24; bl _s802379B4_0; li 0,0; addi 30,30,56; stw 0,0xf4(31); li 0,4; mtspr 9,0; 0:; lha 0,0x0(3); addi 3,3,2; cmpwi 0,-1; beq 1f; lwz 11,0xf4(31); rlwinm 8,0,5,0,26; add 7,30,8; rlwinm 11,11,5,0,26; lwz 0,0x1c(7); addi 11,11,112; addi 6,7,16; add 9,31,11; stw 0,0x1c(9); addi 5,9,16; lfs f0,0xc(7); stfs f0,0xc(9); lwzx 0,30,8; lwz 10,0x4(7); lwz 8,0x8(7); stwx 0,31,11; stw 10,0x4(9); stw 8,0x8(9); lwz 0,0x10(7); lwz 11,0x8(6); lwz 10,0x4(6); stw 0,0x10(9); stw 11,0x8(5); stw 10,0x4(5); lwz 9,0xf4(31); addi 9,9,1; stw 9,0xf4(31); bdnz 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802379B4_0();

struct ERLevel {
    void GetLightsAtLocation();
};

void ERLevel::GetLightsAtLocation() {
}
