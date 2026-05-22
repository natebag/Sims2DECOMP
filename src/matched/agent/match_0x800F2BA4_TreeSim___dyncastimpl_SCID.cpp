// 0x800F2BA4 TreeSim::_dyncastimpl(SCID) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,6; beq 6f; bgt 1f; cmpwi 4,2; beq 8f; bgt 0f; cmpwi 4,1; beq 10f; b 11f; 0:; cmpwi 4,3; beq 9f; cmpwi 4,5; beq 10f; b 11f; 1:; cmpwi 4,8; beq 3f; blt 2f; cmpwi 4,10; beq 4f; cmpwi 4,11; beq 5f; b 11f; 2:; lwz 3,0x4(3); blr; 3:; lwz 3,0x8(3); blr; 4:; lwz 3,0x0(3); blr; 5:; lwz 3,0xc(3); blr; 6:; lwz 9,0xc(3); 7:; li 3,0; cmpwi 9,0; beqlr; lwz 3,0x4(9); blr; 8:; lwz 9,0x4(3); b 7b; 9:; lwz 9,0x8(3); b 7b; 10:; lwz 9,0x0(3); b 7b; 11:; li 3,0"
extern "C" int f_800F2BA4() {}
