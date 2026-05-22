// 0x801D1AFC GetObjSelector3dDisplayInfo(ObjSelector (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; beq 0f; lwz 3,0x38(3); cmpwi 3,0; bne 1f; 0:; li 3,0; blr; 1:; lwz 3,0xc0(3); cmpwi 3,0; beq 0b; lwz 10,0x0(3); li 0,0; mr 9,10; cmpwi 10,0; beq 2f; lwz 0,-4(9); 2:; cmpwi 0,0; beq 0b; lwz 9,0x0(10); li 11,0; li 8,1; stw 9,0x4(4); cmpwi 9,0; lwz 0,0x20(3); stw 0,0x0(4); lwz 9,0x8(10); stw 11,0xc(4); stw 9,0x8(4); bne 3f; li 8,0; 3:; mr 3,8"
extern "C" void f_801D1AFC() {}
