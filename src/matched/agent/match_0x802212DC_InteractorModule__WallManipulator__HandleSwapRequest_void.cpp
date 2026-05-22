// 0x802212DC InteractorModule::WallManipulator::HandleSwapRequest(void) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-31536(13); mr 31,3; li 0,0; stw 0,0xc4(31); cmpwi 9,0; bne 0f; li 3,120; bl _s802212DC_0; bl _s802212DC_1; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,100; ori 4,4,44053; bl _s802212DC_2; mr 3,31; li 4,4; bl _s802212DC_3; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802212DC_0();
extern "C" void _s802212DC_1();
extern "C" void _s802212DC_2();
extern "C" void _s802212DC_3();
extern "C" void f_802212DC() {}
