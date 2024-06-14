#include "thread_test.h"

thread_test::thread_test() {}

void thread_test::msg_handle(const message_base *p_msg)
{
    if(dynamic_cast<const wrapped_message<Type_UserDefined_msg>*>(p_msg))
    {
        auto p = static_cast<const wrapped_message<Type_UserDefined_msg>*>(p_msg);
    }
}

void thread_test::timer_handle()
{

}

Type_TaskRet thread_test::inter_thread_task(Type_UserDefined_parm parm1, int parm2)
{
    return 0;
}

int main(int argc, char *argv[])
{
    crt_frame::load<thread_test>();
    crt_frame::regist_timer<thread_test>(20);
    Type_UserDefined_msg msg = "test_msg";
    crt_frame::push_msg<thread_test>(std::move(msg));

    Type_UserDefined_parm parm = std::make_shared<int>(1);
    std::future<Type_TaskRet> fut = crt_frame::spawn_memfn_task_for<thread_test>(&thread_test::inter_thread_task, parm, 2);

    /*to wait till the task is completed*/
    fut.get();

    /*to wait for designated time*/
    if(fut.wait_for(std::chrono::milliseconds(2)) == std::future_status::ready)
    {
        Type_TaskRet result = fut.get();
    }
}
