struct EStorable;

struct EFile {
    char pad[4];
};

EFile &operator_shr_EFile_EStorable(EFile &, EStorable *&);

struct EIGameInstance;

EFile &operator_shr_EFile_EIGameInstance(EFile &s, EIGameInstance *&p)
{
    EStorable *tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIGameInstance *)tmp;
    return s;
}
