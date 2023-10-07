#include <cassert>

struct IntAbstractQueue
{
    virtual void push(int x) = 0;

    virtual int pop() = 0;

    virtual int peek() const = 0;

    virtual bool is_empty() const = 0;

    virtual bool is_full() const = 0;

    virtual ~IntAbstractQueue() = default;
};

struct IntStack final : IntAbstractQueue
{
    void push(int x) override
    {
        data[top++] = x;
    }

    int pop() override
    {
        return data[--top];
    }

    int peek() const override
    {
        return data[top - 1];
    }

    bool is_empty() const override
    {
        return 0 == top;
    }

    bool is_full() const override
    {
        return 10 == top;
    }

private:
    unsigned top = 0;
    int data[10];
};

struct IntStackWithMax : IntAbstractQueue
{
private:
    IntStack data;

public:
    int get_max() const
    {
        auto data2 = data;
        auto maxi = data.peek();
        while (not(data2.is_empty()))
        {
            if (data2.peek() > maxi)
                maxi = data2.peek();

            data2.pop();
        }

        return maxi;
    }

    void push(int x) override
    {
        data.push(x);
    }

    int pop() override
    {
        return data.pop();
    }

    int peek() const override
    {
        return data.peek();
    }

    bool is_empty() const override
    {
        return data.is_empty();
    }

    bool is_full() const override
    {
        return data.is_full();
    }

};

void with_queue_do(IntAbstractQueue &q)
{
    assert(q.is_empty());
    q.push(1);
    assert(!q.is_empty());
    assert(1 == q.peek());
    assert(!q.is_empty());
    assert(1 == q.pop());
    assert(q.is_empty());
    for (int cnt = 0; cnt != 10; ++cnt)
        q.push(cnt);
    assert(q.is_full());
}

void with_stackwithmax_do(IntStackWithMax &swm)
{
    with_queue_do(swm);
    for (int cnt = 10; cnt != 0; --cnt)
        assert(cnt - 1 == swm.get_max() and cnt - 1 == swm.pop());
    assert(swm.is_empty());
}

int main()
{
    IntStackWithMax swm;
    with_stackwithmax_do(swm);
    return 0;
}