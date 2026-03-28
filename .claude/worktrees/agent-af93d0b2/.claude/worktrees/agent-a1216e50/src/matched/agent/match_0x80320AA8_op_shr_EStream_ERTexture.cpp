/* operator>>(EStream &, ERTexture *&) - 0x80320AA8 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERTexture;

EStream &operator_shr_EStream_ERTexture(EStream &s, ERTexture *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERTexture *)tmp;
    return s;
}
