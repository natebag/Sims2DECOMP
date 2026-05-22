// 0x8003AC20 _Deque_base<StateMachineStatus (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,120; bl _s8003AC20_0; bl _s8003AC20_1; stw 3,-31536(13); lis 4,28199; cmpwi 30,0; lwz 3,-31536(13); mfcr 31; ori 4,4,30903; beq 0f; lis 4,14155; ori 4,4,56554; 0:; bl _s8003AC20_2; mtcrf 128,31; beq 1f; lwz 0,0x0(26); cmpw 0,23; bne 1f; li 0,0; stw 0,0x0(26); 1:; mtcrf 128,24; beq 2f; li 0,1; mr 3,26; stw 0,0x4(26); bl _s8003AC20_3; 2:; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s8003AC20_0();
extern "C" void _s8003AC20_1();
extern "C" void _s8003AC20_2();
extern "C" void _s8003AC20_3();
extern "C" void f_8003AC20() {}
