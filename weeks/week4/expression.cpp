#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;

    virtual ~Expression() = default;
};

struct Number : Expression
{
    explicit Number(double value) : value(value) {}

    double evaluate() const override
    {
        return value;
    }

    ~Number() override = default;

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const *left, char op, Expression const *right) : left(left), right(right), op(op) {}

    double evaluate() const override
    {
        double lha = left->evaluate();
        double rha = right->evaluate();
        switch (op)
        {
            case '+':
                return lha + rha;
            case '-':
                return lha - rha;
            case '*':
                return lha * rha;
            case '/':
                return lha / rha;
        }

        return 0;
    }

    ~BinaryOperation() override
    {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};