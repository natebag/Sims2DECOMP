/* operator>>(EStream &, REffectsAttachment *&) - 0x80322380 (64 bytes) */

struct EStorable;

struct EStream {
    char pad[4];
};

EStream &operator_shr_EStream_EStorable(EStream &, EStorable *&);

struct REffectsAttachment;

EStream &operator_shr_EStream_REffectsAttachment(EStream &s, REffectsAttachment *&p)
{
    EStorable *tmp;
    operator_shr_EStream_EStorable(s, tmp);
    p = (REffectsAttachment *)tmp;
    return s;
}
