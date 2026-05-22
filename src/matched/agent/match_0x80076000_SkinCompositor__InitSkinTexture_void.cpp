// 0x80076000 SkinCompositor::InitSkinTexture(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x10(3); lhz 9,-21264(13); cmpwi 0,0; beq 0f; lhz 0,-32202(13); b 1f; 0:; lhz 0,-32204(13); 1:; mullw 0,9,0; sth 0,0x0(3); li 10,0; lwz 9,0x18(3); lwz 11,0x14(9); stw 10,0x4(3); lbz 0,0x19(11); cmpwi 0,0; beqlr; li 0,1; stw 0,0x4(3)"
extern "C" void f_80076000() {}
