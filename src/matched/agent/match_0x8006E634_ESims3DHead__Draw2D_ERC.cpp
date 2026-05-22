// 0x8006E634 ESims3DHead::Draw2D(ERC (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lis 9,-32697; mr 8,3; lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; lwz 10,0x354(8); lis 9,-32697; lwz 11,0x5e8c(9); lwz 0,0x3d0(10); cmpw 11,0; bne 0f; lis 9,-32707; lfs f0,-32268(13); b 2f; 0:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; lis 9,-32707; lfs f0,-32276(13); lfs f12,-32272(13); b 3f; 1:; lis 9,-32707; lfs f0,-32276(13); 2:; lfs f12,-32264(13); 3:; lfs f13,0x5178(9); stfs f0,0x3a4(8); stfs f13,0x3a8(8); stfs f12,0x3ac(8); lfs f10,0x3ac(8); lis 11,-32707; lfs f13,0x3a0(8); addi 9,1,8; lfs f0,0x3a4(8); mr 3,8; lfs f12,0x398(8); fadds f13,f10,f13; lfs f11,0x517c(11); mr 4,9; stfs f0,0x8(1); fadds f13,f13,f11; stfs f10,0x4(9); fadds f0,f0,f12; stfs f13,0xc(9); stfs f0,0x8(9); bl _s8006E634_0; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s8006E634_0();
extern "C" void f_8006E634() {}
