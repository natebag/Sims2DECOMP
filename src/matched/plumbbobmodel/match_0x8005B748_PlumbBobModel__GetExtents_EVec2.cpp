// 0x8005B748 PlumbBobModel::GetExtents(EVec2 (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 10,0x28(3); cmpwi 10,0; beqlr; lfs f12,0x58(10); lis 9,-32707; lfs f13,0x64(10); lis 11,-32707; lfs f0,0x88(10); lfs f11,0x0(3); fsubs f13,f13,f12; fmuls f0,f0,f13; lfs f8,0x4330(9); fmuls f0,f0,f11; lfs f10,0x432c(11); stfs f0,0x0(4); lfs f13,0x18(3); stfs f13,0x4(4); lfs f0,0x14(3); fadds f9,f13,f0; stfs f9,0x4(4); lwz 9,0x28(3); lfs f12,0x60(10); lfs f0,0x6c(10); lfs f13,0x88(9); lfs f11,0x0(3); fsubs f0,f0,f12; fmuls f13,f13,f0; fcmpu 0,f11,f8; fmuls f10,f13,f10; ble 0f; fsubs f0,f11,f8; fmadds f0,f0,f10,f9; stfs f0,0x4(4); 0:; lfs f0,0x0(3); lfs f12,0x4(3); lfs f13,0x4(4); fmuls f0,f10,f0; fmadds f0,f0,f12,f13; stfs f0,0x4(4)"

struct PlumbBobModel {
    void GetExtents_EVec2();
};

void PlumbBobModel::GetExtents_EVec2() {
}
