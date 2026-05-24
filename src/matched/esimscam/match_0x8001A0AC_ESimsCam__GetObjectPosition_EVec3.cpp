// 0x8001A0AC ESimsCam::GetObjectPosition(EVec3 (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stw 31,0x5c(1); stw 0,0x64(1); lis 11,-32707; addi 9,1,8; lfs f0,-7124(11); mr 31,4; mr. 5,5; stfs f0,0x8(1); stfs f0,0x8(9); stfs f0,0x4(9); lwz 10,0x8(9); lwz 0,0x8(1); lwz 11,0x4(9); stw 0,0x0(31); stw 11,0x4(31); stw 10,0x8(31); beq 0f; lwz 3,0x0(5); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 0f; lwz 9,0x0(11); addi 4,1,24; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; addi 9,1,72; lwz 10,0x48(1); lwz 0,0x8(9); lwz 11,0x4(9); stw 0,0x8(31); stw 10,0x0(31); stw 11,0x4(31); 0:; lwz 0,0x64(1); mtspr 8,0; lwz 31,0x5c(1); addi 1,1,96"

struct ESimsCam {
    void GetObjectPosition();
};

void ESimsCam::GetObjectPosition() {
}
