// 0x80201338 RELTarget::GetRecord(int) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 0,4; lwz 3,0x84(3); mtspr 9,0; blelr; 0:; cmpwi 3,0; beq 1f; lwz 3,0x4(3); 1:; bdnz 0b"
extern "C" int f_80201338() {}
