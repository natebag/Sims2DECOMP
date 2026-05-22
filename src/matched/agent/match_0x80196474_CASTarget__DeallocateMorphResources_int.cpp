// 0x80196474 CASTarget::DeallocateMorphResources(int) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmplwi 4,3; bgt 0f; rlwinm 0,4,3,0,28; add 0,0,4; rlwinm 0,0,6,0,25; add 9,0,3; cmpwi 9,-2640; beq 0f; mr 3,9; addi 3,3,2640; bl _s80196474_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80196474_0();
extern "C" void f_80196474() {}
