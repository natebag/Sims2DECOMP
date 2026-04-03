class EStream;
class EStorable;
class REffectsAttachment;

EStream& operator_shl_base(EStream&, EStorable*);

EStream& operator_shl_REffectsAttachment(EStream& s, REffectsAttachment* p) {
    return operator_shl_base(s, (EStorable*)p);
}
