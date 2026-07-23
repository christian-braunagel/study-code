class Shape
{
public:
    // should be a virtual method because
    // it should be overridden by derived classes of Shape
    // and called via pointers of the base class
    virtual double area() const { return 0.0; }
    // every polymorphic class that is used and deleted via base class pointer
    // needs a virtual destructor to ensure the
    // correct deletion of the derived classes
    virtual ~Shape() {};
};