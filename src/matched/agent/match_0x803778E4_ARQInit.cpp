// 0x803778E4 ARQInit (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); lwz 0,-22292(13); cmpwi 0,1; beq 0f; lwz 3,-25376(13); bl _s803778E4_0; li 31,0; li 0,4096; stw 31,-22328(13); lis 3,-32713; stw 31,-22336(13); addi 3,3,30688; stw 0,-22296(13); bl _s803778E4_1; li 0,1; stw 31,-22312(13); stw 31,-22308(13); stw 31,-22304(13); stw 31,-22300(13); stw 0,-22292(13); 0:; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s803778E4_0();
extern "C" void _s803778E4_1();
extern "C" void f_803778E4() {}
