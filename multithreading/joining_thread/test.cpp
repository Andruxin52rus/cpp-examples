#include <iostream>
#include <sstream>
#include <vector>

#include "joining_thread.h"

void dumb(unsigned count)
{
    std::ostringstream start_line{}, end_line{};
    start_line << std::string("thread ") << std::this_thread::get_id() << " started\n";
    end_line << std::string("thread ") << std::this_thread::get_id() << " ended\n";

    std::cout << start_line.str();
    for (unsigned i = 0; i < count; ++i)
        (void)i;
    std::cout << end_line.str();
}

int main()
{
    const unsigned THREADS_COUNT = 10;
    std::vector<joining_thread> threads(THREADS_COUNT);
    for (unsigned i = 0; i < THREADS_COUNT; ++i)
    {
        threads.push_back(joining_thread(dumb, i * 1e6));
    }
    threads[THREADS_COUNT - 1] = joining_thread(dumb, 1e8);
}
