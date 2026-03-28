/* operator>>(EStream &, ERFont *&) - 0x80313E88 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERFont;

EStream &operator_shr_EStream_ERFont(EStream &s, ERFont *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERFont *)tmp;
    return s;
}
