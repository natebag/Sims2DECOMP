// 0x80266C64 SamplingHandler (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-736(1); stw 31,0x2dc(1); addi 31,4,0; lwz 0,-23148(13); cmplwi 0,0; beq 0f; addi 3,1,16; bl _s80266C64_0; addi 3,1,16; bl _s80266C64_1; lwz 12,-23148(13); mtspr 8,12; blrl; addi 3,1,16; bl _s80266C64_2; mr 3,31; bl _s80266C64_3; 0:; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s80266C64_0();
extern "C" void _s80266C64_1();
extern "C" void _s80266C64_2();
extern "C" void _s80266C64_3();
extern "C" void f_80266C64() {}
