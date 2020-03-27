#include "spinlock.hpp"

namespace spinlock {

    void SpinLock::lock() noexcept {
        while (flag.test_and_set(std::memory_order_acquire));
    }

    void SpinLock::unlock() noexcept {
        flag.clear(std::memory_order_release);
    }

    bool SpinLock::try_lock() noexcept {
        return !flag.test_and_set(std::memory_order_acquire);
    }

}