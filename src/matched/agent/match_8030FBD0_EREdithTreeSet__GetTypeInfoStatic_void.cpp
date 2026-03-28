struct TypeInfo { int data[4]; };
TypeInfo s_EREdithTreeSet_typeInfo = { {1, 2, 3, 4} };
class EREdithTreeSet { public: static TypeInfo *GetTypeInfoStatic(); };
TypeInfo *EREdithTreeSet::GetTypeInfoStatic() { return &s_EREdithTreeSet_typeInfo; }
