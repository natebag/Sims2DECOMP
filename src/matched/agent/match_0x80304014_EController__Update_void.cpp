// 0x80304014 EController::Update(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; bne 0f; lwz 0,-26808(13); stw 0,-26636(13); 0:; lwz 3,0x200(31); li 4,0; bl _s80304014_0; lwz 3,0x200(31); lwz 4,0x1fc(31); bl _s80304014_1; mr 3,31; bl _s80304014_2; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80304014_0();
extern "C" void _s80304014_1();
extern "C" void _s80304014_2();
extern "C" void f_80304014() {}
