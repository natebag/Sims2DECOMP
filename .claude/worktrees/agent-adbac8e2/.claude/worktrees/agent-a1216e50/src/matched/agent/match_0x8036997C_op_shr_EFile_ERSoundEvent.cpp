/* operator>>(EFile &, ERSoundEvent *&) - 0x8036997C (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERSoundEvent;

EFile &operator_shr_EFile_ERSoundEvent(EFile &s, ERSoundEvent *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERSoundEvent *)tmp;
    return s;
}
