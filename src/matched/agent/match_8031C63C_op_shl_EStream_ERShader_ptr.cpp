class EStream;
class EStorable;
class ERShader;

EStream& operator_shl_base(EStream&, EStorable*);

EStream& operator_shl_ERShader(EStream& s, ERShader* p) {
    return operator_shl_base(s, (EStorable*)p);
}
