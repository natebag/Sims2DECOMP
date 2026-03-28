struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERModel_tid = { 1, 2, 3, 4 };
class ERModel { public: unsigned short GetTypeVersion() const; };
unsigned short ERModel::GetTypeVersion() const { return s_ERModel_tid.version; }
