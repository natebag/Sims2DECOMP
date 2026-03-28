/* operator>>(EFile &, EIStaticSubModel *&) - 0x8022E320 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIStaticSubModel;

EFile &operator_shr_EFile_EIStaticSubModel(EFile &s, EIStaticSubModel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIStaticSubModel *)tmp;
    return s;
}
