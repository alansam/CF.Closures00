//
//  closures00.cpp
//  CF.Closures00
//
//  Created by Alan Sampson on 1/7/21.
//
//  MARK: - Reference.
//  @see: https://leimao.github.io/blog/CPP-Closure/
//

#include <iostream>
#include <iomanip>
#include <functional>
#include <cmath>

void fitTheFirst(void);
void fitTheSecond(void);

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "CF.Closures00" << std::endl;
  std::cout << "C++ " << __cplusplus << std::endl;

  fitTheFirst();
  fitTheSecond();
  
  return 0;
}

/// MARK: closureWrapper1()
std::function<void(void)> closureWrapper1() {
  int x = 10;
  return [x](){
    std::cout << "Value in the closure " << x << std::endl;
  };
}

/// MARK: closureWrapper2()
std::function<void(void)> closureWrapper2() {
  int x = 10;
  return [&x](){
    x += 1;
    std::cout << "Value in the closure " << x << std::endl;
  };
}

/*
 * MARK: fitTheFirst()
 */
void fitTheFirst(void) {

  int x = 10;

  auto func0 = [&x](){
    x += 1;
    std::cout << "Value in the closure: " << x << std::endl;
  };

  std::function<void(void)> func1 = closureWrapper1();
  std::function<void(void)> func2 = closureWrapper2();

  std::cout << "-------------------------" << std::endl;
  func0();
  func0();
  func0();

  std::cout << "-------------------------" << std::endl;
  func1();
  func1();
  func1();

  std::cout << "-------------------------" << std::endl;
  func2();
  func2();
  func2();

  std::cout << std::endl;
}

//  MARK: - Constant definition.
double constexpr pi = M_PI;

/*
 *  MARK: Class CircleArea
 */
class CircleArea {
public:
  CircleArea() {
  }

  double operator ()(double r) const {
    return pi * r * r;
  }
};

/*
 *  MARK: fitTheSecond()
 */
void fitTheSecond(void) {
  double r = 1.0;
  CircleArea circleArea;
  double area = circleArea(r);

  std::cout << "radius " << r << " area " << area << std::endl;

  std::cout << std::endl;
}
