struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_REffectsAttachment_tid = { 1, 2, 3, 4 };
class REffectsAttachment { public: int GetTypeName() const; };
int REffectsAttachment::GetTypeName() const { return s_REffectsAttachment_tid.name; }
