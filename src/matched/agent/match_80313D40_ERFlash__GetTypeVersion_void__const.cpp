struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_ERFlash_tid = { 1, 2, 3, 4 };
class ERFlash { public: unsigned short GetTypeVersion() const; };
unsigned short ERFlash::GetTypeVersion() const { return s_ERFlash_tid.version; }
