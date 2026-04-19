/* ERSoundTrackData::Construct(ERSoundTrackData*) at 0x8036A584 (32B) */
// 0x8036A584 (32 bytes)
class ERSoundTrackData {
public:
    ERSoundTrackData();
    void Construct(ERSoundTrackData* other);
};
static inline void* operator new(unsigned sz, void* p) { return p; }
void ERSoundTrackData::Construct(ERSoundTrackData*) {
    new(this) ERSoundTrackData;
}
