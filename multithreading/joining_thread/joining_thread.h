#pragma once

#include <thread>

class joining_thread
{
    std::thread thread;

public:
    joining_thread() noexcept = default;
    template <typename Callable, typename... Args>
    explicit joining_thread(Callable &&func, Args &&... args) : thread(std::forward<Callable>(func), std::forward<Args>(args)...) {}
    explicit joining_thread(std::thread other) : thread{std::move(other)} {}
    joining_thread(joining_thread &&other) : thread{std::move(other.thread)} {}
    joining_thread &operator=(joining_thread &&other)
    {
        if (joinable())
            join();
        thread = std::move(other.thread);
        return *this;
    }
    joining_thread &operator=(std::thread other)
    {
        if (joinable())
            join();
        thread = std::move(other);
        return *this;
    }
    bool joinable() const noexcept
    {
        return thread.joinable();
    }
    void join()
    {
        return thread.join();
    }
    void detach()
    {
        return thread.detach();
    }
    void swap(joining_thread &other) noexcept
    {
        thread.swap(other.thread);
    }
    std::thread::id get_id() const noexcept
    {
        return thread.get_id();
    }
    std::thread &as_thread() noexcept
    {
        return thread;
    }
    const std::thread &as_thread() const noexcept
    {
        return thread;
    }
    ~joining_thread()
    {
        if (joinable())
            join();
    }
};