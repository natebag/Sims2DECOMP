// 0x801930DC CASTarget::CreateScene(int) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 4,4; blt 1f; cmpwi 4,3; bgt 0f; li 3,2848; bl _s801930DC_0; bl _s801930DC_1; mr 31,3; b 2f; 0:; cmpwi 4,5; li 3,0; ble 4f; 1:; li 3,0; b 4f; 2:; cmpwi 31,0; beq 3f; mr 3,31; bl _s801930DC_2; 3:; mr 3,31; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801930DC_0();
extern "C" void _s801930DC_1();
extern "C" void _s801930DC_2();
extern "C" void f_801930DC() {}
