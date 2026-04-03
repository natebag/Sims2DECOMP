/* operator>>(EFile &, IShrubObject *&) - 0x800525A4 (64 bytes) */

struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct IShrubObject;

EFile &operator_shr_EFile_IShrubObject(EFile &s, IShrubObject *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (IShrubObject *)tmp;
    return s;
}
