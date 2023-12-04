//
// Created by user on 02.12.2023.
//

#include <algorithm>

template<typename state_t>
struct ListPair final
{
    state_t const state;
    ListPair<state_t> *next_state;
};

template<typename state_t>
ListPair<state_t> *copy(ListPair<state_t> const *src)
{
    if (src == nullptr)
    {
        return nullptr;
    }

    ListPair<state_t> *head = nullptr;
    ListPair<state_t> *tail = nullptr;

    try
    {
        head = new ListPair<state_t>{src->state, nullptr};
        tail = head;

        ListPair<state_t> const *current = src->next_state;
        while (current != nullptr)
        {
            tail->next_state = new ListPair<state_t>{current->state, nullptr};
            tail = tail->next_state;
            current = current->next_state;
        }
    } catch (...)
    {
        deleteList(head);
        throw;
    }

    return head;
}

template<typename state_t>
void deleteList(ListPair<state_t> *head)
{
    while (head != nullptr)
    {
        ListPair<state_t> *next = head->next_state;
        delete head;
        head = next;
    }
}

template<typename state_t>
ListPair<state_t> *copy(ListPair<state_t> const *src)
{
    if (!src) return nullptr;

    ListPair<state_t> *head = nullptr;

    try
    {
        while (src)
        {
            auto *node = new ListPair<state_t>{src->state, nullptr};
            if (head == nullptr)
                head = node;

            else
            {
                head->next_state = node;
                head = node;
            }

            src = src->next_state;
        }
    }

    catch (...)
    {
        while (head)
        {
            ListPair<state_t> *node = head;
            head = head->next_state;
            delete node;
        }

        throw;
    }

    return head;
}

template<typename state_t>
ListPair<state_t> *copy(ListPair<state_t> const *src)
{
    if (!src) return nullptr;

    ListPair<state_t> *head = nullptr;
    ListPair<state_t> *tail = nullptr;

    try
    {
        while (src)
        {
            auto *node = new ListPair<state_t>{src->state, nullptr};
            if (head == nullptr)
                head = tail = node;

            else
            {
                tail->next_state = node;
                tail = node;
            }

            src = src->next_state;
        }
    }

    catch (...)
    {
        while (head)
        {
            ListPair<state_t> *node = head;
            head = head->next_state;
            delete node;
        }
        throw;
    }

    return head;
}