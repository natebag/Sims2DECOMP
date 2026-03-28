/* operator>>(EStream &, REffectsEmitter *&) - 0x8036A734 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct REffectsEmitter;

EStream &operator_shr_EStream_REffectsEmitter(EStream &s, REffectsEmitter *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (REffectsEmitter *)tmp;
    return s;
}
