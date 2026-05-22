// 0x80267E44 DBGHandler (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-13312; stw 0,0x4(1); li 0,4096; stwu 1,-8(1); lwz 12,-23052(13); stw 0,0x3000(5); cmplwi 12,0; beq 0f; mtspr 8,12; extsh 3,3; blrl; 0:; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void f_80267E44() {}
