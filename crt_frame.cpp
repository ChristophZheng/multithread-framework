#include "crt_frame.h"
std::mutex crt_frame::thd_pl_weak_lk;
thread_unit crt_frame::thread_pool[];
std::once_flag crt_frame::thread_sentinel_intialized;
crt_periodic_cal* crt_frame::thread_sentinel = nullptr;
