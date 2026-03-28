/* operator>>(EStream &, EIStaticModel *&) - 0x8022B920 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIStaticModel;

EStream &operator_shr_EStream_EIStaticModel(EStream &s, EIStaticModel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIStaticModel *)tmp;
    return s;
}
