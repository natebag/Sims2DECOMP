// 0x801811E8 UIButtonImages::Shutdown(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-31492(13); cmpwi 3,0; beq 1f; bl _s801811E8_0; lwz 11,-31492(13); cmpwi 11,0; beq 0f; lwz 9,0xb0(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; stw 0,-31492(13); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801811E8_0();
extern "C" void f_801811E8() {}
