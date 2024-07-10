# Contents
- [Contents](#contents)
- [Journal](#journal)
  - [Project Setup](#project-setup)
  - [Simple tests](#simple-tests)
  - [Added a README](#added-a-readme)
  - [Storing multiple orders](#storing-multiple-orders)
  - [A better `OrderList`](#a-better-orderlist)
  - [Documentation](#documentation)
  - [Exporting `OrderList`s to a file (and import, too)](#exporting-orderlists-to-a-file-and-import-too)
  - [Better export](#better-export)
  - [`MenuItem`s](#menuitems)
  - [`Order`s can calculate their own price](#orders-can-calculate-their-own-price)
  - [`OrderItem`s](#orderitems)

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

### A better `OrderList`
Rather than store the orders in a [std::vector](https://en.cppreference.com/w/cpp/container/vector), I realised it would be beneficial to use a [std::list](https://en.cppreference.com/w/cpp/container/list) instead. This is because we will be adding and removing orders frequently, and a `std::list` is much better at this than a `std::vector`. It doesn't hinder us much, since we don't need random access anyway.

Along with this, I added a `find` method to the `OrderList` class, which will return an iterator to the first order which contains the keyword in the description. This is useful for searching for orders by name, for example. These features are tested in two new files: [tests/test_order_list_erase.cpp](tests/test_order_list_erase.cpp) and [tests/test_order_list_find.cpp](tests/test_order_list_find.cpp).

In order to test these, I also added a new `ASSERT_THROWS` macro, used like so:
```cpp
// tests/test_order_list_erase.cpp
void doesnt_exist() {
  OrderList list{};
  list.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
  list.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));
  ASSERT_THROWS(list.erase(list.find("Bob")), std::invalid_argument);
}
```

### Documentation
I added documentation to the [Order](src/order.h) and [OrderList](src/order_list.h) classes, using [Doxygen](https://www.doxygen.nl/index.html)-style comments. This allows my IDE to show me the documentation when I hover over a class or method, and will also allow me to generate documentation if I want to later on.
```cpp
/**
* @brief Find the first order that matches a given keyphrase.
*
* This method searches the descriptions of the orders for the given keyphrase
* and returns an iterator to the first matching order.
*
* @param keyphrase The keyphrase to search for.
* @return std::list<Order>::iterator An iterator to the found order, or end() if not found.
*/
std::list<Order>::iterator find(const std::string& keyphrase);
```

### Exporting `OrderList`s to a file (and import, too)
In a real restaurant, we're going to want to have multiple people with access to the same list of orders, and also we'll be opening and closing sessions all the time.

I added the functionality to export an `OrderList` to a file, and also to import/read from a file. This is done in a very simple way for now, simply treating each order as a separate line, in a .txt file. Of course, this comes with its own tests in [tests/test_import_export_orders.cpp](tests/test_import_export_orders.cpp).

Here's what a sample exported order looks like:
```text
One pepperoni pizza for Mike, delivered to 1 Elm Ave.
Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.
```

### Better export
I realised that the previous export method was not very good, since it would not work if the description of an order contained a newline character. I changed the export to escape newline characters as `\n`, and also to escape backslashes as `\\`. Now orders with multiline descriptions can be exported and imported correctly:
```text
One peppero\\ni pizza for Mike,\ndelivered to \\1 Elm Ave.\\"\\
Two pepperoni \n\npizzas for "Alice", delivered to 3 Arch Ave.
```

### `MenuItem`s
I added a `MenuItem` class, which is a simple class that holds a name and a price. Orders now contain a list of `MenuItem`s, in addition to a description, such as "For Mike" (although I will remove the description later).

### `Order`s can calculate their own price
Finally, `Order` has the functionality to do something that isn't entirely trivial for a regular employee with a notepad: calculate the price of the order. This is done by summing the prices of all the `MenuItem`s in the order. This is tested in [tests/test_order_price.cpp](tests/test_order_price.cpp).

```cpp
double Order::calculateTotalPrice() const {
    double total = 0;
    for (const auto &item : items) {
        total += item.getPrice();
    }
    return total;
}
```

### `OrderItem`s
I realised that `MenuItem`s are not very useful on their own, since they don't have a quantity. Also, maybe a particular item will have extra requests, such as "no olives" or something. I added an `OrderItem` class, which is a `MenuItem` with a quantity (and in future will also hold special notes / requirements). This is a pretty big non-backwards-compatible change and required rewriting all my tests to support this new structure.

```cpp
void TEST_higher_quantity() {
    Order order("For Mike");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);

    order.addItem(OrderItem(pepperoni, 2));
    order.addItem(OrderItem(margherita, 1));

    ASSERT(order.calculateTotalPrice() == 29.0);
}
```