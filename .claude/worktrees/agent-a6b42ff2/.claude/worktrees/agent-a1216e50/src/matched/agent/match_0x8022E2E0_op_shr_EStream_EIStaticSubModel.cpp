/* operator>>(EStream &, EIStaticSubModel *&) - 0x8022E2E0 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIStaticSubModel;

EStream &operator_shr_EStream_EIStaticSubModel(EStream &s, EIStaticSubModel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIStaticSubModel *)tmp;
    return s;
}
