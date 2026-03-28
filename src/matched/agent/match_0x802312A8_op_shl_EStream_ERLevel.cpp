struct EStream;
struct EStorable;
struct ERLevel;

EStream &operator_shl_EStream_EStorable(EStream &, EStorable *);

EStream &operator_shl_EStream_ERLevel(EStream &s, ERLevel *p) {
    return operator_shl_EStream_EStorable(s, (EStorable *)p);
}
