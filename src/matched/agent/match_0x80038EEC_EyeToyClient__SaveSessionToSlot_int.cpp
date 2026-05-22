// 0x80038EEC EyeToyClient::SaveSessionToSlot(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-32548(13); mr 31,3; cmpwi 0,0; beq 0f; bl _s80038EEC_0; cmpwi 3,0; beq 0f; bl _s80038EEC_1; mr 4,3; li 5,1; mr 3,31; bl _s80038EEC_2; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80038EEC_0();
extern "C" void _s80038EEC_1();
extern "C" void _s80038EEC_2();
extern "C" void f_80038EEC() {}
