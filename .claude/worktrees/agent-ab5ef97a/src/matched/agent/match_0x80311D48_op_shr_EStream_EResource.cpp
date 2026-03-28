/* operator>>(EStream &, EResource *&) - 0x80311D48 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EResource;

EStream &operator_shr_EStream_EResource(EStream &s, EResource *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EResource *)tmp;
    return s;
}
