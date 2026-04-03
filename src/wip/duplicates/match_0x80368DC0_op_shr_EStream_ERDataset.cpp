/* operator>>(EStream &, ERDataset *&) - 0x80368DC0 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct ERDataset;

EStream &operator_shr_EStream_ERDataset(EStream &s, ERDataset *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (ERDataset *)tmp;
    return s;
}
