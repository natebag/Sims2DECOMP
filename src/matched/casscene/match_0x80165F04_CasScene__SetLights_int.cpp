// 0x80165F04 CasScene::SetLights(int) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; blt 0f; mr 12,4; cmpwi 12,3; ble 1f; li 12,3; b 1f; 0:; li 12,0; 1:; mulli 9,12,608; addi 11,31,8; li 10,240; mr 7,9; add 9,9,31; addi 9,9,256; 2:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 2b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 8,0xa80(31); cmpwi 8,0; beq 3f; add 9,7,31; mulli 11,12,608; addi 9,9,504; lwz 0,0xac(9); addis 8,8,3; addi 9,9,172; addi 10,8,-7268; lwz 7,0x8(9); add 11,11,31; lwz 6,0x4(9); addi 11,11,504; stw 0,-7268(8); mulli 9,12,608; stw 7,0x8(10); addi 4,8,-7296; stw 6,0x4(10); addi 7,11,144; addi 3,31,860; lwz 0,0x90(11); lwz 6,0x8(7); mr 11,9; lwz 5,0x4(7); add 9,9,31; stw 0,-7296(8); mr 10,11; stw 5,0x4(4); add 11,11,31; stw 6,0x8(4); addi 11,11,688; addi 7,11,144; mr 5,10; lfs f0,0x284(9); add 10,10,31; stfs f0,-7300(8); lwz 9,0xa80(31); lwz 8,0x90(11); lwz 6,0x8(7); addis 9,9,3; lwz 0,0x4(7); addi 11,9,-7112; stw 8,-7112(9); stw 6,0x8(11); stw 0,0x4(11); lfs f0,0x33c(10); stfs f0,-7116(9); lfsx f13,3,5; lwz 9,0xa80(31); stfs f13,0x14(9); lwz 3,0xa80(31); bl _s80165F04_0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80165F04_0();

struct CasScene {
    void SetLights();
};

void CasScene::SetLights() {
}
