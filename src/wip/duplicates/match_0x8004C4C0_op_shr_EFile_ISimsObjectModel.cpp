/* operator>>(EFile &, ISimsObjectModel *&) - 0x8004C4C0 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ISimsObjectModel;

EFile &operator_shr_EFile_ISimsObjectModel(EFile &s, ISimsObjectModel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ISimsObjectModel *)tmp;
    return s;
}
