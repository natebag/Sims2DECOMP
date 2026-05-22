// 0x802219B4 InteractorModule::WallManipulator::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,1; beq 4f; bgt 0f; cmpwi 4,0; beq 1f; b 8f; 0:; cmpwi 4,2; beq 5f; cmpwi 4,4; beq 6f; b 8f; 1:; lwz 0,0xc4(3); andi. 9,0,17; bne 3f; lwz 9,-31536(13); ori 0,0,3; stw 0,0xc4(3); cmpwi 9,0; bne 2f; li 3,120; bl _s802219B4_0; bl _s802219B4_1; stw 3,-31536(13); 2:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s802219B4_2; b 8f; 3:; ori 0,0,32; b 7f; 4:; lwz 0,0xc4(3); andi. 9,0,512; beq 8f; rlwinm 0,0,0,0,30; ori 0,0,4096; b 7f; 5:; lwz 9,0xc4(3); xori 0,9,1; andi. 11,0,1; beq 8f; ori 0,9,16; b 7f; 6:; lwz 0,0xc4(3); ori 0,0,64; 7:; stw 0,0xc4(3); 8:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802219B4_0();
extern "C" void _s802219B4_1();
extern "C" void _s802219B4_2();
extern "C" void f_802219B4() {}
