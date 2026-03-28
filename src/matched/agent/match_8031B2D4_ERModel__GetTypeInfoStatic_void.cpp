struct TypeInfo { int data[4]; };
TypeInfo s_ERModel_typeInfo = { {1, 2, 3, 4} };
class ERModel { public: static TypeInfo *GetTypeInfoStatic(); };
TypeInfo *ERModel::GetTypeInfoStatic() { return &s_ERModel_typeInfo; }
