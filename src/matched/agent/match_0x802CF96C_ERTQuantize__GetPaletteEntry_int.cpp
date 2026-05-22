// 0x802CF96C ERTQuantize::GetPaletteEntry(int, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x10a8(3); cmpw 4,0; bge 0f; mulli 4,4,12; addi 4,4,4324; add 4,3,4; bl _s802CF96C_0; b 1f; 0:; li 0,0; stb 0,0x2(5); stb 0,0x0(5); stb 0,0x1(5); 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802CF96C_0();
extern "C" void f_802CF96C() {}
