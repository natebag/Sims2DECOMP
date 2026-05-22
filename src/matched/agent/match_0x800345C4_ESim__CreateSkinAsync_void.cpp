// 0x800345C4 ESim::CreateSkinAsync(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s800345C4_0; mr. 3,3; bne 0f; lwz 0,0x630(31); cmpwi 0,-1; bne 0f; li 0,1; stw 3,0x630(31); stw 0,0x3d8(31); li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800345C4_0();
extern "C" void f_800345C4() {}
