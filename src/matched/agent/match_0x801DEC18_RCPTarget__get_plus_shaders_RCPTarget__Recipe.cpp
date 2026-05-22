// 0x801DEC18 RCPTarget::get_plus_shaders(RCPTarget::Recipe (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(4); cmpwi 0,3; beq 4f; bgt 0f; cmpwi 0,1; beq 4f; bgt 4f; cmpwi 0,0; beq 1f; b 5f; 0:; cmpwi 0,5; beq 2f; blt 2f; cmpwi 0,6; beq 4f; b 5f; 1:; lis 0,-24685; ori 0,0,65396; b 3f; 2:; lis 0,-24685; ori 0,0,10960; 3:; stw 0,0x0(5); stw 0,0x0(6); b 6f; 4:; lis 0,-24685; lis 9,-24685; ori 0,0,10960; ori 9,9,65396; stw 0,0x0(5); stw 9,0x0(6); b 6f; 5:; lis 0,-24685; li 3,0; ori 0,0,65396; stw 0,0x0(5); stw 0,0x0(6); blr; 6:; li 3,1"
extern "C" void f_801DEC18() {}
