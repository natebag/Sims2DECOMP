// 0x8001B478 CameraDirector::AttachDummy(ENDummy (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; lwz 0,0x238(10); cmpwi 0,2; beq 5f; lwz 0,0x240(10); xori 0,0,1; andi. 9,0,1; beq 5f; cmpwi 4,0; bne 0f; cmpwi 5,0; bne 1f; stw 5,0x11c(10); stw 5,0x118(10); b 5f; 0:; lwz 9,0x48(4); cmpwi 5,0; addi 9,9,16; stw 9,0x118(10); b 2f; 1:; addi 0,10,288; stw 0,0x118(10); 2:; beq 3f; stw 5,0x11c(10); b 4f; 3:; addi 0,10,288; stw 0,0x11c(10); 4:; lis 9,-32707; li 0,1; lfs f0,-6876(9); li 11,0; stw 0,0x230(10); mr 3,10; stfs f0,0x22c(10); stw 11,0x220(10); bl _s8001B478_0; 5:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8001B478_0();

struct CameraDirector {
    void AttachDummy_ENDummy();
};

void CameraDirector::AttachDummy_ENDummy() {
}
