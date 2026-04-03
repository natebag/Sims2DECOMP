// 0x801b6140 (68 bytes)
// cXObjectImpl::TryKillSounds(StackElem*, KillSoundsParam*)

class cSoundPlayer {
public:
    static void QuietBySourceID(int);
};

struct KillSoundsParam {
    short check;
    short pad;
    short sourceID;
};

class cXObjectImpl {
public:
    short soundID;  // offset 100

    void TryKillSounds(void* elem, KillSoundsParam* param) {
        int sourceID;
        if (param->check == 0) {
            sourceID = this->soundID;  // offset 100
        } else {
            sourceID = param->sourceID;  // offset 4
        }
        cSoundPlayer::QuietBySourceID(sourceID);
    }
};
