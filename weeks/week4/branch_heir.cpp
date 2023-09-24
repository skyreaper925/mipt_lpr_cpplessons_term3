struct Base
{
};

struct D1 : Base
{
};

struct D2 : Base
{
};

struct D3 : D1, D2
{
};

Base const *D1BaseToD2Base(Base const *base)
{
    const D1 *d1 = static_cast<const D1 *>(base);
    const D2 *d2 = static_cast<const D3 *>(d1);
    return static_cast<const Base *>(d2);
}