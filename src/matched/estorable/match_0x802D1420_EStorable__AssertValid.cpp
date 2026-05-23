struct ETypeInfo;

struct EStorable {
    int IsDerivedFrom(ETypeInfo* type) const;
    void AssertValid(ETypeInfo* type) const;
};

void EStorable::AssertValid(ETypeInfo* type) const
{
    IsDerivedFrom(type);
}
