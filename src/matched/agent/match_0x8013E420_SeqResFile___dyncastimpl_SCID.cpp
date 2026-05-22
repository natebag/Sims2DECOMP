// 0x8013E420 SeqResFile::_dyncastimpl(SCID) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,14; beqlr; cmpwi 4,15; beqlr; cmpwi 4,16; li 0,0; bne 0f; mr 0,3; 0:; mr 3,0"
extern "C" int f_8013E420() {}
