// 0x801F0904 INVTarget::Cheat_HandleReturnUpHierarchy(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lbz 11,0x138(31); cmpwi 11,1; beq 0f; bgt 1f; cmpwi 11,0; bne 1f; lis 9,-32704; lhz 0,-30824(9); sth 0,0x0(4); stb 11,0x189(31); b 1f; 0:; lis 9,-32704; mr 3,31; lhz 0,-30820(9); sth 0,0x0(4); stb 11,0x18a(31); lbz 9,0x138(31); addi 9,9,-1; stb 9,0x138(31); bl _s801F0904_0; li 0,0; stb 0,0x3251(31); stb 0,0x189(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801F0904_0();
extern "C" void f_801F0904() {}
