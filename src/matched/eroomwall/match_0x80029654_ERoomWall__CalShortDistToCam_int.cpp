// 0x80029654 ERoomWall::CalShortDistToCam(int) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 24,0x68(1); stw 0,0x8c(1); lis 9,-32707; mr 26,4; lfs f1,0xd1c(9); rlwinm 0,26,2,0,29; addi 8,3,52; stfsx f1,8,0; lwz 30,0x14(3); cmpwi 30,0; beq 3f; lis 11,-32697; addi 10,1,8; lwz 9,0x5e9c(11); mr 24,10; mr 28,0; mr 29,8; lfs f13,0x418(9); li 25,1; addi 9,9,1048; addi 27,1,72; stfs f13,0x8(1); lfs f0,0x4(9); stfs f0,0x4(10); lfs f13,0x8(9); stfs f13,0x8(10); 0:; lwz 31,0x0(30); mr 4,26; mr 3,31; bl _s80029654_0; cmpwi 3,0; beq 2f; addi 4,31,192; addi 3,1,24; bl _s80029654_1; lfs f10,0x4(27); addi 3,1,88; lfs f9,0x8(27); lfs f13,0x4(24); lfs f12,0x8(24); lfs f0,0x8(1); fsubs f13,f13,f10; lfs f11,0x48(1); fsubs f12,f12,f9; stfs f13,0x5c(1); fsubs f0,f0,f11; stfs f12,0x60(1); stfs f0,0x58(1); bl _s80029654_2; cmpwi 25,0; beq 1f; stfsx f1,29,28; li 25,0; b 2f; 1:; lfsx f0,29,28; fcmpu 0,f1,f0; bge 2f; stfsx f1,29,28; 2:; lwz 30,0x8(30); cmpwi 30,0; bne 0b; lfsx f1,29,28; 3:; lwz 0,0x8c(1); mtspr 8,0; lmw 24,0x68(1); addi 1,1,136"

extern "C" void _s80029654_0();
extern "C" void _s80029654_1();
extern "C" void _s80029654_2();

struct ERoomWall {
    void CalShortDistToCam();
};

void ERoomWall::CalShortDistToCam() {
}
