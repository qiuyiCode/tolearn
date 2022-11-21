from math import sqrt

def square(x):
  return x * x

print('square(3) = ',square(3))

def sum_naturals(n):
  sum = 0
  for k in range(1,n+1):
    sum += k
  return sum

print('sum_naturals(100) = ',sum_naturals(100))

def sum_cubes(n):
  sum = 0
  for k in range(1,n+1):
    sum += k * k * k
  return sum

print('sum_cubes(100) = ',sum_cubes(100))

def sum_pi(n):
  sum = 0
  for k in range(1,n+1):
    sum += 8 / ((4*k-3) * (4*k-1))
  return sum

print('sum_pi(100) = ',sum_pi(100))

def summation(n,term):
  sum = 0
  for k in range(1,n+1):
    sum += term(k)
  return sum

def indentity(k):
  return k

def cube(k):
  return k * k * k

def pi(k):
  return 8 / ((4*k-3) * (4*k-1))

print('summation(100,indentity) = ',summation(100,indentity))
print('summation(3,cube) = ',summation(3,cube))
print('summation(100,pi) = ',summation(100,pi))

def sum_naturals2(n):
  return summation(n,indentity)

print('sum_naturals2(100) = ',sum_naturals2(100))


def improve(update,close,guess=1):
  while not close(guess):
    guess = update(guess)
  return guess

def golden_update(guess):
  return 1 / guess + 1

def approx_eq(x,y,tolerance = 1e-16):
  return abs(x-y) <= tolerance

def square_close_successor(guess):
  return approx_eq(guess * guess,guess + 1)

print('golden_radio:',improve(golden_update,square_close_successor))

phi = 1/2 + sqrt(5) / 2

def improve_test():
  approx_phi = improve(golden_update,square_close_successor)
  assert approx_eq(phi,approx_phi),'phi differs from its approximation'
  
improve_test()


def average(x,y):
  return (x + y) / 2

def sqrt(a):
  # 函数内定义函数
  
  # 1.优化函数
  def sqrt_update(x):
    return average(x,a / x)
  
  # 2.判断是否找到了对应的值
  def sqrt_close(x):
    return approx_eq(x * x,a)

  return improve(sqrt_update,sqrt_close)

print('sqrt(1600) = ',sqrt(1600))


def compose1(f,g):
  def h(x):
    return f(g(x))
  return h

def successor(x):
  return x + 1

def f(x):
  return -x

square_successor = compose1(square,successor)
print('square_successor(5) = ',square_successor(5))

abs_successor = compose1(abs,f)
print('abs_successor(12) = ',abs_successor(12))

def newton_update(f,df):
  def update(x):
    return x - f(x) / df(x)
  return update

def find_zero(f,df):
  def near_zero(x):
    return approx_eq(f(x),0)
  return improve(newton_update(f,df),near_zero)

def square_root_newton(a):
  def f(x):
    return x * x - a
  def df(x):
    return 2 * x
  return find_zero(f,df)

print('square_root_newton(16) = ',square_root_newton(16))

def power(x,n):
  product,k = 1,1
  while(k <= n):
    product,k = product * x,k + 1
  return product

def nth_root_of_a(n,a):
  def f(x):
    return power(x,n) - a
  def df(x):
    return n * power(x,n-1)
  return find_zero(f,df)

print('nth_root_of_a(2,64) = ',nth_root_of_a(2,64))

def triple(x):
  return x * 3

def comboine(f,g):
  def h(x):
    return f(g(x))
  return h

def minus(x):
  return -x

f1 = comboine(triple,minus)

print('comboine(triple,minus) = ',f1(3))

def make_adder(n):
  def adder(k):
    return k + n
  return adder

f1 = make_adder(3)

print('make_adder(3)(8) = ',f1(8))


def curry(f):
  def g(x):
    def h(y):
      return f(x,y)
    return h
  return g

f = lambda n : lambda k : k + n


def count_factors(n):
  i,count = 1,0
  while i <= n:
    if n % i == 0:
      count += 1
    i += 1
  return count

def count_primes(n):
  i,count = 1,0
  while i <= n:
    if is_prime(i):
      count += 1
    i += 1
  return count

def is_prime(n):
  return count_factors(n) == 2

print('count_factors(15) = ',count_factors(15))

def count_cond(condition):
  def pd_panduan(n):
      i,count = 1,0
      while(i <= n):
        if condition(n,i) is True:
          count += 1
        i += 1
      return count
  return pd_panduan

f = count_cond(lambda n,i:n % i == 0)
print(f(6))


def zero(f):
    return lambda x: x

def successor(n):
    return lambda f: lambda x: f(n(f)(x))
  
def f(x):
  return x ** 3, x ** 4
  
x,y = f(6)
print(x,y)

