struct TypeInfo { int data[4]; };
TypeInfo s_REffectsAttachment_typeInfo = { {1, 2, 3, 4} };
class REffectsAttachment { public: TypeInfo *GetTypeInfo() const; };
TypeInfo *REffectsAttachment::GetTypeInfo() const { return &s_REffectsAttachment_typeInfo; }
