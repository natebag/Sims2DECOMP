// 0x8019A7F8 CASSelectionTarget::ConvertUiFocusToBodyTextureType(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,64; beq 2f; cmplwi 4,64; bgt 0f; cmpwi 4,63; beq 1f; b 4f; 0:; cmpwi 4,65; beq 3f; b 4f; 1:; li 0,0; stw 0,0x0(5); b 5f; 2:; li 0,1; stw 0,0x0(5); b 5f; 3:; li 0,2; stw 0,0x0(5); b 5f; 4:; li 3,0; blr; 5:; li 3,1"
extern "C" void f_8019A7F8() {}
