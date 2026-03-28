/* operator>>(EFile &, EIStaticModel *&) - 0x8022B960 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIStaticModel;

EFile &operator_shr_EFile_EIStaticModel(EFile &s, EIStaticModel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIStaticModel *)tmp;
    return s;
}
