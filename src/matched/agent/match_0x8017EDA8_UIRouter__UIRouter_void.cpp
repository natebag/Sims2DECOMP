// 0x8017EDA8 UIRouter::UIRouter(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; li 0,0; addi 9,9,-12328; stw 9,0x80(31); addi 10,31,40; stw 0,0x0(31); addi 9,31,56; stw 0,0x4(31); addi 8,31,72; stw 0,0x8(31); addi 7,31,88; stw 0,0xc(31); addi 6,31,104; stw 0,0x10(31); lis 11,-32698; stw 0,0x14(31); addi 11,11,26384; stw 0,0x18(31); stw 0,0x8(10); stw 0,0x28(31); stw 0,0x8(9); stw 0,0x38(31); stw 0,0x8(8); stw 0,0x48(31); stw 0,0x8(7); lwz 9,-31532(13); stw 0,0x58(31); stw 0,0x8(6); cmpwi 9,0; stw 0,0x78(31); stw 11,0x80(31); stw 0,0x68(31); bne 0f; li 3,16; bl _s8017EDA8_0; bl _s8017EDA8_1; stw 3,-31532(13); 0:; lwz 9,-31528(13); lwz 0,-31532(13); cmpwi 9,0; stw 0,0x84(31); bne 1f; li 3,16; bl _s8017EDA8_2; bl _s8017EDA8_3; stw 3,-31528(13); 1:; lwz 0,-31528(13); lis 9,-32697; mr 4,31; stw 0,0x88(31); lwz 3,0x5e80(9); bl _s8017EDA8_4; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8017EDA8_0();
extern "C" void _s8017EDA8_1();
extern "C" void _s8017EDA8_2();
extern "C" void _s8017EDA8_3();
extern "C" void _s8017EDA8_4();
extern "C" void f_8017EDA8() {}
