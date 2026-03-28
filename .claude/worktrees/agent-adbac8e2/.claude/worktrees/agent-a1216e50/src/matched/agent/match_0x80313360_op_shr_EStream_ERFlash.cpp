/* operator>>(EStream &, ERFlash *&) - 0x80313360 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERFlash;

EStream &operator_shr_EStream_ERFlash(EStream &s, ERFlash *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERFlash *)tmp;
    return s;
}
