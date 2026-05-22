// 0x8020BDBC InteractorModule::InteractorManager::IsValidPlayerId(int) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); cmpwi 0,0; bne 1f; 0:; li 3,0; blr; 1:; cmpwi 4,0; blt 0b; lwz 0,0x4(3); cmpw 4,0; bge 0b; cmpwi 4,7; bgt 0b; li 3,1"
extern "C" int f_8020BDBC() {}
