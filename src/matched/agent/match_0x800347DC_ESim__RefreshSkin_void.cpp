// 0x800347DC ESim::RefreshSkin(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 11,0x3d0(31); cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x160(9); lwz 0,0x164(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; mr 3,31; bl _s800347DC_0; mr. 3,3; bne 0f; lwz 0,0x630(31); cmpwi 0,-1; bne 0f; li 0,1; stw 3,0x630(31); stw 0,0x3d8(31); addi 3,31,820; bl _s800347DC_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800347DC_0();
extern "C" void _s800347DC_1();
extern "C" void f_800347DC() {}
