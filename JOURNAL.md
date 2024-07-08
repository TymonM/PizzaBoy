# Contents
- [Contents](#contents)
- [Journal](#journal)
  - [Project Setup](#project-setup)
  - [Simple tests](#simple-tests)
  - [Added a README](#added-a-readme)
  - [Storing multiple orders](#storing-multiple-orders)

# Journal
### Project Setup
I set up a git repository, and initialised a new [CMake](https://cmake.org) project. I made two directories `src` and `tests`.

In the `src` directory, we will have all our files, from classes to `main.cpp` itself. The `tests` directory will contain unit tests for our classes, and will be run with [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html).

### Simple tests
I ignore compiled CMake build files in the [.gitignore](.gitignore) file, since these are OS-specific.

I then set up an *extremely* simple `Order` class, which literally just holds a description, and set up a super simple test in [tests/test_new_order.cpp](tests/test_new_order.cpp). In order to do this, I also set up some simple macros which will be useful for testing later on. These can be found at [tests/macros.cpp](tests/macros.cpp).

```cpp
// tests/test_new_order.cpp
Order order("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
ASSERT_EQUAL_STR(order.getDescription(), "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
return 0;
```

For now, [src/main.cpp](src/main.cpp) is just a 'hello world' program, since I was focusing on setting up the tests first.

### Added a README
Added a [README.md](README.md) file, which contains a brief overview of the project, and instructions on how to build and run the project. I also added a [task.pdf](task.pdf) file, which contains the task requirements for the project.

### Storing multiple orders
Having a single order is great, but we need to be able to store multiple orders. I added a `OrderList` class, which is a simple wrapper around a `std::vector<Order>`. For now, it does nothing fancy. I also added a test for this class, which is in [tests/test_new_order.cpp](tests/test_new_order.cpp):
```cpp
// tests/test_new_order.cpp
void create_order_list() {
  OrderList list{};
  ASSERT(list.size() == 0);
  Order order1("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
  Order order2("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");
  
  list.pushOrder(order1);
  list.pushOrder(order2);
  ASSERT(list.size() == 2);
  ASSERT(list.getOrder(0).getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
  ASSERT(list.getOrder(1).getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");
  list.erase(0);
  ASSERT(list.size() == 1);
  ASSERT(list.getOrder(0).getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");
}
```
Note that I also created a new and improved `ASSERT` macro, with much better fail messages. This is in [tests/macros.cpp](tests/macros.cpp).