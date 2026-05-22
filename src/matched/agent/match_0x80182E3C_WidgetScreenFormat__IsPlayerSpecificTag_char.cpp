// 0x80182E3C WidgetScreenFormat::IsPlayerSpecificTag(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,4; lis 4,-32705; mr 3,31; addi 4,4,-23704; bl _s80182E3C_0; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23692; bl _s80182E3C_1; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23684; bl _s80182E3C_2; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23672; bl _s80182E3C_3; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23660; bl _s80182E3C_4; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23652; bl _s80182E3C_5; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23644; bl _s80182E3C_6; cmpwi 3,0; li 3,1; beq 0f; lis 4,-32705; mr 3,31; addi 4,4,-23632; bl _s80182E3C_7; subfic 0,3,0; adde 3,0,3; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80182E3C_0();
extern "C" void _s80182E3C_1();
extern "C" void _s80182E3C_2();
extern "C" void _s80182E3C_3();
extern "C" void _s80182E3C_4();
extern "C" void _s80182E3C_5();
extern "C" void _s80182E3C_6();
extern "C" void _s80182E3C_7();
extern "C" void f_80182E3C() {}
