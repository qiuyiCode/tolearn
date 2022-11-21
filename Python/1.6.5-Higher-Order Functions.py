def improve(update,close,guess = 1):
  while not close(guess):
    guess = update(guess)
  return guess

# 判断是否符合找到的条件
def approx_eq(x,y,tolerance = 1e-16):
  return abs(x-y) <= tolerance 

# 牛顿迭代法,用来寻找函数零点
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

def power(x,n):
  product,k = 1,1
  for i in range(1,n+1):
    product,k = x*product,k+1
  return product

# 将函数形式用程序语言表达出来,然后用牛顿法进行求解
def nth_root_of_a(n,a):
  def f(x):
    return power(x,n) - a
  def dfx(x):
    return n * power(x,n-1)
  return find_zero(f,dfx)

print(square_root_newton(64))

print(nth_root_of_a(2,64))

print(nth_root_of_a(3,64))

print(nth_root_of_a(6,64))