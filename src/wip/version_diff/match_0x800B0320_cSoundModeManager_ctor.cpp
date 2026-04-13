// MATCH: 0x800B0320 cSoundModeManager::cSoundModeManager (68 bytes)
// Raw: 7C 69 1B 78 38 00 00 00 39 60 00 01 90 09 00 30 91 69 00 2C 90 09 00 00 90 09 00 04 90 09 00 08 90 09 00 0C 90 09 00 10 90 09 00 14 90 09 00 18 90 09 00 1C 90 09 00 20 90 09 00 24 90 09 00 28 4E 80 00 20
// FLAGS: -fno-schedule-insns

struct cSoundModeManager {
    int fields[13];  // 0x00 to 0x30
};

extern "C" void cSoundModeManager_ctor(cSoundModeManager* this_) {
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
    this_->fields[11] = 1;  // field at 0x2C
    this_->fields[12] = 0;  // field at 0x30
}
