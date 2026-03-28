struct TypeInfo { int data[4]; };
TypeInfo s_EREdithTreeSet_typeInfo = { {1, 2, 3, 4} };
class EREdithTreeSet { public: TypeInfo *GetTypeInfo() const; };
TypeInfo *EREdithTreeSet::GetTypeInfo() const { return &s_EREdithTreeSet_typeInfo; }
