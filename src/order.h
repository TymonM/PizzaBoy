#ifndef DTS_91896_ORDER_H
#define DTS_91896_ORDER_H

#include <string>

class Order {
private:
    std::string description;
public:
   Order(const std::string &description);

    const std::string &getDescription() const;
};


#endif //DTS_91896_ORDER_H
