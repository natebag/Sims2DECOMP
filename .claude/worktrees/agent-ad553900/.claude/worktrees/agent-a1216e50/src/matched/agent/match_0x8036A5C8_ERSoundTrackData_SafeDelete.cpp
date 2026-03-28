/* ERSoundTrackData::SafeDelete(void) - 0x8036A5C8 (64 bytes) */

struct ERSoundTrackData {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual ~ERSoundTrackData();
    static void SafeDelete(ERSoundTrackData *p);
};

void ERSoundTrackData::SafeDelete(ERSoundTrackData *p)
{
    if (p) {
        delete p;
    }
}
