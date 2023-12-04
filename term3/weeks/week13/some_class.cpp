class SomeClass final
{
public:
    SomeClass(unsigned res_a_id, unsigned res_b_id) : res_a(nullptr), res_b(nullptr)
    {
        try
        {
            res_a = get_resource(res_a_id);
            res_b = get_resource(res_b_id);
        } catch (...)
        {
            if (res_a)
                free_resource(res_a);
            throw;
        }
    }

    unsigned call_a() const;

    unsigned call_b() const;

    ~SomeClass() noexcept
    {
        if (res_a)
        {
            free_resource(res_a);
        }
        if (res_b)
        {
            free_resource(res_b);
        }
    }

    SomeClass(SomeClass const &src) = delete;

    SomeClass &operator=(SomeClass const &src) = delete;

    SomeClass(SomeClass &&src) = delete;

    SomeClass &operator=(SomeClass const &&src) = delete;

private:
    void *res_a;
    void *res_b;
};