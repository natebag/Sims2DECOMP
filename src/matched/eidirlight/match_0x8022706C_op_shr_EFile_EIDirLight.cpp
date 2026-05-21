// 0x8022706C operator>>(EFile &, EIDirLight *&) (64B)
struct EStorable;
struct EFile { char pad[4]; };
EFile& operator_shr_EFile_EStorable(EFile&, EStorable*&);
struct EIDirLight;
EFile& operator_shr_EFile_EIDirLight(EFile& s, EIDirLight*& p) {
    EStorable* tmp;
    operator_shr_EFile_EStorable(s, tmp);
    p = (EIDirLight*)tmp;
    return s;
}
