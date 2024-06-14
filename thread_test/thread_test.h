#ifndef THREAD_TEST_H
#define THREAD_TEST_H
#include "crt_frame.h"
#include <memory>
typedef int Type_TaskRet;
typedef std::shared_ptr<int> Type_UserDefined_parm;
typedef std::string Type_UserDefined_msg;
class thread_test : public crt_thread<Type_TaskRet>
{
public:
    thread_test();
    virtual void msg_handle(const message_base *p_msg) override;
    virtual void timer_handle() override;

    Type_TaskRet inter_thread_task(Type_UserDefined_parm parm1, int parm2);

};

#endif // THREAD_TEST_H
