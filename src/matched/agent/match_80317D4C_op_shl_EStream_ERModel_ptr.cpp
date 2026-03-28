class EStream;
class EStorable;
class ERModel;

EStream& operator_shl_base(EStream&, EStorable*);

EStream& operator_shl_ERModel(EStream& s, ERModel* p) {
    return operator_shl_base(s, (EStorable*)p);
}
