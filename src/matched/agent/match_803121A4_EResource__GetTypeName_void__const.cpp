struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_EResource_tid = { 1, 2, 3, 4 };
class EResource { public: int GetTypeName() const; };
int EResource::GetTypeName() const { return s_EResource_tid.name; }
