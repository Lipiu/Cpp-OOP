# Teorie

## Key differences between Early binding and Late binding
| Aspect               | Early binding     | Late binding                             |
| -------------------  | ------------      | ---------------------------------------- |
| Timing               | Compile time | Run time |
| Overhead             | Zero(direct calls or inline) | Slight(pointer dereference via vtable) |
| Flexibility          | Limited to the static type | Supports polymorphism and true dynamic dispatch   |
| Syntax               | Non-virtual member functions, templates | Functions declared `virtual` in `base class`               |

**Early binding:**
* **When it happens:** `compile time`
* **Also called:** `static binding or compile-time binding`
* **How C++ does it:**
    * Non-virtual member functions
    * Free (non-member) functions
    * Function overloading and template instantiation
    * Inline functions
* **Mechanism:**
    * The compiler knows exactly which function to call based on the static type of the expression, and it emits a direct call instruction (or inlines the code) into the object file.
##
**EXAMPLE Early Binding:**\
#include <iostream>\
struct Base {\
    void foo() { std::cout << "Base::foo\n"; }\
};

int main() {\
    Base b;\
    b.foo();  // early binding: compiler generates a direct call to Base::foo\
    return 0;\
}

##

**Late (dynamic) binding:**
* **When it happens:** `at run-time`
* **Also called:** `dynamic binding`, `run-time binding`
* **How C++ does it:** `virtual functions`
* **Mechanism:**
    * When you declare a function virtual in a base class, C++ creates a vtable (virtual-function table) for each polymorphic class. Objects carry a pointer to their class’s vtable. At run time, a call through a base-class pointer/reference looks up the correct function in the vtable of the actual (derived) object.
##
**EXAMPLE Late Binding:**\
#include <iostream>\
struct Base {\
    virtual void foo() { std::cout << "Base::foo\n"; }\
};\

struct Derived : Base {\
    void foo() override { std::cout << "Derived::foo\n"; }\
};\

int main() {\
    Base* p = new Derived;\
    p->foo();  // late binding: calls Derived::foo via vtable dispatch\
    delete p;\
    return 0;\
}

Here, p->foo() isn't fixed at compile time, at run time the vtable is consulted and Derived::foo() is invoked.

