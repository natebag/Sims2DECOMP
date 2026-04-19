/* operator<<(EStream&, ERSoundTrackData*) at 0x8036A0A4 (32B) */
// 0x8036A0A4 (32 bytes)
class EStream;
class EStorable {};
class ERSoundTrackData : public EStorable {};
extern EStream& operator<<(EStream& s, EStorable* obj);
EStream& operator<<(EStream& s, ERSoundTrackData* obj) {
    return operator<<(s, (EStorable*)obj);
}
