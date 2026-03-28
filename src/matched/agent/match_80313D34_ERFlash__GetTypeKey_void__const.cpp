struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERFlash_tid = { 1, 2, 3, 4 };
class ERFlash { public: int GetTypeKey() const; };
int ERFlash::GetTypeKey() const { return s_ERFlash_tid.key; }
