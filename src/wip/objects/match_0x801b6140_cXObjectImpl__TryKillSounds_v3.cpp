// 0x801b6140 (68 bytes)
// cXObjectImpl::TryKillSounds

extern void cSoundPlayer_QuietBySourceID(int id);

struct cXObjectImpl {
    char pad[100];
    short soundID;

    void TryKillSounds(void* elem, void* param) {
        short* param_ptr = (short*)param;
        int sourceID;
        if (param_ptr[0] == 0) {
            sourceID = this->soundID;
        } else {
            sourceID = param_ptr[2];
        }
        cSoundPlayer_QuietBySourceID(sourceID);
    }
};
