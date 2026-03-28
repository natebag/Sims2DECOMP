struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERModel_tid = { 1, 2, 3, 4 };
class ERModel { public: int GetTypeKey() const; };
int ERModel::GetTypeKey() const { return s_ERModel_tid.key; }
