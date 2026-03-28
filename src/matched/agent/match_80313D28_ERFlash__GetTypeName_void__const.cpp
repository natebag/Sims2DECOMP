struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERFlash_tid = { 1, 2, 3, 4 };
class ERFlash { public: int GetTypeName() const; };
int ERFlash::GetTypeName() const { return s_ERFlash_tid.name; }
