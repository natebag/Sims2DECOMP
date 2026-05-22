// 0x8034A6B0 TArray<ENDummyPoint, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 0,-25988(13); blr; lwz 0,-25984(13); cmpwi 0,0; beqlr; li 0,0; stw 0,-25984(13); blr; lwz 0,-25980(13); cmpwi 0,0; beqlr; li 0,0; stw 0,-25980(13); blr; lwz 0,-25976(13); cmpwi 0,0; beqlr; li 0,0; stw 0,-25976(13); blr; lwz 0,-25972(13); cmpwi 0,0; beqlr; li 0,0; stw 0,-25972(13); blr; lwz 0,-25968(13); cmpwi 0,0; beqlr; li 0,0; stw 0,-25968(13); blr; lwz 0,-25964(13); cmpwi 0,0; beq 0f; li 0,0; stw 0,-25964(13); 0:; lwz 9,0x4dc(3); addi 9,9,24; stw 9,0x4dc(3); blr; lwz 0,-25960(13); cmpwi 0,0; beq 1f; li 0,0; stw 0,-25960(13); 1:; lwz 9,0x4dc(3); addi 9,9,24; stw 9,0x4dc(3); blr"
extern "C" void f_8034A6B0() {}
