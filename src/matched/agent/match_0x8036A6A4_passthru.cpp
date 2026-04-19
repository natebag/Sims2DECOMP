/* ERSoundTrackData::CreateCopy(void) at 0x8036A6A4 (32B) */
// 0x8036A6A4 (32 bytes)
class EStorable {
public:
    EStorable* CreateCopy() const;
};
class ERSoundTrackData : public EStorable {
public:
    ERSoundTrackData* CreateCopy() const;
};
ERSoundTrackData* ERSoundTrackData::CreateCopy() const {
    return (ERSoundTrackData*)EStorable::CreateCopy();
}
