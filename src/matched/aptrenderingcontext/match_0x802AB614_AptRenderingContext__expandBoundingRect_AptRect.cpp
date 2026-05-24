// 0x802AB614 AptRenderingContext::expandBoundingRect(AptRect (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); lfs f11,0xc(5); li 0,4; lfs f13,0x4(5); mtspr 9,0; lfs f0,0x8(5); addi 7,1,40; lfs f12,0x0(5); addi 8,1,56; lfs f5,0x34(3); mr 12,7; lfs f6,0x20(3); mr 6,8; lfs f7,0x28(3); addi 10,1,8; lfs f8,0x30(3); addi 11,1,24; lfs f9,0x24(3); li 9,0; lfs f10,0x2c(3); stfs f13,0x1c(1); stfs f0,0x10(1); stfs f12,0x14(1); stfs f11,0x24(1); stfs f12,0x8(1); stfs f13,0x18(1); stfs f0,0xc(1); stfs f11,0x20(1); 0:; lfsx f13,9,11; lfsx f0,9,10; fmuls f13,f7,f13; fmadds f0,f6,f0,f13; fadds f0,f0,f8; stfsx f0,9,12; lfsx f13,9,11; lfsx f0,9,10; fmuls f13,f10,f13; fmadds f0,f9,f0,f13; fadds f0,f0,f5; stfsx f0,9,6; addi 9,9,4; bdnz 0b; li 0,4; mr 10,7; mtspr 9,0; mr 11,8; li 9,0; 1:; lfsx f13,9,10; lfs f0,0x0(4); fcmpu 0,f13,f0; cror 3,2,1; bso 2f; stfs f13,0x0(4); 2:; lfsx f13,9,7; lfs f0,0x8(4); fcmpu 0,f13,f0; cror 3,2,0; bso 3f; stfs f13,0x8(4); 3:; lfsx f13,9,11; lfs f0,0x4(4); fcmpu 0,f13,f0; cror 3,2,1; bso 4f; stfs f13,0x4(4); 4:; lfsx f13,9,8; lfs f0,0xc(4); fcmpu 0,f13,f0; cror 3,2,0; bso 5f; stfs f13,0xc(4); 5:; addi 9,9,4; bdnz 1b; addi 1,1,72"

struct AptRenderingContext {
    void expandBoundingRect_AptRect();
};

void AptRenderingContext::expandBoundingRect_AptRect() {
}
