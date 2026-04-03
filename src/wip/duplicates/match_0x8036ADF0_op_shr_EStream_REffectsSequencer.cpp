/* operator>>(EStream &, REffectsSequencer *&) - 0x8036ADF0 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct REffectsSequencer;

EStream &operator_shr_EStream_REffectsSequencer(EStream &s, REffectsSequencer *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (REffectsSequencer *)tmp;
    return s;
}
