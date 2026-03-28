/* operator>>(EStream &, ERModel *&) - 0x80317D6C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERModel;

EStream &operator_shr_EStream_ERModel(EStream &s, ERModel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERModel *)tmp;
    return s;
}
