// match_0x801b6140_cXObjectImpl__TryKillSounds.cpp
// Release build version of TryKillSounds (68 bytes)
// Ported from DVD-build match @ 0x80109BEC

struct KillSoundsParam { short flag; };
struct StackElem { char pad[4]; short sourceID; };

class cSoundPlayer {
public:
    void QuietBySourceID(int);
};

extern cSoundPlayer *g_soundPlayer;

struct cXObjectImpl_KS {
    char pad[0x64];
    short m_sourceID;

    long long TryKillSounds(StackElem *elem, KillSoundsParam *param) {
        short sourceID;
        if (param->flag != 0) {
            sourceID = elem->sourceID;
        } else {
            sourceID = m_sourceID;
        }
        g_soundPlayer->QuietBySourceID(sourceID);
        return 1;
    }
};
