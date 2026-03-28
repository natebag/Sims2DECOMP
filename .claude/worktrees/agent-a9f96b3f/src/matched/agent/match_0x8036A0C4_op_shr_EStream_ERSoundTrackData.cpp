/* operator>>(EStream &, ERSoundTrackData *&) - 0x8036A0C4 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERSoundTrackData;

EStream &operator_shr_EStream_ERSoundTrackData(EStream &s, ERSoundTrackData *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERSoundTrackData *)tmp;
    return s;
}
