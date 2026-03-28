struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERModel_tid = { 1, 2, 3, 4 };
class ERModel { public: int GetTypeName() const; };
int ERModel::GetTypeName() const { return s_ERModel_tid.name; }
