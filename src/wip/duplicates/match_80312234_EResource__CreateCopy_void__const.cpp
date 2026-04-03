class EResource;
extern EResource *CreateResourceCopy(EResource *);
class EResource { public: EResource *CreateCopy() const; };
EResource *EResource::CreateCopy() const { return CreateResourceCopy((EResource *)this); }
