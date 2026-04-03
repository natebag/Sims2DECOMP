/* operator>>(EStream &, ISimsObjectModel *&) - 0x8004C480 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ISimsObjectModel;

EStream &operator_shr_EStream_ISimsObjectModel(EStream &s, ISimsObjectModel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ISimsObjectModel *)tmp;
    return s;
}
