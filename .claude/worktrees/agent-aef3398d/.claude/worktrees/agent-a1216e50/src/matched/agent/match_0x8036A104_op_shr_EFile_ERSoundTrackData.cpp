/* operator>>(EFile &, ERSoundTrackData *&) - 0x8036A104 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERSoundTrackData;

EFile &operator_shr_EFile_ERSoundTrackData(EFile &s, ERSoundTrackData *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERSoundTrackData *)tmp;
    return s;
}
