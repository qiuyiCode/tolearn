from operator import getitem
from math import gcd
import cmath
def sum_digits(n):
  if n < 10:
    return n
  else:
    all_but_last,last = n // 10,n % 10
    return sum_digits(all_but_last) + last

def fac(x):
  total,k = 1,1
  while(k <= x):
    total,k = total * k,k+1
  return total
  
print(fac(5))

def fac_re(n):
  if n == 1 or n == 0:
    return 1
  else:
    return fac_re(n-1) * n

print(fac_re(0))


# Mutual recursion
def is_even(n):
  if n == 0:
    return True
  else:
    return is_odd(n-1)

def is_odd(n):
  if n == 0:
    return True
  else:
    return is_even(n-1)

print(is_even(4))

def cascade(n):
  print(n)

  if n >= 10:
    print


cascade(2013)

print(8 // 2)


def crust():
   print("70km")
   def mantle():
       print("2900km")
       def core():
           print("5300km")
           return mantle()
       return core
   return mantle
drill = crust
drill = drill()
drill = drill()
drill = drill()
drill()

# 查看数字中是否包含8
def num_eights(x):
    if x == 0:
      return 0
    elif x % 10 == 8:
      return 1 + num_eights(x // 10)
    else:
      return num_eights(x // 10)

def Ping_pong(n):
  count = 0
  flag = True
  for i in range(1,n+1):
    if num_eights(i) == 0 and i % 8 != 0:
      if flag == True:
        count = count + 1
      else:
        count = count - 1
    else:
      if flag == True:
        count = count + 1
      else:
        count = count - 1
      flag = not flag
  return count

print(Ping_pong(21))


def both_paths(sofar="S"):
    def up():
      return both_paths(sofar + 'U')

    def down():
      return both_paths(sofar + 'D')
    
    return up,down

up,down = both_paths()

def g_iter(n):
    li = []
    li.append(0)
    for i in range(1,n+1):
      if i <= 3:
        li.append(i)
      else:
        li.append(li[i-1] + 2*li[i-2] + 3*li[i-3])
    return li[n]
print(g_iter(4))

# print(type(2*3))
# print(type(3+2j))
# print(7 / 3 * 3)
# print(1 / 3 * 7 * 3)

print()

def count_partitions(n,m):
  if n == 0:
    return 1
  elif n < 0:
    return 0
  elif m == 0:
    return 0
  else:
    return count_partitions(n-m, m) + count_partitions(n, m-1)

print(count_partitions(6, 4))

def find_x(x):
  if x == 1:
    return 0
  for i in range(1,x):
    if 2 ** i > x:
      return i-1
print(find_x(1))

x = int(2)
print(x ** 2)

print(1 << 4)

def print_goto(start,dest):
  print('{} --> {}'.format(start,dest))

def hanoi(n,one,two,three):
  if n == 1:
    print_goto(one, three)
  else:
    hanoi(n-1, one, three, two)
    print_goto(one, three)
    hanoi(n-1, two, one, three)

hanoi(3, 'A', 'B', 'C')

# rational(n,d) 实现将分子n和分母d组合成一个分数
# numer(x) 返回一个有理数x的分子
# denom(x) 返回一个有理数x的分母
def add_rationals(x,y):
  nx,dx = numer(x),denom(x)
  ny,dy = numer(y),denom(y)
  return rational(nx * dy + ny * dx,dx * dy)

def mul_rationals(x,y):
  nx,dx = numer(x),denom(x)
  ny,dy = numer(y),denom(y)
  return rational(nx*ny,dx*dy)

def print_rational(x):
  print(numer(x),'/',denom(x))

def rational_are_equal(x,y):
  return numer(x) * denom(y) == numer(y) * denom(x)

def rational(n,d):
  g = gcd(n,d)
  return [n // g,d // g]

def numer(x):
  return x[0]

def denom(x):
  return x[1]

half = rational(1, 2)
third = rational(1, 3)
print_rational(half)
print_rational(third)
print_rational(mul_rationals(half,third))
print_rational(add_rationals(third,third))

print()

digits = [1,6,2,6]
print(len(digits))
print(digits[3])