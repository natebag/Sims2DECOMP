// 0x800B3318 ChainResFile::Add(Memory::HandleNode (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,0xc(3); mr 9,8; li 8,0; lha 0,0x100(11); lwz 11,0x104(11); add 3,3,0; mtspr 8,11; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800B3318() {}
