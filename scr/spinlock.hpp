//
// Created by Татьяна on 2020-03-26.
//

#ifndef SPINLOCK_SPINLOCK_HPP
#define SPINLOCK_SPINLOCK_HPP
#include <atomic>

namespace spinlock {

    class SpinLock {

        std::atomic_flag flag{ ATOMIC_FLAG_INIT };

    public:
        constexpr SpinLock() noexcept = default;
        ~SpinLock() noexcept = default;

        SpinLock(const SpinLock&) = delete;
        SpinLock& operator=(const SpinLock&) = delete;
        SpinLock(SpinLock&&) = delete;
        SpinLock& operator=(SpinLock&&) = delete;

        void lock() noexcept;
        void unlock() noexcept;
        bool try_lock() noexcept;
    };

}

#endif //SPINLOCK_SPINLOCK_HPP
