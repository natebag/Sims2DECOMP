// 0x803C357C EAnimController::GetNonMainTrackFlagFromIndex(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,9; beq 4f; bgt 0f; cmpwi 4,7; beq 2f; bgt 3f; cmpwi 4,6; beq 1f; b 9f; 0:; cmpwi 4,11; beq 6f; blt 5f; cmpwi 4,12; beq 7f; cmpwi 4,13; beq 8f; b 9f; 1:; li 3,256; blr; 2:; li 3,512; blr; 3:; li 3,1024; blr; 4:; li 3,2048; blr; 5:; li 3,4096; blr; 6:; li 3,8192; blr; 7:; li 3,16384; blr; 8:; li 3,0; ori 3,3,32768; blr; 9:; li 3,0"
extern "C" int f_803C357C() {}
