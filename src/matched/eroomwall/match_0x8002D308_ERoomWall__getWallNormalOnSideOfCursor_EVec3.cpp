// 0x8002D308 ERoomWall::getWallNormalOnSideOfCursor(EVec3 (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 31,0x2c(1); stw 0,0x34(1); lfs f12,0x8(4); lis 9,-32707; lfs f13,0x8(3); mr 31,6; lfs f0,0x0(4); fsubs f9,f12,f13; lfs f11,0x4(4); lfs f13,0x0(3); lfs f12,0x4(3); lfs f10,0xe14(9); fsubs f0,f0,f13; fsubs f11,f11,f12; stfs f0,0x18(1); fcmpu 0,f0,f10; stfs f9,0x20(1); stfs f11,0x1c(1); bne 0f; fcmpu 0,f11,f10; bne 0f; fcmpu 0,f9,f10; beq 1f; 0:; addi 3,1,24; mr 4,3; bl _s8002D308_0; 1:; lfs f13,0x18(1); addi 9,1,24; addi 11,1,8; stfs f13,0x8(1); lfs f0,0x4(9); stfs f0,0x4(11); lfs f13,0x8(9); stfs f13,0x8(11); lfs f0,0xc(1); lfs f13,0x8(1); fneg f0,f0; stfs f13,0x4(31); stfs f0,0x0(31); lwz 0,0x34(1); mtspr 8,0; lwz 31,0x2c(1); addi 1,1,48"

extern "C" void _s8002D308_0();

struct ERoomWall {
    void getWallNormalOnSideOfCursor_EVec3();
};

void ERoomWall::getWallNormalOnSideOfCursor_EVec3() {
}
