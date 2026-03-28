struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EIGameInstance;

EStream &operator_shr_EStream_EIGameInstance(EStream &s, EIGameInstance *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EIGameInstance *)tmp;
    return s;
}
