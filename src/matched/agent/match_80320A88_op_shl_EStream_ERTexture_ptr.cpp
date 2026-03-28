class EStream;
class EStorable;
class ERTexture;

EStream& operator_shl_base(EStream&, EStorable*);

EStream& operator_shl_ERTexture(EStream& s, ERTexture* p) {
    return operator_shl_base(s, (EStorable*)p);
}
