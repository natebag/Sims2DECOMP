/* operator>>(EStream &, ERSoundEvent *&) - 0x8036993C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERSoundEvent;

EStream &operator_shr_EStream_ERSoundEvent(EStream &s, ERSoundEvent *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERSoundEvent *)tmp;
    return s;
}
