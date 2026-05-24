// 0x80291390 AptCIH::_getBoundingRect(AptRenderingContext (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 29,4; mr 28,5; bl _s80291390_0; li 30,0; cmpwi 3,19; bne 0f; mr 3,31; bl _s80291390_1; subfic 0,3,0; adde 30,0,3; 0:; cmpwi 30,0; bne 12f; mr 3,29; lwz 26,0x4c(31); bl _s80291390_2; li 27,0; mr 3,29; addi 4,31,16; bl _s80291390_3; li 30,0; mr 3,31; bl _s80291390_4; cmpwi 3,13; bne 1f; mr 3,31; bl _s80291390_5; subfic 0,3,0; adde 30,0,3; 1:; cmpwi 30,0; bne 3f; mr 3,31; li 30,0; bl _s80291390_6; cmpwi 3,18; bne 2f; mr 3,31; bl _s80291390_7; subfic 0,3,0; adde 30,0,3; 2:; cmpwi 30,0; beq 4f; 3:; li 27,1; 4:; cmpwi 27,0; beq 5f; lwz 3,0x4c(31); mr 5,28; mr 4,29; addi 3,3,36; bl _s80291390_8; b 11f; 5:; mr 3,31; li 30,0; bl _s80291390_9; cmpwi 3,14; bne 6f; mr 3,31; bl _s80291390_10; subfic 0,3,0; adde 30,0,3; 6:; cmpwi 30,0; beq 7f; lwz 3,0x4c(31); mr 5,28; mr 4,29; addi 3,3,28; bl _s80291390_11; b 11f; 7:; mr 3,31; li 30,0; bl _s80291390_12; cmpwi 3,15; bne 8f; mr 3,31; bl _s80291390_13; subfic 0,3,0; adde 30,0,3; 8:; cmpwi 30,0; beq 9f; lwz 5,0x4c(31); mr 4,28; mr 3,29; addi 5,5,80; bl _s80291390_14; b 11f; 9:; mr 3,31; li 30,0; bl _s80291390_15; cmpwi 3,17; bne 10f; mr 3,31; bl _s80291390_16; subfic 0,3,0; adde 30,0,3; 10:; cmpwi 30,0; bne 11f; lwz 3,0x8(26); mr 5,28; mr 4,29; li 6,0; bl _s80291390_17; 11:; mr 3,29; bl _s80291390_18; 12:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80291390_0();
extern "C" void _s80291390_1();
extern "C" void _s80291390_2();
extern "C" void _s80291390_3();
extern "C" void _s80291390_4();
extern "C" void _s80291390_5();
extern "C" void _s80291390_6();
extern "C" void _s80291390_7();
extern "C" void _s80291390_8();
extern "C" void _s80291390_9();
extern "C" void _s80291390_10();
extern "C" void _s80291390_11();
extern "C" void _s80291390_12();
extern "C" void _s80291390_13();
extern "C" void _s80291390_14();
extern "C" void _s80291390_15();
extern "C" void _s80291390_16();
extern "C" void _s80291390_17();
extern "C" void _s80291390_18();

struct AptCIH {
    void _getBoundingRect_AptRenderingContext();
};

void AptCIH::_getBoundingRect_AptRenderingContext() {
}
