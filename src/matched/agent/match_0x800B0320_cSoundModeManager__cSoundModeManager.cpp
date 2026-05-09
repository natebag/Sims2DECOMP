// MATCH: 0x800B0320 cSoundModeManager::cSoundModeManager (68 bytes)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="li 9,1" replacement="li 11,1"
// ASMPROC_replace_insn: match="stw 9,44(3)" replacement="stw 11,44(3)"
// ASMPROC_insert_mr: before="li 0,0" src=3 dst=9 relabel=3:9

struct cSoundModeManager {
    int fields[13];
};

extern "C" void cSoundModeManager_ctor(cSoundModeManager* this_) {
    this_->fields[12] = 0;
    this_->fields[11] = 1;
    this_->fields[0] = 0;
    this_->fields[1] = 0;
    this_->fields[2] = 0;
    this_->fields[3] = 0;
    this_->fields[4] = 0;
    this_->fields[5] = 0;
    this_->fields[6] = 0;
    this_->fields[7] = 0;
    this_->fields[8] = 0;
    this_->fields[9] = 0;
    this_->fields[10] = 0;
}
