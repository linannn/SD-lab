class My_stack
{
    public:
        My_stack();
        int pop();
        void push(int x);
        inline int get_cur() {return cur;}
        inline void set_cur(int x) {cur = x;}
        inline int* get_buffer() {return buffer;}
    private:
        int buffer[14];
        int cur;
};
