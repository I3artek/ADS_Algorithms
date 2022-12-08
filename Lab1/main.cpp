#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack s;
    s.Put(4);
    s.Put(5);
    s.Put(6);
    s.Put(7);

    while (!s.Empty()) {
        cout << s.Get() << endl;
    }

    return 0;
}