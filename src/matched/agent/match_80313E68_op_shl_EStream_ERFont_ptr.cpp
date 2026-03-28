class EStream;
class EStorable;
class ERFont;

EStream& operator_shl_base(EStream&, EStorable*);

EStream& operator_shl_ERFont(EStream& s, ERFont* p) {
    return operator_shl_base(s, (EStorable*)p);
}
