#include <iostream>

using namespace std;

class PseudoArray
{
protected:
    size_t size_;

public:
    explicit PseudoArray(size_t size) : size_(size) {}

    virtual void clear() = 0;

    bool is_empty() const { return size_; }

    virtual ~PseudoArray() = default;
};

class FloatArray : public PseudoArray
{
protected:
    float *storage_ = nullptr;

public:

    FloatArray(size_t size, float value) : PseudoArray(size), storage_(new float[size_])
    {
        for (size_t i = 0; i < size_; ++i)
        {
            storage_[i] = value;
        }
    }

    void clear() override
    {
        for (size_t i = 0; i < size_; ++i)
        {
            storage_[i] = 0;
        }
    }

    float operator[](size_t idx)
    {
        return storage_[idx];
    }

    ~FloatArray() override
    {
        delete[] storage_;
    }
};

class DoubleArray : public PseudoArray
{
protected:
    double *storage_ = nullptr;

public:

    DoubleArray(size_t size, double value) : PseudoArray(size), storage_(new double[size_])
    {
        for (size_t i = 0; i < size_; ++i)
        {
            storage_[i] = value;
        }
    }

    void clear() override
    {
        for (size_t i = 0; i < size_; ++i)
        {
            storage_[i] = 0;
        }
    }

    double operator[](size_t idx)
    {
        return storage_[idx];
    }

    ~DoubleArray() override
    {
        delete[] storage_;
    }
};