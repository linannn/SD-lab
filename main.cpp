#include <iostream>
#include "include/Cdr.h"
#include "include/my_stack.h"

using namespace std;
using namespace eprosima::fastcdr;

void my_serialize(Cdr &cdr, My_stack &sta);
void my_deserialize(Cdr &cdr, My_stack &sta);
int main()
{
    /// Raw buffer where data will be serialized.
    char buffer[505];
    /// Object that manage the raw buffer.
    FastBuffer cdrBuffer(buffer, 500);
    /// Object that will serialize.
    Cdr cdr(cdrBuffer);

    uint16_t ushort = 211;                  ///用于序列化的变量
    uint16_t ushort_out = 3;                ///接受反序列化的变量
    uint32_t tst_list[3] = {1, 2, 3};       ///序列化的数组
    uint32_t tst_list_out[3] = {4, 5, 6};   ///接受反序列化的数组

    My_stack sta;
    sta.push(9);
    sta.push(8);                            ///序列化的栈
    My_stack sta_out;                       ///接受反序列化的栈

    ///序列化
    cdr << ushort;                          ///序列化ushort
    cdr.serializeArray(tst_list, 3);        ///序列化数组
    my_serialize(cdr, sta);                 ///序列化栈

    Cdr cdr_out(cdrBuffer);

    ///反序列化
    cdr_out >> ushort_out;
    cdr_out.deserializeArray(tst_list_out, 3);
    my_deserialize(cdr_out, sta_out);


    ///打印结果
    cout << "hello world" << endl;
    cout << ushort_out << endl;
    for (int i = 0; i < 3; i++) printf("%d ", tst_list_out[i]); printf("\n");
    cout << sta_out.pop() << endl;
    cout << sta_out.pop() << endl;
    int p;
    cin >> p;
    return 0;
}

void my_serialize(Cdr &cdr, My_stack &sta)
{
    cdr << sta.get_cur();
    cdr.serializeArray(sta.get_buffer(), 14);
}

void my_deserialize(Cdr &cdr, My_stack &sta)
{
    int32_t temp_cur;
    cdr >> temp_cur;
    sta.set_cur(temp_cur);
    cdr.deserializeArray(sta.get_buffer(), 14);
}
