struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct EILight;

EStream &operator_shr_EStream_EILight(EStream &s, EILight *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (EILight *)tmp;
    return s;
}
