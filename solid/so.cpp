#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//// ===================== DOMAIN LAYER =====================

class Product
{
public:
    int price;

    Product(int price)
    {
        this->price = price;
    }
};

class Order
{
private:
    vector<Product> products;

public:
    void addProduct(const Product &product)
    {
        products.push_back(product);
    }

    int calculateTotal() const
    {
        int total = 0;
        for (const auto &p : products)
            total += p.price;
        return total;
    }
};

//// ===================== STRATEGY (OCP) =====================

class DiscountStrategy
{
public:
    virtual int apply(int amount) const = 0;
    virtual ~DiscountStrategy() = default;
};

class NoDiscount : public DiscountStrategy
{
public:
    int apply(int amount) const override
    {
        return amount;
    }
};

class LocalDiscount : public DiscountStrategy
{
public:
    int apply(int amount) const override
    {
        return amount - 5;
    }
};

class PremiumDiscount : public DiscountStrategy
{
public:
    int apply(int amount) const override
    {
        return amount - 10;
    }
};

class FestivalDiscount : public DiscountStrategy
{
public:
    int apply(int amount) const override
    {
        return amount - 25;
    }
};

//// ===================== REPOSITORY (SRP) =====================

class IOrderRepository
{
public:
    virtual void save(const Order &order) const = 0;
    virtual ~IOrderRepository() = default;
};

class OrderRepository : public IOrderRepository
{
public:
    void save(const Order &order) const override
    {
        cout << "Order saved to database\n";
    }
};

//// ===================== NOTIFICATION (SRP) =====================

class INotificationService
{
public:
    virtual void sendOrderPlaced() const = 0;
    virtual ~INotificationService() = default;
};

class EmailNotificationService : public INotificationService
{
public:
    void sendOrderPlaced() const override
    {
        cout << "Email notification sent\n";
    }
};

//// ===================== APPLICATION LAYER =====================

class OrderService
{
private:
    const IOrderRepository &repository;
    const INotificationService &notifier;

public:
    OrderService(const IOrderRepository &repo,
                 const INotificationService &notifier)
        : repository(repo), notifier(notifier) {}

    void placeOrder(Order &order, const DiscountStrategy &discount) const
    {

        int total = order.calculateTotal();

        int finalAmount = discount.apply(total);

        cout << "Total amount: " << total << endl;
        cout << "Final amount after discount: " << finalAmount << endl;

        repository.save(order);
        notifier.sendOrderPlaced();
    }
};

//// ===================== MAIN (COMPOSITION ROOT) =====================

int main()
{

    /// Create order
    Order order;
    order.addProduct(Product(100));
    order.addProduct(Product(200));
    order.addProduct(Product(300));

    /// Choose discount strategy (OCP in action)
    PremiumDiscount discount;

    /// Infrastructure
    OrderRepository repo;
    EmailNotificationService notifier;

    /// Application service (Dependency Injection)
    OrderService service(repo, notifier);

    /// Execute use case
    service.placeOrder(order, discount);

    return 0;
}