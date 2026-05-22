// 0x801D7FD8 PCTTarget::calc_wallpaper_value(InteractorModule::Interactor::CallbackData (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 11,3; mr. 4,4; bne 0f; li 3,0; blr; 0:; lwz 0,0xe8(11); li 3,0; cmpwi 0,0; beq 1f; lwz 0,0x210(11); lwz 9,0x10(4); mullw 3,9,0; srawi 0,3,31; xor 3,0,3; subf 3,0,3; blr; 1:; lis 9,-32697; li 7,0; lwz 10,0x5ea4(9); lwz 9,0x0(10); cmpwi 9,0; beq 2f; lwz 7,-4(9); 2:; lwz 0,0x18(4); lwz 4,0x14(4); cmpw 4,0; beqlr; mr 8,0; 3:; lwz 9,0x0(4); cmpw 9,7; bge 4f; lwz 11,0x0(10); rlwinm 9,9,2,0,29; lwzx 9,11,9; cmpwi 9,0; beq 4f; lwz 0,0x0(9); lwz 9,0x4(4); mullw 0,0,9; add 3,3,0; 4:; addi 4,4,8; cmpw 4,8; bne 3b"
extern "C" int f_801D7FD8() {}
