// 0x802C550C EBound3::Compute(EVec3 (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); mr 7,3; mr. 5,5; beq 0f; lwz 0,0x0(4); addi 9,7,12; lwz 11,0x4(4); lwz 10,0x8(4); addi 5,5,-1; stw 0,0xc(7); addi 4,4,12; stw 10,0x8(9); stw 11,0x4(9); stw 11,0x4(7); lwz 0,0xc(7); stw 10,0x8(7); stw 0,0x0(7); bl _s802C550C_0; b 1f; 0:; lis 11,-32702; addi 9,1,8; lfs f0,-7580(11); addi 8,7,12; stfs f0,0x8(9); stfs f0,0x4(9); stfs f0,0x8(1); lwz 0,0x8(1); lwz 11,0x8(9); lwz 10,0x4(9); stw 0,0xc(7); stw 11,0x8(8); stw 10,0x4(8); stw 11,0x8(7); lwz 0,0xc(7); stw 10,0x4(7); stw 0,0x0(7); 1:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s802C550C_0();
extern "C" void f_802C550C() {}
