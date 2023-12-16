template<typename T>
class Uptr
{

private:
    T *ptr;

public:

    Uptr() : ptr(nullptr) {}

    explicit Uptr(T *p) : ptr(p) {}

    Uptr(const Uptr &) = delete;

    Uptr(Uptr &&other) noexcept: ptr(other.ptr) { other.ptr = nullptr; }

    ~Uptr() { delete ptr; }

//    ~Uptr() { delete[] ptr; }

    T *release()
    {
        auto temp = ptr;
        ptr = nullptr;
        return temp;
    }

    explicit operator bool() { return ptr != nullptr; }

    T &operator*() { return *ptr; }

    T *operator->() { return ptr; }

    void swap(Uptr &other)
    {
        if (this != other)
        {
            auto tmp = this;
            this = other;
            other = tmp;
        }
    }

    void reset(T *newptr = nullptr)
    {
        if (ptr != newptr)
        {
            delete ptr;
            ptr = newptr;
        }
    }

};

int main()
{

    return 0;
}