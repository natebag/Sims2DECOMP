// 0x801758A8 CasScenePersonal::GetMirrorCorners(CasScene::RoomId, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; bne 1f; lis 9,-32696; li 11,48; addi 9,9,31204; 0:; lwz 0,0x0(9); addic. 11,11,-24; stw 0,0x0(5); lwz 0,0x4(9); stw 0,0x4(5); lwz 0,0x8(9); stw 0,0x8(5); lwz 0,0xc(9); stw 0,0xc(5); lwz 0,0x10(9); stw 0,0x10(5); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(5); addi 5,5,24; bne 0b; li 3,1; blr; 1:; li 3,0"
extern "C" void f_801758A8() {}
