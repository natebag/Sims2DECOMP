// 0x801b6140 (68 bytes)
// cXObjectImpl::TryKillSounds

void cSoundPlayer_QuietBySourceID(int id);

void cXObjectImpl_TryKillSounds(void* this_ptr, void* elem, void* param) {
    short* param_short = (short*)param;
    short* this_short = (short*)((char*)this_ptr + 100);

    int soundID;
    if (param_short[0] == 0) {
        soundID = this_short[0];  // this[100]
    } else {
        soundID = param_short[2];  // param[4]
    }

    cSoundPlayer_QuietBySourceID(soundID);
}
