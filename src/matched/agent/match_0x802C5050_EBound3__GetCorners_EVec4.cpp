// 0x802C5050 EBound3::GetCorners(EVec4 (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,8; lis 9,-32702; mtspr 9,0; lfs f11,-7584(9); addi 11,3,12; li 9,0; 0:; andi. 0,9,1; beq 1f; lfs f12,0xc(3); b 2f; 1:; lfs f12,0x0(3); 2:; andi. 0,9,2; beq 3f; lfs f13,0x4(11); b 4f; 3:; lfs f13,0x4(3); 4:; andi. 0,9,4; beq 5f; lfs f0,0x8(11); b 6f; 5:; lfs f0,0x8(3); 6:; stfs f12,0x0(4); addi 9,9,1; stfs f13,0x4(4); stfs f0,0x8(4); stfs f11,0xc(4); addi 4,4,16; bdnz 0b"
extern "C" void f_802C5050() {}
