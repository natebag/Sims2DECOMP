// 0x8001E3E0 CameraDirector::AnimEventHandler(AnimRef (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,5; lwz 0,0x4(4); cmpwi 0,12; bgt 0f; cmpwi 0,11; bge 7f; cmpwi 0,5; beq 4f; cmpwi 0,6; beq 5f; b 7f; 0:; cmpwi 0,14; beq 2f; blt 1f; cmpwi 0,15; beq 3f; b 7f; 1:; lwz 3,0x170(3); li 5,13; bl _s8001E3E0_0; b 7f; 2:; lwz 3,0x170(3); li 5,14; bl _s8001E3E0_1; b 7f; 3:; lwz 3,0x170(3); li 5,15; bl _s8001E3E0_2; b 7f; 4:; lwz 4,0x8(4); li 5,0; lwz 3,-21492(13); bl _s8001E3E0_3; b 7f; 5:; lwz 3,0x8(4); bl _s8001E3E0_4; cmpwi 3,101; blt 7f; cmpwi 3,103; bgt 6f; lis 9,-32697; li 0,-1; stw 0,0x6230(9); b 7f; 6:; cmpwi 3,105; bgt 7f; li 3,1; bl _s8001E3E0_5; 7:; li 3,0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8001E3E0_0();
extern "C" void _s8001E3E0_1();
extern "C" void _s8001E3E0_2();
extern "C" void _s8001E3E0_3();
extern "C" void _s8001E3E0_4();
extern "C" void _s8001E3E0_5();

struct CameraDirector {
    void AnimEventHandler();
};

void CameraDirector::AnimEventHandler() {
}
