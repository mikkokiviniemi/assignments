

#include <vector>

// Not too rare case, when we have a C library

// Don't worry too much about the code in the extern C block,
// it's basically C code forged so it gets through the compiler
// without errors.
extern "C" {
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <assert.h>

    // Usually C libraries define some structs
    struct some_c_library
    {
        int random;
        char values;
        void* in;
        long a;
        short type;
    };

    // and give you functions to initialise
    some_c_library* some_c_new() {
        some_c_library* ptr = (some_c_library*)malloc(sizeof(some_c_library));
        assert(ptr != nullptr);
        // init the values so we don't read uninitialised memory and get
        // confused about that
        ptr->random = 53;
        ptr->values = 2;
        ptr->in = nullptr;
        ptr->a = 0xdeadbeefcafe;
        ptr->type = 0;
        return ptr;
    }

    // and destroy (free resources)
    void some_c_free(some_c_library* ptr) {
        free(ptr);
    }

    void do_stuff_after_init(some_c_library* ptr) {
        printf("%p:%d%ld%p\n", ptr, ptr->random, ptr->a, ptr->in);
    }
}

// and we want to wrap it into RAII-enabled type.  If you
// use libraries such as FreeType, SDL or GLFW, or many others
// this is a good practice.
class cpp_wrapper
{
    public:
        cpp_wrapper();
        ~cpp_wrapper();

        void do_stuff();
        some_c_library& values() { return *library; }

    private:
        some_c_library* library;
};

cpp_wrapper::cpp_wrapper() {
    library = some_c_new();
}

cpp_wrapper::~cpp_wrapper() {
    some_c_free(library);
}

void cpp_wrapper::do_stuff() {
    do_stuff_after_init(library);
}

// Common thing, create a thing, set it to certain non-default initial values.
cpp_wrapper build_wrapper() {
    cpp_wrapper rval;
    rval.values().random = 42;

    // move to avoid copy (if compiler doesn't handle guaranteed copy elision)
    return std::move(rval);
}

int main() {
    // we could use the C library like this, but it's usually a bad idea
    // (bug-prone), so we want to do the wrapping to handle some of the
    // busywork for us. (And have RAII so we don't forget to clean up
    // after ourselves)
    some_c_library* lib = some_c_new();
    do_stuff_after_init(lib);
    some_c_free(lib);

    // with C++ we would use it like (so we trade initial wrapping work to
    // ease of use later on)
    cpp_wrapper wrapped;
    wrapped.do_stuff();

    // But our wrapper might still be a bit under construction...
    auto wrapped2 = build_wrapper();

    wrapped2.do_stuff();
}

