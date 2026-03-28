/* operator>>(EFile &, ERDataset *&) - 0x80368E00 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct ERDataset;

EFile &operator_shr_EFile_ERDataset(EFile &s, ERDataset *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (ERDataset *)tmp;
    return s;
}
