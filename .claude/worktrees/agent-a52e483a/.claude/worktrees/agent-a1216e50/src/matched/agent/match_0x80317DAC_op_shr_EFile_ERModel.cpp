/* operator>>(EFile &, ERModel *&) - 0x80317DAC (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERModel;

EFile &operator_shr_EFile_ERModel(EFile &s, ERModel *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERModel *)tmp;
    return s;
}
