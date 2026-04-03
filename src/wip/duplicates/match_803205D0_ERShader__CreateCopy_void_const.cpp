class EStorable {
public:
    EStorable* CreateCopy() const;
};

class ERShader : public EStorable {
public:
    ERShader* CreateCopy() const;
};

ERShader* ERShader::CreateCopy() const {
    return (ERShader*)EStorable::CreateCopy();
}
