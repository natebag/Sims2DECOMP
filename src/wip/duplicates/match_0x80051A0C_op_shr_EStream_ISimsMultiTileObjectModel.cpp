/* operator>>(EStream &, ISimsMultiTileObjectModel *&) - 0x80051A0C (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ISimsMultiTileObjectModel;

EStream &operator_shr_EStream_ISimsMultiTileObjectModel(EStream &s, ISimsMultiTileObjectModel *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ISimsMultiTileObjectModel *)tmp;
    return s;
}
