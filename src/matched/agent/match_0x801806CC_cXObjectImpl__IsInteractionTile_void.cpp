// 0x801806CC cXObjectImpl::IsInteractionTile(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,16; bl _s801806CC_0; bl _s801806CC_1; stw 3,-31484(13); lwz 9,-31544(13); lwz 0,-31484(13); cmpwi 9,0; stw 0,0x18(31); bne 0f; li 3,16; bl _s801806CC_2; bl _s801806CC_3; stw 3,-31544(13); 0:; lwz 9,-31540(13); lwz 0,-31544(13); cmpwi 9,0; stw 0,0x1c(31); bne 1f; li 3,32; bl _s801806CC_4; bl _s801806CC_5; stw 3,-31540(13); 1:; lwz 9,-31536(13); lwz 0,-31540(13); cmpwi 9,0; stw 0,0x20(31); bne 2f; li 3,120; bl _s801806CC_6; bl _s801806CC_7; stw 3,-31536(13); 2:; lwz 0,-31536(13); li 9,1; lis 4,-32706; lwz 3,0x8(31); stw 0,0x24(31); addi 4,4,15468; stw 9,0x0(31); mr 5,28; bl _s801806CC_8; mr 3,31; lwz 0,0x5c(1); lwz 12,0x44(1); mtspr 8,0; lmw 28,0x48(1); mtcrf 8,12; addi 1,1,88"
extern "C" void _s801806CC_0();
extern "C" void _s801806CC_1();
extern "C" void _s801806CC_2();
extern "C" void _s801806CC_3();
extern "C" void _s801806CC_4();
extern "C" void _s801806CC_5();
extern "C" void _s801806CC_6();
extern "C" void _s801806CC_7();
extern "C" void _s801806CC_8();
extern "C" void f_801806CC() {}
