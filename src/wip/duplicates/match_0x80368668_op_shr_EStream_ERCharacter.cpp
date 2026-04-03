/* operator>>(EStream &, ERCharacter *&) - 0x80368668 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERCharacter;

EStream &operator_shr_EStream_ERCharacter(EStream &s, ERCharacter *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERCharacter *)tmp;
    return s;
}
