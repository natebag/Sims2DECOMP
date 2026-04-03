/* operator>>(EStream &, ERBinary *&) - 0x803681F8 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERBinary;

EStream &operator_shr_EStream_ERBinary(EStream &s, ERBinary *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERBinary *)tmp;
    return s;
}
