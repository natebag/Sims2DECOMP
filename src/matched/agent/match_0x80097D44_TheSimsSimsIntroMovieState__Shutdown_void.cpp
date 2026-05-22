// 0x80097D44 TheSimsSimsIntroMovieState::Shutdown(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x24(3); cmpwi 0,0; beq 0f; li 0,1; li 9,0; stw 0,-28408(13); stw 0,-28404(13); stw 9,0x24(3); 0:; lis 3,-32697; addi 3,3,23428; bl _s80097D44_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80097D44_0();
extern "C" void f_80097D44() {}
