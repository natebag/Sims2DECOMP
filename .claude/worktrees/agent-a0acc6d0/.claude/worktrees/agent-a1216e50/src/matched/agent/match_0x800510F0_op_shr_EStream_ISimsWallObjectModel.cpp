/* operator>>(EStream &, ISimsWallObjectModel *&) - 0x800510F0 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ISimsWallObjectModel;

EStream &operator_shr_EStream_ISimsWallObjectModel(EStream &s, ISimsWallObjectModel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ISimsWallObjectModel *)tmp;
    return s;
}
